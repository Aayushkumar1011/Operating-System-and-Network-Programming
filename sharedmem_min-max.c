/*

Parent creates shared memory to store N numbers and child find max and min number

*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h> 

int main()
{
   long shmid;
   key_t key;
   int *shm;
  	int *s,shm_size,n,i,lar,smal;
  	printf("\nEnter the limit :- ");
  	scanf("%d",&n);
  	shm_size=n*sizeof(long);
   key = 110200;
  	if ((shmid = shmget(key, shm_size, IPC_CREAT | 0666)) < 0) {
     perror("shmget");
     exit(1);
   }
  	if ((shm = shmat(shmid, NULL, 0)) == (int *) -1) {
     perror("shmat");
     exit(1);
   }
  	s = shm;
  	for(i=0;i<n;i++,s++)
    	scanf("%d",s);
  	if(fork()==0){
    	s=shm;
    	lar=*s;
    	smal=*s;
    	for(i=1;i<n;i++){
      	if(*(s+i)>lar)
        	lar=*(s+i);
      	else if(*(s+i)<smal)	
        	smal=*(s+i);
    	}
  	}
  	else{
    	wait(NULL);
    	return 0;
  	}
  	printf("\nLargest= %d \nSmallest= %d\n",lar,smal);
  	return 0;
}