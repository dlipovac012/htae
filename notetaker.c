/*
 * =====================================================================================
 *
 *       Filename:  notetaker.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/23/2020 05:54:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dalibor Lipovac (dl), dlipovac012@gmail.com
 *        Company:  raptr.dev
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

void usage(char *, char *);
void fatal(char *);
void *error_checking_malloc(unsigned);

int main(int argc, char **argv)
{
	int userid, fd;
	char *buffer, *datafile;

	buffer = (char *) error_checking_malloc(100);
	datafile = (char *) error_checking_malloc(20);
	strcpy(datafile, "/var/notes");

	if (argc < 2)
		usage(argv[0], datafile);

	strcpy(buffer, argv[1]);

	printf("[DEBUG] buffer		@ %p: \'%s\'\n", buffer, buffer);
	printf("[DEBUG] datafile@	@ %p: \'%s\'\n", datafile, datafile);

	fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND);
	if (fd == -1)
		fatal("in main() while opening file");
	printf("[DEBUG] file descriptor is %d\n", fd);

	userid = getuid();

	if (write(fd, &userid, 4) == -1)
		fatal("in main() while writing userid to file");
	write(fd, "\n", 1);

	if (write(fd, &buffer, strlen(buffer)) == -1)
		fatal("in main() while writing buffer to file");
	write(fd, "\n", 1);

	if (close(fd) == -1)
		fatal("in main() while closing a file");

	printf("A note has been saved.");
	free(buffer);
	free(datafile);	

	return 0;
}

void usage(char *prog_name, char *filename)
{
	printf("Usage: %s <data to add to %s>\n", prog_name, filename);
}
