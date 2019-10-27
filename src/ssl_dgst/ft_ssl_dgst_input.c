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

// int     ft_ssl_shell_open(char *file)
// {
//     int fd[2];

//     if (access(file, F_OK) == 0)
//     {
//         fd[0] = open(file, O_RDONLY);
//         readFile(fd[0]);
//         close(fd[0]);
//     }
//     else {
//         printf("file %s not found\n", file);
//         fd[0] = open(0, O_RDONLY);
//         readFile(0);
//         close(fd[0]);
//     }
//     return (EXIT_SUCCESS);
// }