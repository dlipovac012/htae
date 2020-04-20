#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void usage(char* program_name, char* filename)
{
	printf("Usage: %s <data to add to %s>\n", program_name, filename);
	exit(0);
}

void fatal(char*);
void *error_checking_malloc(unsigned int);

int main(int argc, char **argv)
{
	int fd; // file descriptor
	char *buffer, *datafile;

	buffer = (char *) error_checking_malloc(100);
	datafile = (char *) error_checking_malloc(20);
	strcpy(datafile, "/tmp/notes");

	if (argc < 2)
		usage(argv[0], datafile);

	strcpy(buffer, argv[1]);
	
	printf("[DEBUG] buffer	 @ %p: \'%s\'\n", buffer, buffer);	
	printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

	strncat(buffer, "\n", 1);

	// opening file
	fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);

	if (fd == -1)
		fatal("in main() while opening file");	
	
	printf("[DEBUG] file descriptor is %d\n", fd);

	// writing data
	if (write(fd, buffer, strlen(buffer)) == -1)
		fatal("In main() while writing buffer to a file");

	// Closing file
	if (close(fd) == -1)
		fatal("In main() while closing a file");

	printf("Note has been saved.\n");
	free(buffer);
	free(datafile);

	return 0;
}

void fatal(char *message)
{
	char error_message[160];

	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 143);
	perror(error_message);
	exit(-1);
}

void *error_checking_malloc(unsigned int size)
{
	void *ptr;
	ptr = malloc(size);

	if (ptr == NULL)
		fatal("In error_checking_malloc() on memory allocation");

	return ptr;
}

