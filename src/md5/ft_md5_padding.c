#include "ft_md5.h"

size_t			ft_get_size_aligned(size_t offset, size_t align)
{
	return (offset + (align - (offset % align) % align));
}

static void  ft_md5_padding_lenght(unsigned char *dpad, unsigned long nalign, unsigned long n, unsigned long *i)
{
  char bytes[8];
  int nbytes;

  nbytes = -1;
  n = (n * 8) % FT_MD5_LENGHTMOD;
  while (++nbytes < FT_MD5_BYTE)
  {
    if (n > 0)
    {
      bytes[nbytes] = n % 256;
      n /= 256;
    }
    else
      bytes[nbytes] = 0;
  }
  while (nbytes-- > 0)
  {
    dpad[*i] = bytes[nbytes];
    (*i)++;
  }
}

static void  ft_md5_padding_default(unsigned char *dpad, unsigned long nalign, unsigned long *i)
{
  static const unsigned char ft_md5_padding[64] = {
      0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };
  size_t j;

  j = 0;
  while ((*i) < (nalign - FT_MD5_BYTE))
  {
    dpad[*i] = ft_md5_padding[j];
    j++; 
    (*i)++;
  }
}

static char *ft_md5_padding_new(const unsigned char *d, unsigned long nalign)
{
  char   *dpad;

  printf("Size aligned : %ld bytes / %ld\n", nalign, nalign * 8);
  if ((dpad = ft_strnew(nalign)) == NULL)
    return (NULL);
  ft_strcpy(dpad, d);
  return (dpad);
}

char  *ft_md5_padding(const unsigned char *d, unsigned long n)
{

  size_t i;
  size_t nalign;
  char   *dpad;

  i = n;
  nalign = ft_get_size_aligned((n + FT_MD5_BYTE), FT_MD5_PADMOD);
  if ((dpad = ft_md5_padding_new(d, nalign)) == NULL)
    return (NULL);
  ft_md5_padding_default(dpad, nalign, &i);
  printf("i returned from default : %ld\n", i);
  ft_md5_padding_lenght(dpad, nalign, n, &i);
  printf("i returned from lenght : %ld\n", i);
  return (dpad);
}
