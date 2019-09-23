#include "ft_ssl.h"

int main(int argc, char const *argv[])
{
  (void)argc;
  (void)argv;

  const unsigned char arg[64] = "pickle rick\n";

  unsigned char md[16];
  size_t        len;

  ft_bzero(md, sizeof(md));
  len = ft_strlen(arg);
  ft_md5(arg, len, md);
  printf("MD5(%s)\n", md);
  return 0;
}

// 1111 1011 110

// 111 1101 1110

// 1 1011 1000