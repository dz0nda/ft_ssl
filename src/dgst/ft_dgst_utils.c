#include "ft_dgst.h"

#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 16
#endif
 
uint32_t		ft_rotate_left(uint32_t word, uint32_t bits)
{
	return ((word << bits) | (word >> (32 - bits)));
}

uint32_t		ft_rotate_right(uint32_t word, uint32_t bits)
{
	return ((word >> bits) | (word << (32 - bits)));
}

uint32_t		ft_shift_right(uint32_t word, uint32_t bits)
{
	return (word >> bits);
}

uint64_t		ft_rotate_left64(uint64_t word, uint64_t bits)
{
	return ((word << bits) | (word >> (64 - bits)));
}

uint64_t		ft_rotate_right64(uint64_t word, uint64_t bits)
{
	return ((word >> bits) | (word << (64 - bits)));
}

uint64_t		ft_shift_right64(uint64_t word, uint64_t bits)
{
	return (word >> bits);
}

uint32_t swap_uint32( uint32_t val )
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

uint64_t swap_uint64( uint64_t val )
{
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
    return (val << 32) | (val >> 32);
}

void hexdump(void *mem, unsigned int len)
{
	unsigned int i, j;
	
	for(i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++)
	{
        /* print offset */
        if(i % HEXDUMP_COLS == 0)
        {
            printf("0x%06x: ", i);
        }

        /* print hex data */
        if(i < len)
        {
            printf("%02x ", 0xFF & ((char*)mem)[i]);
        }
        else /* end of block, just aligning for ASCII dump */
        {
            printf("   ");
        }
        
        /* print ASCII dump */
        if(i % HEXDUMP_COLS == (HEXDUMP_COLS - 1))
        {
            for(j = i - (HEXDUMP_COLS - 1); j <= i; j++)
            {
                if(j >= len) /* end of block, not really printing */
                {
                                putchar(' ');
                }
                else if(ft_isprint(((char*)mem)[j])) /* printable char */
                {
                                putchar(0xFF & ((char*)mem)[j]);        
                }
                else /* other char */
                {
                                putchar('.');
                }
            }
            putchar('\n');
        }
	}
}
