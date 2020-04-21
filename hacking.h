/*
 * =====================================================================================
 *
 *       Filename:  hacking.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2020 04:41:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dalibor Lipovac (dl), dlipovac012@gmail.com
 *        Company:  raptr.dev
 *
 * =====================================================================================
 */

void fatal(char* message)
{
	char error_message[160];
	
	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 143);
	perror(error_message);
	exit(-1);
}

void *error_checking_malloc(unsigned int size)
{
	void* ptr;
	ptr = malloc(size);

	if (ptr == NULL)
		fatal("in malloc() on memory allocation");

	return ptr;
}
