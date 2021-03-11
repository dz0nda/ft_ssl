/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:59 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/11 21:06:58 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base64.h"

void 	ft_ssl_base64_debug_struct(t_base64_ctx ctx)
{
	printf("\n-----\n");
	printf("iblock: %d\n", ctx.iblock);
	printf("state[0]: %c, state[1]: %c, state[2]: %c\n", ctx.state[0], ctx.state[1], ctx.state[2]);
	printf("\n-----\n");
}

void print_word_as_bits(char val) {
  for (int i = 5; 0 <= i; i--) {
    printf("%c", (val & (1 << i)) ? '1' : '0');
  }
}

void print_byte_as_bits_2(char *state) {

	int i = 0;
	int j = 0;
	char chunks[4][6];

	while (i < 3)
	{
		char val = state[i];
		for (int i = 7; 0 <= i; i--) {
			++j;
			printf("%c", (val & (1 << i)) ? '1' : '0');
			if (j % 6 == 0)
				printf(" ");
		}
		i++;
	}
}

// void print_bits(char * val, unsigned char * bytes, size_t num_bytes) {
//   printf("(%*s)= [ ", 16, val);
//   for (size_t i = 0; i < num_bytes; i++) {
//     print_byte_as_bits(bytes[i]);
//     printf(" ");
//   }
//   printf("] => [ ");


// 	char state[3];
// 	int istate = 0;

// 	for (size_t i = 0; i < num_bytes; i++) {
// 		ft_memcpy(&state[i], &bytes[i], sizeof(char));
// 		if (++istate == 3)
// 		{
// 			print_byte_as_bits_2(state);
// 			istate = 0;
// 			printf(" ");
// 		}
//   }
// 	// ft_memcpy(&state[3], "c", sizeof(char));
// 	// print_byte_as_bits_2(state);
// 	printf("]\n");
// }


void 	ft_ssl_base64_length(char *msg)
{
	int length_bytes = ft_strlen(msg);
	int length_bits = ft_strlen(msg) * 8;
	// int length_chunks = length_bits / 24;
	// int length_chunks = ft_align_bits(length_bits, 24);
	int pad_length_bits = ft_align_bits(length_bits, 24);
	int length_chunks = pad_length_bits / 24;

	printf("msg: %s\n", msg);
	printf("length in bytes: %d\nlength in bits: %d -> padded length: %d\n", length_bytes, length_bits, pad_length_bits);
	printf("length chunks: %d\n", length_chunks);
}

void 	ft_ssl_base64_process(char *state, int len) {

	int i = 0;
	int j = 0;
	char chunks[4][6];

	printf("[ ");
	while (len--)
	{
		char val = state[i];
		for (int i = 7; 0 <= i; i--) {
			++j;
			printf("%c", (val & (1 << i)) ? '1' : '0');
			if (j % 6 == 0)
				printf(" ");
		}
		i++;
	}
	printf(" ]\n");
}

