#include "ft_dgst.h"

void    ft_dgst_update_words_debug(uint32_t *w, int n)
{
	int i;

	i = -1;
	printf("\n== Words for block: ==\n");
    // m[0] = swap_uint32(m[0]);
	while (++i < n)
		printf("Block[%d] = %u \n", i, w[i]);
	printf("\n");
}

void    ft_dgst_update_process_debug(uint32_t *state, int i, int n)
{
    const char letter[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    int j;

    j = -1;
    printf("[i = %d] ", i);
    while (++j < n)
        printf("%c=%u ", letter[j], state[j]);
    printf("\n");
}


void    ft_dgst_state_debug(uint32_t *state, int n)
{
    const char letter[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    int j;

    j = -1;
    printf("\n== Blocks processed: ==\n");
    while (++j < n)
        printf("%c=%u ", letter[j], state[j]);
    printf("\n");
}