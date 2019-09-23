#include "ft_md5.h"


  int a0 = 0x67452301;  //A
  int b0 = 0xefcdab89;  //B
  int c0 = 0x98badcfe;  //C
  int d0 = 0x10325476;  //D


void hexDump(char *desc, void *addr, int len) 
{
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;

    // Output description if given.
    if (desc != NULL)
        printf ("%s:\n", desc);

    // Process every byte in the data.
    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).

        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.
            if (i != 0)
                printf("  %s\n", buff);

            // Output the offset.
            printf("  %04x ", i);
        }

        // Now the hex code for the specific character.
        printf(" %02x", pc[i]);

        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e)) {
            buff[i % 16] = '.';
        } else {
            buff[i % 16] = pc[i];
        }

        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf("   ");
        i++;
    }

    // And print the final ASCII bit.
    printf("  %s\n", buff);
}



unsigned char   *ft_md5(const unsigned char *d, unsigned long n, unsigned char *md)
{
  t_ft_md5_ctx ctx;
  unsigned char *dpad;

  printf("Enter md5 : %s : %ld \n", d, n);

  ft_md5_init(&ctx);
  dpad = ft_md5_padding(d, n);

  hexDump(NULL, dpad, 64);

  int a = 256;
  hexDump (NULL, &a, 16);
  size_t nalign = ft_get_size_aligned((n + FT_MD5_BYTE), FT_MD5_PADMOD);

  ft_md5_update(&ctx, dpad, nalign);

  return (EXIT_SUCCESS);
}
