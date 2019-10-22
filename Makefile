###############################################################################
#                                                                             #
# Makefile                                                                    #
#                                                                             #
###############################################################################

TARGET = ft_ssl
SRCDIR = src
OBJDIR = build

MAKEFILE_NAME = Makefile-$(lastword $(subst /, ,$(TARGET)))

CC = gcc
CFLAGS = -ggdb -g3
LDFLAGS = -Llib/libft 
LDLIBS = -lft 
SUBDIR = \
				md5 \
				sha1 \
				sha256 \
				ssl \
				ssl_utils
SUBFILE = \
				md5/ft_md5.c \
				md5/ft_md5_final.c \
				md5/ft_md5_padding.c \
				md5/ft_md5_update.c \
				sha1/ft_sha1.c \
				sha1/ft_sha1_final.c \
				sha1/ft_sha1_padding.c \
				sha1/ft_sha1_update.c \
				sha256/ft_sha256.c \
				sha256/ft_sha256_final.c \
				sha256/ft_sha256_padding.c \
				sha256/ft_sha256_sigma.c \
				sha256/ft_sha256_update.c \
				ssl/ft_ssl.c \
				ssl/ft_ssl_parse.c \
				ssl/ft_ssl_shell.c \
				ssl/ft_ssl_init.c \
				ssl/ft_ssl_error.c \
				ssl/ft_ssl_usage.c \
				ssl_utils/ft_ssl_rotate.c \
				ssl_utils/ft_ssl_show.c \
				ssl_utils/ft_ssl_size.c \
				ssl_utils/ft_ssl_swap.c \
				ssl_utils/hexdump.c

SRCDIRS = $(foreach dir, $(SUBDIR), $(addprefix $(SRCDIR)/, $(dir)))
OBJDIRS = $(foreach dir, $(SUBDIR), $(addprefix $(OBJDIR)/, $(dir)))
INCLUDES = $(foreach dir, $(SRCDIRS), $(addprefix -I, $(dir)))

VPATH = $(SRCDIRS)
SRCS = $(foreach file, $(SUBFILE), $(addprefix $(SRCDIR)/, $(file)))
OBJS := $(subst $(SRCDIR),$(OBJDIR),$(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

VERBOSE = false
ifeq ($(VERBOSE),TRUE)
	HIDE =  
else
	HIDE = @
endif
MAKE = make -C
RM = rm -rf 
RMDIR = rm -rf 
MKDIR = mkdir -p
ERRIGNORE = 2>/dev/null
SEP=/
PSEP = $(strip $(SEP))

.PHONY: all directories clean fclean re lib

all: directories lib $(TARGET)

$(TARGET): $(OBJS)
	$(HIDE)echo $(MAKEFILE_NAME): Linking $@
	$(HIDE)$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS)  -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo $(MAKEFILE_NAME): Building $@
	$(HIDE)$(CC) $(CFLAGS) -c $(INCLUDES) -o $@ $< -MMD

directories:
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(OBJDIRS)) $(ERRIGNORE)

lib:
	$(HIDE)$(MAKE) lib/libft 

clean:
	$(HIDE)$(RMDIR) $(subst /,$(PSEP),$(OBJDIRS)) $(ERRIGNORE)
	@echo $(MAKEFILE_NAME): Build cleaning done !

fclean: clean
	$(HIDE)$(RM) $(TARGET) $(ERRIGNORE)
	@echo $(MAKEFILE_NAME): Bin cleaning done !

re: fclean all