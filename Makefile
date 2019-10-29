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
				ssl \
				ssl_dgst \
				ssl_cipher \
				ssl_stdrd
SUBFILE = \
				ssl/ft_ssl.c \
				ssl/ft_ssl_dispatch.c \
				ssl/ft_ssl_usage.c \
				ssl_dgst/ft_ssl_dgst.c \
				ssl_dgst/ft_ssl_dgst_dispatch.c \
				ssl_dgst/ft_ssl_dgst_usage.c \
				ssl_cipher/ft_ssl_cipher.c \
				ssl_cipher/ft_ssl_cipher_dispatch.c \
				ssl_cipher/ft_ssl_cipher_usage.c \
				ssl_stdrd/ft_ssl_stdrd.c \
				ssl_stdrd/ft_ssl_stdrd_dispatch.c \
				ssl_stdrd/ft_ssl_stdrd_usage.c \

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

-include $(DEPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo $(MAKEFILE_NAME): Building $(@)
	$(HIDE)$(CC) $(CFLAGS) -c $(INCLUDES) -o $(@) $(<) -MMD

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