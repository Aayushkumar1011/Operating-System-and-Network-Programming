/*

Parent process read 2 filenames and compare the sizes returned by child processes
:reading of sizes are done parallelly by two child process

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/stat.h>
int main(){ 
   int pid1,pid2,p1[2],p2[2],p3[2],p4[2],i,j,buffr3[2],buffr4[2],flag,n2=0; 
   char buffr1[2][30],buffr2[2][30];
   struct stat filestat;
   pipe(p1);
   pipe(p2);
   pipe(p3);
   pipe(p4);
   pid1 = fork(); 
   switch(pid1){ 
     case -1:perror("main: fork"); 
     exit(1); 
     case 0: read(p1[0],buffr1,sizeof(buffr1));
     printf("In child process (ID: %d)\n", getpid());
     stat(buffr1[0],&filestat);
     buffr3[0]=filestat.st_size;
     write(p3[1],buffr3,sizeof(buffr3));
     exit(1);
     break;
     default: 
     pid2 = fork(); 
     switch(pid2){ 
       case -1:perror("main: fork"); 
       exit(1); 
       case 0: read(p2[0],buffr1,sizeof(buffr1));
       printf("In child process (ID: %d)\n", getpid());
       stat(buffr1[0],&filestat);
      buffr3[0]=filestat.st_size;
      write(p4[1],buffr3,sizeof(buffr3));
      exit(1);
      break;
      default:
       printf("In parent process (ID: %d)\n", getpid());
       printf("\nEnter the files \n");
       gets(buffr1[0]);
      gets(buffr2[0]);
      write(p1[1],buffr1,sizeof(buffr1));
      write(p2[1],buffr2,sizeof(buffr2));
      waitpid(pid1,NULL,0);
      waitpid(pid2,NULL,0);
      read(p3[0],buffr3,sizeof(buffr3));
      read(p4[0],buffr4,sizeof(buffr3));
      if(buffr3[0]>buffr4[0])
        printf("\n%s is larger than %s\n",buffr1[0],buffr2[0]);
       else
         printf("\n%s is larger than %s\n",buffr2[0],buffr1[0]); 
       break;
       }
     } 

   return 0; 
}