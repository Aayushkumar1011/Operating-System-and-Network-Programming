/*

Read the contents of a file and store it in reverse order using system calls

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int i=0;
	int fileout= open("output.txt", O_WRONLY | O_APPEND);
	int filein= open("input.txt", O_RDONLY);
	int start= lseek(filein, 0, SEEK_CUR);
	int end= lseek(filein, 0, SEEK_END);
	int restart= lseek(filein, 0-end, SEEK_CUR);
	char data[end];
	char revdata[end];
	read(filein, data, end);

	for(i=0; i<end; i++)
	{
		revdata[i]= data[end-(i+1)];
	}
	write(fileout, revdata, end);

	return 0;
}