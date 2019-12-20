# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: dzonda <dzonda@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/11 05:46:03 by dzonda       #+#   ##    ##    #+#        #
#    Updated: 2019/12/20 14:12:00 by dzonda      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_ssl
SRCDIR = src
OBJDIR = obj
LIBDIR = libft

MAKEFILE_NAME = Makefile-$(lastword $(subst /, ,$(NAME)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunused -Wunreachable-code
LDFLAGS = -Llibft 
LDLIBS = -lft 
SUBDIR = \
			dgst \
			ssl \
			ssl_cipher \
			ssl_dgst \
			ssl_stdrd
SUBFILE = \
			ssl/ft_ssl.c \
			ssl/ft_ssl_init.c \
			ssl/ft_ssl_shell.c \
			ssl/ft_ssl_dist.c \
			ssl/ft_ssl_core.c \
			\
			dgst/ft_dgst.c \
			dgst/ft_dgst_init.c \
			dgst/ft_dgst_debug.c \
			dgst/ft_dgst_rotate.c \
			dgst/ft_dgst_swap_shift.c \
			dgst/ft_dgst_file.c \
			dgst/ft_dgst_string.c \
			dgst/ft_dgst_result.c \
			dgst/ft_md5.c \
			dgst/ft_sha1.c \
			dgst/ft_sha224.c \
			dgst/ft_sha256.c \
			dgst/ft_sha384.c \
			dgst/ft_sha512.c \
			\
			ssl_dgst/ft_ssl_dgst.c \
			ssl_dgst/ft_ssl_dgst_dist.c \
			ssl_dgst/ft_ssl_dgst_parse.c \
			ssl_dgst/ft_ssl_dgst_opt.c \
			ssl_dgst/ft_ssl_dgst_arg.c \
			ssl_dgst/ft_ssl_dgst_output.c \
			ssl_dgst/ft_ssl_dgst_error.c \
			ssl_dgst/ft_ssl_dgst_usage.c \
			\
			ssl_cipher/ft_ssl_cipher.c \
			ssl_cipher/ft_ssl_cipher_dist.c \
			\
			ssl_stdrd/ft_ssl_stdrd.c \
			ssl_stdrd/ft_ssl_stdrd_dist.c

SRCDIRS = $(foreach dir, $(SUBDIR), $(addprefix $(SRCDIR)/, $(dir)))
OBJDIRS = $(foreach dir, $(SUBDIR), $(addprefix $(OBJDIR)/, $(dir)))
INCLUDES = $(foreach dir, $(SRCDIRS), $(addprefix -I, $(dir)))

SRCS = $(foreach file, $(SUBFILE), $(addprefix $(SRCDIR)/, $(file)))
OBJS := $(subst $(SRCDIR),$(OBJDIR),$(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

VERBOSE = FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =  
else
	HIDE = @
endif
MAKE = make -C
RM = rm -rf
MKDIR = mkdir -p
ERRIGNORE = 2>/dev/null

.PHONY: all clean fclean re lib

all: lib $(NAME)

$(NAME): $(OBJDIRS) $(OBJS)
	$(HIDE)echo $(MAKEFILE_NAME): "Linking \t ->" $@
	$(HIDE)$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

-include $(DEPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo $(MAKEFILE_NAME): "Building \t ->" $@
	$(HIDE)$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD

$(OBJDIRS):
	@echo $(MAKEFILE_NAME): "Making \t ->" $(OBJDIRS)
	$(HIDE)$(MKDIR) $(OBJDIRS) $(ERRIGNORE)

lib:
	$(HIDE)$(MAKE) $(LIBDIR)

clean:
	$(HIDE)$(MAKE) $(LIBDIR) clean
	$(HIDE)$(RM) $(OBJDIR) $(ERRIGNORE)
	@echo $(MAKEFILE_NAME): Clean done !

fclean:
	$(HIDE)$(MAKE) $(LIBDIR) clean
	$(HIDE)$(RM) $(OBJDIR) $(ERRIGNORE)
	$(HIDE)$(RM) $(NAME) $(ERRIGNORE)
	@echo $(MAKEFILE_NAME): Fclean done !

re: fclean all