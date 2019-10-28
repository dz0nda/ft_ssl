#include "ft_ssl.h"

t_dgst_ctx        *ft_dgst_init_ctx(int cmd_key)
{
	const int dgst_ctx[FT_DGST_CMD][4] = {
		{ FT_MD5, FT_MD5_HS, FT_MD5_MBS, FT_DGST_LITTLE_ENDIAN},
		{ FT_SHA1, FT_SHA1_HS, FT_SHA1_MBS, FT_DGST_BIG_ENDIAN},
		{ FT_SHA256,FT_SHA256_HS, FT_SHA256_MBS, FT_DGST_BIG_ENDIAN}
	};
	t_dgst_ctx	*ctx;	

	ctx = NULL;
	if ((ctx = (t_dgst_ctx *)malloc(sizeof(t_dgst_ctx))) == NULL)
		return (NULL);
	ft_memset(ctx, 0, sizeof(t_dgst_ctx));
	ctx->len_hs = dgst_ctx[cmd_key][1];
	ctx->len_mbs = dgst_ctx[cmd_key][2];
	ctx->endian = dgst_ctx[cmd_key][3];
	ctx->len_state = ctx->len_hs / 4;
	ctx->state = (uint32_t *)malloc(sizeof(uint32_t) * ctx->len_state);
	ctx->block = (uint8_t *)malloc(sizeof(uint8_t) * ctx->len_mbs);
	if (ctx->state == NULL || ctx->block == NULL)
	{
		ctx->state != NULL ? free(ctx->state) : 0;
		ctx->block != NULL ? free(ctx->block) : 0;
		free(ctx);
		return (NULL);
	}
	return (ctx);
}

t_dgst_act		ft_dgst_init_act(int cmd_key)
{
	int (* dgst_act[FT_DGST_CMD][2])(t_dgst_ctx *) = {
        { ft_ssl_dgst_init_md5_sha1, ft_ssl_dgst_update_md5 }, 
        { ft_ssl_dgst_init_md5_sha1, ft_ssl_dgst_update_sha1 },
        { ft_ssl_dgst_init_sha256, ft_ssl_dgst_update_sha256 }
	};
	t_dgst_act	act;	

	ft_memset(&act, 0, sizeof(t_dgst_act));
	act.init = dgst_act[cmd_key][0];
	act.update = dgst_act[cmd_key][1];
	return (act);
}

int         		ft_dgst(t_ftssl *ssl)
{
    printf("ïm in dgst\n");
	t_ftssl_dgst	dgst;

    ft_memset(&dgst, 0, sizeof(dgst));
	int i = 0;
	dgst.cmd_key = 0;
	dgst.cmd_name = "md5";
	while (ssl->sh.argv[i] != NULL)
		ft_putendl(ssl->sh.argv[i++]);
	dgst.ctx = ft_dgst_init_ctx(dgst.cmd_key);
	dgst.act = ft_dgst_init_act(dgst.cmd_key);
	dgst.act.init(dgst.ctx);
	dgst.act.update(dgst.ctx);


	i = -1;
	while (++i < dgst.ctx->len_state)
		printf("%x\n", dgst.ctx->state[i]);

	return (EXIT_SUCCESS);
}

int		    ft_cipher(t_ftssl *ssl)
{
    printf("ïm in cipher\n");
	return (EXIT_SUCCESS);
}

int			ft_stdrd(t_ftssl *ssl)
{
    printf("ïm in stdrd\n");
	return (EXIT_SUCCESS);
}

int         ft_unknown(t_ftssl *ssl)
{
	ft_putstr("ft_ssl: Error: '");
	ft_putstr(ssl->sh.cmd);
	ft_putstr("' is an invalid command.\n");
    ft_ssl_usage();
	return (EXIT_SUCCESS);
}