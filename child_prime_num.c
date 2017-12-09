/*

Parent sends N strings to child and child returns the prime and displays 

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main(){ 
int pid,a,n,p[2],p2[2],i,j,buffr1[100],buffr2[100],flag,n2=0; 
a = pipe(p);
   if(a == -1) 
   { 
       fprintf(stderr, "Pipe Failed.\n"); 
       return EXIT_FAILURE; 
    } 
   a=pipe(p2);
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
           
       case 0: n=read(p[0],buffr2,sizeof(buffr2));
         	printf("In child process (ID: %d)\n", pid);
         	n=n/sizeof(int);
         	for(i=0;i<n;i++){
            	flag=0;
            	if(buffr2[i]<=1)
               	flag=1;
            	for(j=2;j<=buffr2[i]/2;j++){
               	if((buffr2[i]%j)==0)
               	{
                  	flag=1;	
                  	break;	
               	}
            	}
            	if(flag==0){
               	buffr1[n2]=buffr2[i];
               	n2++;
            	}
         	}
         	write(p2[1],buffr1,n2*sizeof(int));
         	exit(1);
         	break;

       default: printf("In parent process (ID: %d)\n", pid);
         	printf("Enter the limit:- ");
         	scanf("%d",&n);
         	for(i=0;i<n;i++){
            	printf("Enter the element %d:- ",i+1);
            	scanf("%d",&buffr1[i]);
         	}
         	write(p[1],buffr1,n*sizeof(int));
         	waitpid(pid,NULL,0);
         	printf("In parent process (ID: %d)\n", pid);
         	n2=read(p2[0],buffr2,sizeof(buffr2));
         	n2=n2/sizeof(int);
         	for(i=0;i<n2;i++)
            	printf("Prime Number %d:- %d\n",i+1,buffr2[i]);
         	break;
       } 
      close(p[0]);
       close(p[1]);
      return 0; 
}