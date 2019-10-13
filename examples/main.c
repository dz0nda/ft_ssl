// # include "sha.h"
// # include "sha-private.h"
# include "stdio.h"

// void print(SHA256Context ctx)
// {
//     int i = -1;

//     while (++i < (SHA256HashSize/4))
//         printf("IH = %x\n", ctx.Intermediate_Hash[i]);

//     printf("LH = %d\n", ctx.Length_High);
//     printf("LL = %d\n", ctx.Length_Low);

//     printf("MDI = %d\n", ctx.Message_Block_Index);
// }

// int main()
// {
//     SHA256Context ctx;
//     uint8_t Message_Digest[SHA256HashSize];
//     const char *input = "a";
//     unsigned int bits = strlen(input) * 8;

//     SHA256Reset(&ctx);
//     SHA256Input(&ctx, input, strlen(input));
//     SHA256FinalBits(&ctx, bits, 8);
//     SHA224Result(&ctx, Message_Digest);

//     int i = -1;
//     while (++i < SHA256HashSize)
//         printf("%x", Message_Digest[i]);
//     printf("\n");

//     print(ctx);
    
// }

int main()  
{  
    unsigned int i = 1;  
    char *c = (char*)&i;  
    if (*c)  
        printf("Little endian");  
    else
        printf("Big endian");  
    return 0;  
}