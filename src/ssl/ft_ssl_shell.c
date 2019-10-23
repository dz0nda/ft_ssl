#include "ft_ssl.h"
// char		*ft_get_user_input(t_prompt *prompt)
// {
// 	t_shell	sh;
// 	char	buff[5];

// 	ft_memset(&sh, 0, sizeof(sh));
// 	ft_memset(buff, 0, sizeof(buff));
// 	if (ft_init_shell_struct(&sh, prompt) == -1)
// 		return (g_cmd = ft_strdup("exit\n"));
// 	ft_init_input_keys(&sh);
// 	get_term_raw_mode(1);
// 	while (1)
// 	{
// 		ft_bzero(buff, 5);
// 		if (!(read(0, buff, 4)))
// 			return (NULL);
// 		tputs(tgetstr("vi", NULL), 1, ft_putchar);
// 		ft_get_cols(&sh.ws);
// 		if (ft_get_user_input_buff_checker(&sh, buff))
// 			return (g_cmd);
// 		tputs(tgetstr("ve", NULL), 1, ft_putchar);
// 	}
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>

#define MAX_BUFFER 512
#define MAX_STRINGS 10

int sslRead(void) {
    char buffer[MAX_BUFFER];

    if ( !fgets(buffer, MAX_BUFFER, stdin) ) {
        fprintf(stderr, "Couldn't get input.\n");
        return EXIT_FAILURE;
    }
    else {

        /*  Remove trailing newline, if present  */

        size_t length = strlen(buffer);
        if ( length && buffer[length - 1] == '\n' ) {
            buffer[length - 1] = '\0';
        }
    }

    char *my_strings[MAX_STRINGS + 1] = {NULL};
    int read_strings = 0;
    char *buf_ptr = buffer;

    while ( *buf_ptr && read_strings < MAX_STRINGS ) {
        char temp_buf[MAX_BUFFER] = {0};
        char *temp_ptr = temp_buf;

        /*  Skip leading whitespace  */

        while ( *buf_ptr && isspace(*buf_ptr) ) {
            ++buf_ptr;
        }

        if ( *buf_ptr ) {
            if ( *buf_ptr == '"' ) {

                /*  If starts with '"', read to next '"'...  */

                ++buf_ptr;      /*  Skip first "  */
                while ( *buf_ptr && *buf_ptr != '"' ) {
                    *temp_ptr++ = *buf_ptr++;
                }

                if ( *buf_ptr ) {
                    ++buf_ptr;  /*  Skip second "  */
                }
            }
            else {

                /*  ...otherwise, read to next whitespace  */

                while ( *buf_ptr && !isspace(*buf_ptr) ) {
                    *temp_ptr++ = *buf_ptr++;
                }
            }

            /*  Copy substring into string array  */

            my_strings[read_strings] = malloc(strlen(temp_buf) + 1);
            if ( !my_strings[read_strings] ) {
                fprintf(stderr, "Couldn't allocate memory.\n");
                return EXIT_FAILURE;
            }
            strcpy(my_strings[read_strings++], temp_buf);
        }
    }

    for ( size_t i = 0; my_strings[i]; ++i ) {
        printf("String %zu: %s\n", i + 1, my_strings[i]);
        free(my_strings[i]);
    }

    return 0;
}
// void readFile(int fd) {
//     char buffer[10];
//     int bytes_read;
//     int k = 0;
//     do {
//         char t = 0;
//         bytes_read = read(fd, &t, 1); 
//         buffer[k++] = t;    
//         printf("%c", t);
//         if(t == '\n' && t == '\0') {
//             printf("%d", atoi(buffer));
//             for(int i=0; i<10; i++) 
//                 buffer[i]='\0';
//             k = 0;
//         }
//     }
//     while (bytes_read != 0); 
// }

void        readFile(int fd) {
    char buffer[MAX_BUFFER];
    int bytes_read;
    int k = 0;
    int i;
    char c[1];
    int exit = 1;

    i = -1;
    while (exit)
    {
        ft_memset(c, 0, sizeof(c));
        bytes_read = read(fd, &c, 1);
        if (bytes_read == 0)
        {
            ft_putendl("\n0 bytes read\n");
            return ;
        }
        if (bytes_read == -1)
        {
            ft_putendl("\nerror with read\n");
            return ;
        }
        ft_putchar(c[0]);
    }
}

int     ft_ssl_shell_open(char *file)
{
    int fd[2];

    if (access(file, F_OK) == 0)
    {
        fd[0] = open(file, O_RDONLY);
        readFile(fd[0]);
        close(fd[0]);
    }
    else {
        printf("file %s not found\n", file);
        fd[0] = open(0, O_RDONLY);
        readFile(0);
        close(fd[0]);
    }
    return (EXIT_SUCCESS);
}

void            ft_ssl_shell_prompt()
{
    ft_putstr("ftSSL> ");
}


// int     ft_ssl_dispatch()
// {
//     static int (* const pf[FT_SSL_CMD][FT_SSL_DGST_CMD])(void) = 
//     {
//         {fnUp, fnDown, fnNull, ..., fnMenu},
// 	    {fnMenu, fnNull, ..., fnHome}, 
//     };
// }

int		        ft_ssl_shell(t_ftssl *ssl)
{
    t_ftssl_sh  sh;
	char	buff[5];
    int exit;

    ft_memset(&sh, 0, sizeof(sh));
    ft_memset(buff, 0, sizeof(buff));
    exit = FT_SSL_SUCCESS;
    while(exit = FT_SSL_SUCCESS)
    {
        ft_ssl_shell_prompt();
        
    }
    ft_ssl_shell_open("0");
    // sslRead();
}
