###############################################################################
#                                                                             #
# Makefile                                                                    #
#                                                                             #
###############################################################################

TARGET = ./libft.a
PROJDIR = .
SRCDIR = ./src
OBJDIR = ./build

MAKEFILE_NAME = Makefile-$(lastword $(subst /, ,$(TARGET)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
SUBDIR = \
				gnl \
				is \
				lst \
				mem \
				put \
				str \
				to
SUBFILE = \
				mem/memchr.c \
				mem/memcmp.c \
				mem/memmove.c \
				mem/memcpy.c \
				mem/memdel.c \
				mem/memccpy.c \
				mem/memalloc.c \
				mem/memset.c \
				lst/lstmap.c \
				lst/lstadd.c \
				lst/lstdelone.c \
				lst/lstnew.c \
				lst/lstdel.c \
				lst/lstiter.c \
				put/putendlpad.c \
				put/putstrpad_fd.c \
				put/putstrpad.c \
				put/putendlpad_fd.c \
				put/putchar_fd.c \
				put/putnbr_fd.c \
				put/puthexa.c \
				put/puthexa_fd.c \
				put/putnbrendl_fd.c \
				put/putnbrendl.c \
				put/putstr_fd.c \
				put/puthexapad_fd.c \
				put/putendl.c \
				put/puthexapad.c \
				put/putendl_fd.c \
				put/putchar.c \
				put/putnbr.c \
				put/putstr.c \
				is/isspace.c \
				is/islower.c \
				is/isalpha.c \
				is/isblank.c \
				is/isalnum.c \
				is/isprint.c \
				is/isupper.c \
				is/isascii.c \
				is/isdigit.c \
				gnl/get_next_line.c \
				to/toupper.c \
				to/atoi.c \
				to/tolower.c \
				to/itoa.c \
				to/nbrlen.c \
				str/strcpy.c \
				str/strmap.c \
				str/strncat.c \
				str/strncpy.c \
				str/strncmp.c \
				str/strnew.c \
				str/strequ.c \
				str/strdup.c \
				str/strcat.c \
				str/strnstr.c \
				str/strdel.c \
				str/stradup.c \
				str/strlen.c \
				str/strsub.c \
				str/bzero.c \
				str/striteri.c \
				str/stradel.c \
				str/strsplit.c \
				str/strrev.c \
				str/striter.c \
				str/strnequ.c \
				str/stralen.c \
				str/strjoin.c \
				str/strchr.c \
				str/strtrim.c \
				str/strrchr.c \
				str/strcmp.c \
				str/wordcount.c \
				str/strlcat.c \
				str/strstr.c \
				str/strmapi.c \
				str/strclr.c \
				str/wordlen.c

SRCDIRS = $(foreach dir, $(SUBDIR), $(addprefix $(SRCDIR)/, $(dir)))
OBJDIRS = $(foreach dir, $(SUBDIR), $(addprefix $(OBJDIR)/, $(dir)))
INCLUDES = $(foreach dir, $(SRCDIRS), $(addprefix -I, $(dir)))

VPATH = $(SRCDIRS)
SRCS = $(foreach file, $(SUBFILE), $(addprefix $(SRCDIR)/, $(file)))
OBJS = $(subst $(SRCDIR),$(OBJDIR),$(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

VERBOSE = FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =  
else
	HIDE = @
endif
RM = rm -rf
RMDIR = rm -rf 
MKDIR = mkdir -p
ERRIGNORE = 2>/dev/null
SEP=/
PSEP = $(strip $(SEP))

.PHONY: all directories clean fclean re 

all: directories $(TARGET)

$(TARGET) : $(OBJS)
	$(HIDE)echo $(MAKEFILE_NAME): Linking library $@
	$(HIDE)ar rcs $(TARGET) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo $(MAKEFILE_NAME): Building $@
	$(HIDE)$(CC) $(CFLAGS) -c $(INCLUDES) -o $@ $< -MMD

directories:
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(OBJDIRS)) $(ERRIGNORE)

clean:
	$(HIDE)$(RMDIR) $(subst /,$(PSEP),$(OBJDIRS)) $(ERRIGNORE)
	@echo $(MAKEFILE_NAME): Build done !

fclean: clean
	$(HIDE)$(RM) $(TARGET) $(ERRIGNORE)
	@echo $(MAKEFILE_NAME): Bin cleaning done !

re: fclean all
