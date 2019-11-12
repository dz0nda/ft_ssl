/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_dgst_opt.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/09 21:17:47 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 08:34:50 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_dgst.h"

/*
 * 	Output stdin to stdout by sending P flag to ft_dgst_file
*/

int		ft_ssl_dgst_opt_p(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[], int opt_key)
{
	(void)argc;
	(void)opt_key;
	ftssl_dgst->iarg++;
	ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
	ft_dgst_file(ftssl_dgst->cmd_key, NULL, FT_SSL_TRUE, ftssl_dgst->md);
	ftssl_dgst->outp_dist(ftssl_dgst->cmd_name, NULL, 0, ftssl_dgst->md);
	return (EXIT_SUCCESS);
}

/*
 * 	Assign cmd_arg and cmd_arg_len only if argv[i + 1] exists
 * 	Return fatal error for ssl_dgst instead
*/

static int		ft_ssl_dgst_opt_s(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[], int opt_key)
{	
	(void)opt_key;
	if (!(ftssl_dgst->iarg + 1 < argc))
		return (ft_ssl_dgst_error_opt_arg(ftssl_dgst->cmd_name, argv[ftssl_dgst->iarg] + 1));
	ftssl_dgst->iarg++;
	ft_bzero(ftssl_dgst->md, sizeof(ftssl_dgst->md));
	ft_dgst_string(ftssl_dgst->cmd_key, argv[ftssl_dgst->iarg], ft_strlen(argv[ftssl_dgst->iarg]), ftssl_dgst->md);
	if (argv[ftssl_dgst->iarg] == NULL)
		ftssl_dgst->outp_dist(ftssl_dgst->cmd_name, "", 1, ftssl_dgst->md);
	else
		ftssl_dgst->outp_dist(ftssl_dgst->cmd_name, argv[ftssl_dgst->iarg], ft_strlen(argv[ftssl_dgst->iarg]), ftssl_dgst->md);
	ftssl_dgst->iarg++;
	// ft_putendl(ftssl_dgst->md);
	return (EXIT_SUCCESS);
}

/*
 * 	Assign outp_dist and outp_flag only if FLAG_Q is not already set
*/

static int		ft_ssl_dgst_opt_outp(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[], int opt_key)
{
	(void)argc;
	(void)argv;
	if (ftssl_dgst->outp_key != FT_SSL_DGST_OPT_Q)
	{
		ftssl_dgst->outp_key = opt_key;
		if (opt_key == FT_SSL_DGST_OPT_R)
			ftssl_dgst->outp_dist = ft_ssl_dgst_output_r;
		else if (opt_key == FT_SSL_DGST_OPT_Q)
			ftssl_dgst->outp_dist = ft_ssl_dgst_output_q;
	}
	ftssl_dgst->iarg++;
	return (EXIT_SUCCESS);
}

/*
 * 	Assign cmd_name and cmd_key by opt_key
 * 	it removes '-' if found
 * 	Map dgst key and ssl_dgst
*/

static int		ft_ssl_dgst_opt_dist(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[], int opt_key)
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
	(void)argc;
	while (++i < FT_DGST_DIST)
		if (opt_key == opt_dist[i][0])
			break ;
	if (i == FT_DGST_DIST)
		return (EXIT_FAILURE);
	ftssl_dgst->cmd_key = opt_dist[i][1];
	if (argv[ftssl_dgst->iarg][0] == '-')
		ftssl_dgst->cmd_name = argv[ftssl_dgst->iarg] + 1;
	else
		ftssl_dgst->cmd_name = argv[ftssl_dgst->iarg];
	ftssl_dgst->iarg++;
	return (EXIT_SUCCESS);
}

/*
 * 	Check option at argv[idx]
 * 	if cmd_name is null, it assumes argv[idx] is without '-'
 * 	Return fatal error for ssl_dgst in case of failure
*/

int		ft_ssl_dgst_opt(t_ftssl_dgst *ftssl_dgst, int argc, char *argv[])
{
	const t_ftssl_dgst_opt_d	opt_d[FT_SSL_DGST_OPT] = {
		{ "p", 		FT_SSL_DGST_OPT_P, 		ft_ssl_dgst_opt_p },
        { "q", 		FT_SSL_DGST_OPT_Q, 		ft_ssl_dgst_opt_outp },
        { "r", 		FT_SSL_DGST_OPT_R, 		ft_ssl_dgst_opt_outp },
		{ "s", 		FT_SSL_DGST_OPT_S, 		ft_ssl_dgst_opt_s },
		{ "md5", 	FT_SSL_DGST_OPT_MD5, 	ft_ssl_dgst_opt_dist },
		{ "sha1", 	FT_SSL_DGST_OPT_SHA1, 	ft_ssl_dgst_opt_dist },
		{ "sha256", FT_SSL_DGST_OPT_SHA256, ft_ssl_dgst_opt_dist },
		{ "sha384", FT_SSL_DGST_OPT_SHA384, ft_ssl_dgst_opt_dist },
		{ "sha512", FT_SSL_DGST_OPT_SHA512, ft_ssl_dgst_opt_dist }
    };
	int i;
	char *opt;
	
	i = -1;
	if (ftssl_dgst->cmd_name == NULL)
		opt = argv[ftssl_dgst->iarg];
	else
		opt = argv[ftssl_dgst->iarg] + 1;
	while (++i < FT_SSL_DGST_OPT)
		if (ft_strcmp(opt, opt_d[i].opt_name) == 0)
			return (opt_d[i].opt_dist(ftssl_dgst, argc, argv, opt_d[i].opt_key));
	return (ft_ssl_dgst_error_opt(ftssl_dgst->cmd_name, opt));
}
