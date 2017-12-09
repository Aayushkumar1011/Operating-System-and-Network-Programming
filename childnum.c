/*

Send N numbers from parent to child process and child will display the numbers

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
int main(){ 
    int pid,a,n,p[2],i,buffr1[100],buffr2[100]; 
    a = pipe(p);
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
         	for(i=0;i<n;i++)
            	printf("Number sent by parent process %d:- %d\n",i+1,buffr2[i]);
         	exit(1);
         	break;
          
       default: printf("In parent process (ID: %d)\n", pid);
         	printf("Enter number of no's:- ");
         	scanf("%d",&n);
         	for(i=0;i<n;i++){
            	printf("Enter the element %d:- ",i+1);
            	scanf("%d",&buffr1[i]);
         	}
         	write(p[1],buffr1,n*sizeof(int));
         	waitpid(pid,NULL,0);
         	break;
   } 
   close(p[0]);
    close(p[1]);
    return 0; 
}