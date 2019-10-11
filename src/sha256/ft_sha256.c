#include "ft_sha256.h"
#include <stdio.h>

void hexDump (const char *desc, const void *addr, const int len) {
    int i;
    unsigned char buff[17];
    const unsigned char *pc = (const unsigned char*)addr;

    // Output description if given.
    if (desc != NULL)
        printf ("%s:\n", desc);

    if (len == 0) {
        printf("  ZERO LENGTH\n");
        return;
    }
    if (len < 0) {
        printf("  NEGATIVE LENGTH: %i\n",len);
        return;
    }

    // Process every byte in the data.
    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).

        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.
            if (i != 0)
                printf ("  %s\n", buff);

            // Output the offset.
            printf ("  %04x ", i);
        }

        // Now the hex code for the specific character.
        printf (" %02x", pc[i]);

        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }

    // And print the final ASCII bit.
    printf ("  %s\n", buff);
}

static int			ft_sha256_init(t_sha256_ctx *ctx)
{
	ft_memset(ctx, 0, sizeof(t_sha256_ctx));
	ctx->hash[0] = 0x6a09e667;
	ctx->hash[1] = 0xbb67ae85;
	ctx->hash[2] = 0x3c6ef372;
	ctx->hash[3] = 0xa54ff53a;
	ctx->hash[4] = 0x510e527f;
	ctx->hash[5] = 0x9b05688c;
	ctx->hash[6] = 0x1f83d9ab;
	ctx->hash[7] = 0x5be0cd19;
	return (EXIT_SUCCESS);
}

unsigned char		*ft_sha256(const unsigned char *d, unsigned long n, unsigned char *md)
{
	char					*dpad;
	unsigned long		nalign;
	t_sha256_ctx	ctx;

	dpad = NULL;
	nalign = ft_get_size_aligned((n + FT_SHA256_BYTE), FT_SHA256_MODBYTE);
	ft_sha256_init(&ctx);
    printf("nalign = %d\n", nalign);
	if ((dpad = ft_sha256_padding(d, nalign)) == NULL)
		return (NULL);
	hexDump(NULL, dpad, nalign);
	ft_sha256_update(&ctx, (const void *)dpad, nalign);
	ft_sha256_final(&ctx, md);
	// ft_strdel(&dpad);
	return (md);
}
