/*

Producer-consumer problem

*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#define EMPTY 0
#define FULL 1
#define MUTEX 2
#define SIZE 10
void up(int sem_id,int sem_num,struct sembuf *semaphore){
  semaphore->sem_num=sem_num;
   semaphore->sem_op=1;
   semaphore->sem_flg=0;
   semop(sem_id,semaphore,1);
}
void down(int sem_id,int sem_num,struct sembuf *semaphore){
   semaphore->sem_num=sem_num;
   semaphore->sem_op=-1;
   semaphore->sem_flg=0;
   semop(sem_id,semaphore,1);
}
void initsem(int sem_id,int sem_num,int val){
   union semnum{
      int val;
      struct semid_ds *buf;
      unsigned short *array;
   }argument;
   argument.val=val;
  semctl(sem_id,sem_num,SETVAL,argument);
}
int main(){
   key_t shm_key=1234,sem_key=3456;
   int shm_id,sem_id;
   int *shm;
   struct sembuf semaphore;
   shm_id=shmget(shm_key,SIZE+1,IPC_CREAT|0666);
   sem_id=semget(sem_key,3,IPC_CREAT|0666);
   shm=shmat(shm_id,NULL,0);
  shm[0]=0;
  initsem(sem_id,EMPTY,SIZE);
   initsem(sem_id,FULL,0);
  initsem(sem_id,MUTEX,1);
   if(fork()==0){
      while(1){
         int item,i;
         sleep(2);
         down(sem_id,FULL,&semaphore);
         down(sem_id,MUTEX,&semaphore);
         item=shm[1];
         for(i=1;i<shm[0];i++)
           shm[i]=shm[i+1];
         shm[0]--;
         printf("\nConsumed %d",item);
         up(sem_id,MUTEX,&semaphore);
         up(sem_id,EMPTY,&semaphore); 
      }
  }
  else{
      while(1){
         int item=random()%10;
         sleep(1);
         down(sem_id,EMPTY,&semaphore);
         down(sem_id,MUTEX,&semaphore);
         shm[++shm[0]]=item;
         printf("\nProduced %d",item);
         up(sem_id,MUTEX,&semaphore);
         up(sem_id,FULL,&semaphore); 
      }
   }
}