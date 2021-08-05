/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_des.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzonda <dzonda@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:11:57 by dzonda            #+#    #+#             */
/*   Updated: 2021/03/17 12:25:41 by dzonda           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_des.h"

const char ft_random2[] = { 0x16, 0xF7, 0xA4, 0xA5, 0x14, 0x6B, 0xC9, 0xBE };

char *pass_arg = "dzonda";
char *salt_arg = "488843243FBFF7D9";
char *key_arg = "133457799BBCDFF1";//"6162636465666768"; //abcdefgh

int		ft_ssl_des_exec_handle_salt(t_ssl_des *ctx)
{
	// printf("Handling !\n");

  int randomData = open("/dev/urandom", O_RDONLY);
  if (randomData < 0) {
      ft_putendl_fd("Something went wrong when generating random number", STDERR_FILENO);
      return (EXIT_FAILURE);
}
else
{
    char myRandomData[8];
    ssize_t result = read(randomData, myRandomData, sizeof myRandomData);
    if (result < 0) {
			ft_putendl_fd("Something went wrong when generating random number", STDERR_FILENO);
			return (EXIT_FAILURE);
    }
		ft_memcpy(ctx->opt.salt, myRandomData, 8);
}

	return (EXIT_SUCCESS);
}

int		ft_ssl_des_exec_handle_password(t_ssl_des *ctx)
{
	char passbuf[256];
	char passbuf_confirm[256];

	ft_bzero(passbuf, 256);
	ft_bzero(passbuf_confirm, 256);

	if (readpassphrase("enter des-ecb encryption password: ", passbuf,
				sizeof(passbuf), 0) == NULL)
		return (EXIT_FAILURE);
	
	if (readpassphrase("Verifying - enter des-ecb encryption password: ", passbuf_confirm,
				sizeof(passbuf_confirm), 0) == NULL)
		return (EXIT_FAILURE);

	if (ft_memcmp(passbuf, passbuf_confirm, 256) != 0) {
		ft_putendl_fd("Verify failure", STDERR_FILENO);
		ft_putendl_fd("bad password read", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	ft_memcpy(ctx->opt.pass, passbuf, 256);

	return (EXIT_SUCCESS);
}

int		ft_ssl_des_exec_pre_process(t_ssl_des *ctx)
{
  // if (ft_strlen(ctx->opt.key)) {
  //   uint64_t n = hex2int(ctx->opt.key);
  //   ft_memcpy(ctx->opt.key, &n, sizeof(n));
  if (!ft_strlen(ctx->opt.key)) {
    if (!ft_strlen(ctx->opt.pass))
      ft_ssl_des_exec_handle_password(ctx);
    
    if (!ft_strlen(ctx->opt.salt))
      ft_ssl_des_exec_handle_salt(ctx);

    uint64_t n = hex2int(ctx->opt.salt);
    ft_memcpy(ctx->opt.salt, &n, sizeof(n));

    ft_des_kdf(ctx->opt.pass, ctx->opt.salt, ctx->opt.key, ctx->opt.iv);
  }

  uint64_t n = hex2int(ctx->opt.key);
  ft_memcpy(ctx->opt.key, &n, sizeof(n));

	n = hex2int(ctx->opt.iv);
	ft_memcpy(ctx->opt.iv, &n, sizeof(n));
	// if (ft_strlen(ctx->opt.pass) == 0 && ft_strlen(ctx->opt.key) == 0)
	// 	ft_ssl_des_exec_handle_password(ctx);

	// if (ft_strlen(ctx->opt.salt) == 0) {
	// 		uint64_t n = hex2int(salt_arg);
	// 		ft_memcpy(ctx->opt.salt, &n, sizeof(n));
	// } else {
	// 		ft_ssl_des_exec_handle_salt(ctx);
	// 		printf("ctxsalt: %s\n", ctx->opt.salt);
	// 		// ft_get_random(ctx->opt.salt);
	// 		uint64_t n = hex2int(ctx->opt.salt);
	// 		ft_memcpy(ctx->opt.salt, &n, sizeof(n));
	// }

	// printf("key: %s\n", ctx->opt.key);

	// if (ft_strlen(ctx->opt.key) == 0) {
	// 		ft_des_kdf(pass_arg, ctx->opt.salt, ctx->opt.key, ctx->opt.iv);
	// 		uint64_t n = hex2int(ctx->opt.key);
	// 		ft_memcpy(ctx->opt.key, &n, sizeof(n));
	// } else {
	// 		uint64_t n = hex2int(ctx->opt.key);
	// 		ft_memcpy(ctx->opt.key, &n, sizeof(n));
	// }

	// printf("key: %s\n", ctx->opt.key);

}
