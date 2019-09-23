#include "ft_md5.h"

void hexDump(char *desc, void *addr, int len) 
{
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;

    if (desc != NULL)
        printf ("%s:\n", desc);
    for (i = 0; i < len; i++) {
        if ((i % 16) == 0) {
            if (i != 0)
                printf("  %s\n", buff);
            printf("  %04x ", i);
        }
        printf(" %02x", pc[i]);
        if ((pc[i] < 0x20) || (pc[i] > 0x7e)) {
            buff[i % 16] = '.';
        } else {
            buff[i % 16] = pc[i];
        }
        buff[(i % 16) + 1] = '\0';
    }
    while ((i % 16) != 0) {
        printf("   ");
        i++;
    }
    printf("  %s\n", buff);
}

void  ft_put_uint32(uint32_t state)
{
  unsigned char c[4];

  c[0] = (unsigned char)( (state)       ) & 0xFF;
  c[1] = (unsigned char)( (state) >>  8 ) & 0xFF;  
  c[2] = (unsigned char)( (state) >> 16 ) & 0xFF;  
  c[3] = (unsigned char)( (state) >> 24 ) & 0xFF;  

    int rest = state & 255;

    printf("uint rest : .%c. \n", rest);

  printf("uint : .%c. .%c. .%c. .%c. \n", c[0], c[1], c[2], c[3]);
  printf("uint: %s \n", c);
}


unsigned char   *ft_md5(const unsigned char *d, unsigned long n, unsigned char *md)
{
  t_ft_md5_ctx  ctx;
  unsigned char *dpad;

  printf("Enter md5 : %s : %ld \n", d, n);

  ft_md5_init(&ctx);

  dpad = ft_md5_padding(d, n);

  hexDump(NULL, dpad, 64);


    ft_put_uint32(0x67452301);

  // int a = 256;
  // hexDump (NULL, &a, 16);
  // size_t nalign = ft_get_size_aligned((n + FT_MD5_BYTE), FT_MD5_PADMOD);

 //  ft_md5_update(&ctx, dpad, nalign);

  return (EXIT_SUCCESS);
}