const char base64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void 	ft_ssl_base64_exec(char *msg)
{
	t_base64_ctx ctx;
	int length_bytes = ft_strlen(msg);
	int i = 0;


	ft_memset(&ctx, 0, sizeof(ctx));

	while (i < length_bytes)
	{
		ft_memcpy(&ctx.state[ctx.iblock], &msg[i], sizeof(char));
		if (ctx.iblock == 2)
		{
			ft_ssl_base64_process(ctx.state, ctx.iblock + 1);
			// ft_memset(&ctx.state, 0, sizeof(ctx.state));
			ctx.iblock = 0;	
		}
		else
			ctx.iblock += 1;
		i++;
	}

	if (ctx.iblock != 0)
	{
		printf("\n\nThere is %d bytes left\n", 3 - ctx.iblock);
		ft_ssl_base64_process(ctx.state, ctx.iblock);
	}

	ft_ssl_base64_debug_struct(ctx);
	ft_memset(&ctx, 0, sizeof(ctx));

	i = 0;

	while (i < length_bytes)
	{

		SHOW(char, msg[i]);
		SHOW(char, msg[i + 1]);
		SHOW(char, msg[i + 2]);

		SHOW(uint32_t, (uint32_t)msg[i]);
		SHOW(uint32_t, (uint32_t)msg[i + 1]);
		SHOW(uint32_t, (uint32_t)msg[i + 2]);

		SHOW(uint32_t, ((uint32_t)msg[i]) << 16);
		SHOW(uint32_t, ((uint32_t)msg[i + 1]) << 8);
		SHOW(uint32_t, (uint32_t)msg[i + 2]);

		ctx.base64_state = ((uint32_t)msg[i]) << 16;

	  SHOW(uint32_t, ctx.base64_state);

		if((i + 1) < length_bytes)
			ctx.base64_state += ((uint32_t)msg[i + 1]) << 8;
	
		SHOW(uint32_t, ctx.base64_state);

		if((i + 2) < length_bytes)
			ctx.base64_state += msg[i + 2];
	
	  SHOW(uint32_t, ctx.base64_state);
	  SHOW(uint32_t, ctx.base64_state >> 18);
	  SHOW(uint32_t, ctx.base64_state >> 12);
	  SHOW(uint32_t, ctx.base64_state >> 6);

		ctx.words[0] = (uint8_t)(ctx.base64_state >> 18);
		ctx.words[1] = (uint8_t)(ctx.base64_state >> 12);
		ctx.words[2] = (uint8_t)(ctx.base64_state >> 6);
		ctx.words[3] = (uint8_t)ctx.base64_state;

	  SHOW(char, ctx.words[0]);
	  SHOW(char, ctx.words[1]);
	  SHOW(char, ctx.words[2]);
	  SHOW(char, ctx.words[3]);

		printf("\n");
		ctx.words[0] = (uint8_t)(ctx.base64_state >> 18) & 0x3F;
		ctx.words[1] = (uint8_t)(ctx.base64_state >> 12) & 0x3F;
		ctx.words[2] = (uint8_t)(ctx.base64_state >> 6) & 0x3F;
		ctx.words[3] = (uint8_t)ctx.base64_state & 0x3F;

	  SHOW(char, ctx.words[0]);
	  SHOW(char, ctx.words[1]);
	  SHOW(char, ctx.words[2]);
	  SHOW(char, ctx.words[3]);


		// print_word_as_bits(ctx.words[0]);
		// printf(" ");
		// print_word_as_bits(ctx.words[1]);
		// printf(" ");
		// print_word_as_bits(ctx.words[2]);
		// printf(" ");
		// print_word_as_bits(ctx.words[3]);

		i += 3;
		// ft_memcpy(&ctx.state[ctx.iblock], &msg[i], sizeof(char));
		// if (ctx.iblock == 2)
		// {
		// 	ft_ssl_base64_process(ctx.state, ctx.iblock + 1);
		// 	// ft_memset(&ctx.state, 0, sizeof(ctx.state));
		// 	ctx.iblock = 0;	
		// }
		// else
		// 	ctx.iblock += 1;
	}

	ft_ssl_base64_debug_struct(ctx);

	// if (ctx.iblock != 0)
	// {
	// 	printf("\n\nThere is %d bytes left\n", 3 - ctx.iblock);
	// 	ft_ssl_base64_process(ctx.state, ctx.iblock);
	// }
}

void 	ft_ssl_base64(char *msg)
{
	printf("base64 encode:\n");
	printf("msg: %s\n", msg);
	// ft_ssl_base64_length(msg);
  // // print_bits(msg, (unsigned char*)msg, ft_strlen(msg));
	// ft_ssl_base64_exec(msg);
}

void 	ft_ssl_base64_decode(char *msg)
{
	printf("base64 decode:\n");
	printf("msg: %s\n", msg);
}