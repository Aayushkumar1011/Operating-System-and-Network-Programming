/*

Simulate UNIX WC command to find no. of characters, words and lines in a file 

*/
#include <unistd.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
   int fd,count=0,len,wCount=0,lCount=0,f=0;
   char buffer,flag='y';
   fd = open(argv[1],O_RDWR);
   if(fd!=-1){
     len=lseek(fd,0L,2);
     while(lseek(fd,count,0)<len){
       count++;
       read(fd,&buffer,sizeof(char));
       if((char)buffer==' ' || (char)buffer=='\t') 
         f=0;
       else if((char)buffer=='\n'){
         lCount++;
         f=0;
       }
       else if(f==0){
         f=1;
         wCount++;
       }
     }
     printf("No of Lines= %d",lCount);
     printf("\nNo of Words= %d",wCount);
     printf("\nNo of Characters= %d\n",len); 
   }
   else
     printf("\nFile not found\n");
   close(fd);
   return 0;
}