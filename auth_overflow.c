#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_authentication(char *);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <password>\n", argv[0]);
    }

    if (check_authentication(argv[1]))
    {
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("    Access Granted.\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    }
    else
    {
        printf("\nAccess Denied.\n");
    }
}

int check_authentication(char *password)
{
    int auth_flag = 0;
    char password_buffer[16];

    strcpy(password_buffer, password);

    if (strcmp(password_buffer, "brillig") == 0)
        auth_flag = 1;
    if (strcmp(password_buffer, "outgrabe") == 0)
        auth_flag = 1;

    return auth_flag;
}