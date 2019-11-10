/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_opt.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/09 21:17:47 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 17:12:48 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

int		ft_ssl_dgst_parse_options_p(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	const int fd = 0;
	int bytes;
	char buffer[FTSSL_DGST_MAX_BUFFER];
	char c[2];

	ft_putendl("Parse -p");

    ft_bzero(buffer, sizeof(buffer));
	ft_bzero(c, sizeof(c));
	ftssl_dgst->ctx.cmd_arg_len = 0;
	while ((bytes = read(fd, c, 1)) > 0)
	{
		ftssl_dgst->ctx.cmd_arg_len += bytes;
		ft_strcat(buffer, c);
		ft_bzero(c, sizeof(c));
	}
	close(fd);
	printf("BYtes = %d\n", bytes);
    // if (read(0, buffer, FTSSL_DGST_MAX_BUFFER - 1) < 0)
        // return (EXIT_FAILURE)
	ft_putendl("\n\n\n");
	ft_putendl(buffer);
	ftssl_dgst->ctx.cmd_arg = buffer;
	ftssl_dgst->inpt.i++;
	ft_ssl_dgst_exec(ftssl_dgst);
	// Execute
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_parse_options_s(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	ft_putendl("Parse -s");
	if (ftssl_dgst->inpt.argv[ftssl_dgst->inpt.i + 1] == NULL)
		return (ft_ssl_dgst_error_opt_arg(ftssl_dgst->ctx.cmd_name, ftssl_dgst->inpt.argv[ftssl_dgst->inpt.i] + 1));
	ftssl_dgst->ctx.cmd_arg = ftssl_dgst->inpt.argv[++ftssl_dgst->inpt.i];
	ftssl_dgst->inpt.i++;
	ftssl_dgst->ctx.cmd_arg_len = ft_strlen(ftssl_dgst->ctx.cmd_arg);
	ft_ssl_dgst_exec(ftssl_dgst);
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_opt_outp(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	if (ftssl_dgst->outp.outp_flag != FT_SSL_DGST_OPT_Q)
	{
		ftssl_dgst->outp.outp_flag = opt_key;
		if (opt_key == FT_SSL_DGST_OPT_R)
			ftssl_dgst->outp.outp_dist = ft_ssl_dgst_output_r;
		else if (opt_key == FT_SSL_DGST_OPT_Q)
			ftssl_dgst->outp.outp_dist = ft_ssl_dgst_output_q;
	}
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_opt_dist(t_ftssl_dgst *ftssl_dgst, int opt_key)
{
	const int opt_dist[FT_DGST_DIST][2] = {
		{ FT_SSL_DGST_OPT_MD5, FT_MD5 },
		{ FT_SSL_DGST_OPT_SHA1, FT_SHA1 },
		{ FT_SSL_DGST_OPT_SHA256, FT_SHA256 },
		{ FT_SSL_DGST_OPT_SHA384, FT_SHA384 },
		{ FT_SSL_DGST_OPT_SHA512, FT_SHA512 }
	};
    int i;

    i = -1;
	while (++i < FT_DGST_DIST)
		if (opt_key == opt_dist[i][0])
			break ;
	if (i == FT_DGST_DIST)
		return (EXIT_FAILURE);
	ftssl_dgst->ctx.cmd_key = opt_dist[i][1];
	if (ftssl_dgst->inpt.argv[ftssl_dgst->inpt.i][0] == '-')
		ftssl_dgst->ctx.cmd_name = ftssl_dgst->inpt.argv[ftssl_dgst->inpt.i] + 1;
	else
		ftssl_dgst->ctx.cmd_name = ftssl_dgst->inpt.argv[ftssl_dgst->inpt.i];
	ftssl_dgst->inpt.i++;
	return (EXIT_SUCCESS);
}

int		ft_ssl_dgst_opt(t_ftssl_dgst *ftssl_dgst, char *opt)
{
	t_ftssl_dgst_opt dist_opt[FT_SSL_DGST_OPT] = {
		{ "p", FT_SSL_DGST_OPT_P , ft_ssl_dgst_parse_options_p },
        { "q", FT_SSL_DGST_OPT_Q, ft_ssl_dgst_opt_outp },
        { "r", FT_SSL_DGST_OPT_R, ft_ssl_dgst_opt_outp },
		{ "s", FT_SSL_DGST_OPT_S, ft_ssl_dgst_parse_options_s },
		{ "md5", FT_SSL_DGST_OPT_MD5, ft_ssl_dgst_opt_dist },
		{ "sha1", FT_SSL_DGST_OPT_SHA1, ft_ssl_dgst_opt_dist },
		{ "sha256", FT_SSL_DGST_OPT_SHA256, ft_ssl_dgst_opt_dist },
		{ "sha384", FT_SSL_DGST_OPT_SHA384, ft_ssl_dgst_opt_dist },
		{ "sha512", FT_SSL_DGST_OPT_SHA512, ft_ssl_dgst_opt_dist }
    };
	int i;
	
	printf("DGST_OPT = %s\n", opt);

	i = -1;
	while (++i < FT_SSL_DGST_OPT)
		if (ft_strcmp(opt, dist_opt[i].opt_name) == 0)
			return (dist_opt[i].opt_dist(ftssl_dgst, dist_opt[i].opt_key));
	return (ft_ssl_dgst_error_opt(ftssl_dgst->ctx.cmd_name, opt));
}
