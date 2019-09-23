#include "ft_md5.h"

  int32_t s[64] = { 
    7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22, 
    5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
    4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
    6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21  
  };
  int32_t K[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
  };

// char  *ft_md5_process(t_ft_md5_ctx *ctx, unsigned char *dpad)
// {
//   int i;
//   uint32_t A;
//   uint32_t B;
//   uint32_t C;
//   uint32_t D;

//   i = -1;
//   A = ctx->state[0];
//   B = ctx->state[1];
//   C = ctx->state[2];
//   D = ctx->state[3];
//   while (++i < 64)
//   {
//     if (0 <= i && i <= 15)
//     {
//       F = (B && C)
//     } 
//   }

// }

uint32_t ft_leftrotate(uint32_t x, uint32_t c)
{
  return ((x << c) | (x >> (32 - c)));
}

static void  ft_put_uint32(uint32_t state)
{
  unsigned char c[4];

  c[0] = (unsigned char)( (state)       ) & 0xFF;
  c[1] = (unsigned char)( (state) >>  8 ) & 0xFF;  
  c[2] = (unsigned char)( (state) >> 16 ) & 0xFF;  
  c[3] = (unsigned char)( (state) >> 24 ) & 0xFF;  

  printf("uint : %s \n", c);
}

void  ft_get_uint32(uint32_t n, uint32_t *b, uint32_t i)
{
    (n) = ( (uint32_t) (b)[(i)    ]       )           
        | ( (uint32_t) (b)[(i) + 1] <<  8 )     
        | ( (uint32_t) (b)[(i) + 2] << 16 )
        | ( (uint32_t) (b)[(i) + 3] << 24 );   
}

int   ft_md5_update(t_ft_md5_ctx *ctx, const void *data, unsigned long len)
{
  int i;
  // uint32_t *M;

  // M = (uint32_t *)data;
  uint32_t X[16];
    ft_get_uint32( X[ 0], data,  0 );
    ft_put_uint32(X[0]);
    ft_get_uint32( X[ 1], data,  4 );
    ft_get_uint32( X[ 2], data,  8 );
    ft_get_uint32( X[ 3], data, 12 );
    ft_get_uint32( X[ 4], data, 16 );
    ft_get_uint32( X[ 5], data, 20 );
    ft_get_uint32( X[ 6], data, 24 );
    ft_get_uint32( X[ 7], data, 28 );
    ft_get_uint32( X[ 8], data, 32 );
    ft_get_uint32( X[ 9], data, 36 );
    ft_get_uint32( X[10], data, 40 );
    ft_get_uint32( X[11], data, 44 );
    ft_get_uint32( X[12], data, 48 );
    ft_get_uint32( X[13], data, 52 );
    ft_get_uint32( X[14], data, 56 );
    ft_get_uint32( X[15], data, 60 );
  printf("%ld \n", len);
  while (len > 0)
  {
    // printf("%d \n", len);
    i = -1;
    uint32_t A = ctx->state[0];
    uint32_t B = ctx->state[1];
    uint32_t C = ctx->state[2];
    uint32_t D = ctx->state[3];

    while (++i < 64)
    {
      uint32_t F;
      int g;
      if (0 <= i && i <= 15)
      {
        F = (B && C) || ((!B) && D);
        g = i;
      }
      else if (16 <= i && i <= 31)
      {
        F = (D && B) || ((!D) && C);
        g = (5 * 1 + 1) % 16;
      }
      else if (32 <= i && i <= 47)
      {
        F = B ^ C ^ D;
        g = (3 * 1 + 5) % 16;
      }
      else if (48 <= i && i <= 63)
      {
        F = C ^ (B || (!D));
        g = (7 * 1) % 16;
      }
      F = F + A + K[i] + X[g];
      A = D;
      D = C;
      C = B;
      B = B + ft_leftrotate(F, s[i]);
    }
    ctx->state[0] += A;
    ctx->state[1] += B;
    ctx->state[2] += C;
    ctx->state[3] += D;
    len -= 64;
  }

  printf("%ld - %ld - %ld - %ld \n", ctx->state[0], ctx->state[1], ctx->state[2], ctx->state[3]);

  ft_put_uint32(ctx->state[0]);
  ft_put_uint32(ctx->state[1]);
  ft_put_uint32(ctx->state[2]);
  ft_put_uint32(ctx->state[3]);

  char digest[16];
  // i = 0;
  // int j = -1;
  // int k = 0;
  // while (i < 16)
  // {
  //   j = -1;
  //   while (++j < 4)
  //   {
  //     digest[i] = ctx->state[k] % 255;
  //     ctx->state[k] /= 255;
  //     i++;
  //   }
  //   k++;
  // }
 // ft_put_uint32()
  // printf("digest: %s \n", digest);
}
