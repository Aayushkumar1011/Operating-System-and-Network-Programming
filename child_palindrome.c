/*

Parent send N strings to child and child return the palindromes

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>

int main(){ 
  int pid,a,n,p[2],p2[2],i,len,j,k,flag,n2=0;
  char buffr1[100][100],buffr2[100][100],buf[5]; 
  printf("Enter the number of string:- ");
  scanf("%d",&n);
  a = pipe(p);
  if(a == -1) 
  { 
     fprintf(stderr, "Pipe Failed.\n"); 
     return EXIT_FAILURE; 
  } 
  a = pipe(p2);
   if(a == -1) 
   { 
     fprintf(stderr, "Pipe Failed.\n"); 
     return EXIT_FAILURE; 
  } 
   pid = fork(); 
   switch(pid)
   { 
     case -1:perror("main: fork"); 
       exit(1); 
       
     case 0:	read(p[0],buffr2,sizeof(buffr2));
      	printf("In child process (ID: %d)\n", pid);
      	for(i=0;i<n;i++){
        	len=strlen(buffr2[i]);
        	flag=0;
        	for(j=0,k=len-1;j<len;j++,k--){
          	if(buffr2[i][j]!=buffr2[i][k]){
            	flag=1;
            	break;	
          	}
        	}
        	if(flag==0){
          	n2++;
          	strcpy(buffr1[n2],buffr2[i]);
        	}
      	}
      	buffr1[0][0]=n2;
      	write(p2[1],buffr1,sizeof(buffr1));
      	exit(1);
      	break;

     default: printf("In parent process (ID: %d)\n", pid);
      	for(i=0;i<n;i++){
        	printf("Enter the string %d:- ",i+1);
        	scanf("%s",buffr1[i]);
      	}
      	write(p[1],buffr1,sizeof(buffr1));
      	waitpid(pid,NULL,0);
      	read(p2[0],buffr2,sizeof(buffr2));
      	printf("In parent process (ID: %d)\n", pid);
      	n=(int) buffr2[0][0];
      	for(i=1;i<=n;i++)
        	printf("Paliandrome %d:- %s\n",i,buffr2[i]);
      	break;
  } 
   close(p[0]);
   close(p[1]);
   return 0; 
}