/*

Read a filename and display its attributes such as Owner, Size, Permission using system calls

*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>
#include <sys/types.h>

int main()
{
	int s;
	struct  stat filestat;
	char src[100];
	printf("\n Enter file name: " );
	scanf("%s", src);

	s= stat(src, &filestat);
	if(s!=-1)
	{
		printf("\n Owner ID: %d", filestat.st_uid);
		printf("\n Size of file is: %d bytes", filestat.st_size);
		printf("\n Permission read/write: %o", filestat.st_mode);
		printf("\n Creation time: %s", ctime(&filestat.st_ctime));
		printf("\n Modification time: %s", ctime(&filestat.st_mtime));

	}
	else 
		printf("ERROR\n");
	return 0;
}