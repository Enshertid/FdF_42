NAME = libft.a

NAME_DEBUG = glibft.a

SRCS =	ft_abs.c								\
		error.c									\
		ft_swap.c								\
		ft_dpow.c								\
		ft_ipow.c								\
		ft_arrdel.c								\
		ft_sizeof_num.c							\
		ft_print_bits.c							\
												\
ft_tolower.c	ft_toupper.c					\
												\
												\
ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
ft_isdigit.c	ft_isprint.c	ft_isspace.c	\
												\
												\
ft_putnbr.c		ft_putstr.c		ft_putchar.c	\
ft_putendl.c	ft_putnbr_fd.c	ft_putstr_fd.c	\
ft_putendl_fd.c	ft_putchar_fd.c					\
												\
												\
ft_atoi.c		ft_itoa.c		ft_mitoa.c		\
												\
												\
ft_min.c	ft_max.c	ft_maxn.c	ft_minn.c	\
												\
												\
ft_memcmp.c		ft_memset.c		ft_memcpy.c		\
ft_memchr.c		ft_memccpy.c	ft_memmove.c	\
ft_memalloc.c	ft_memnchr.c	ft_memrchr.c	\
ft_memrnchr.c									\
												\
												\
ft_strrev.c		ft_strcmp.c		ft_strdel.c		\
ft_strcpy.c		ft_strlen.c		ft_strstr.c		\
ft_strchr.c		ft_strsub.c		ft_strequ.c		\
ft_strnew.c		ft_strmap.c		ft_strcat.c		\
ft_strdup.c		ft_strclr.c		ft_striter.c	\
ft_strnequ.c	ft_strncmp.c	ft_strncat.c	\
ft_strjoin.c	ft_strrchr.c	ft_strnstr.c	\
ft_strlcat.c	ft_strmapi.c	ft_strncpy.c	\
ft_strtrim.c	ft_striteri.c	ft_strsplit.c	\
												\
												\
ft_lstnew.c		ft_lstmap.c		ft_lstadd.c		\
ft_lstpop.c		ft_lstiter.c	ft_lstsize.c	\
ft_lstpurge.c	ft_lstdelete.c	ft_lstextend.c	\
ft_lstdelone.c	ft_lstappend.c	ft_lstpopback.c	\
												\
												\
ft_dlstnew.c	ft_dlstnew.c	ft_dlstiter.c	\
ft_dlstsize.c	ft_dlstpurge.c	ft_dlstappend.c	\
ft_get_next_line.c\
ft_mod_num.c




OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -Iincludes


$(NAME):
	@gcc $(FLAGS) -c $(SRCS)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)


all: $(NAME)


clean:
	@rm -f *.o


fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_DEBUG)


re: fclean all




c: clean


f: fclean


g:
	@gcc -g $(FLAGS) -c $(SRCS)
	@ar rcs $(NAME_DEBUG) $(OBJ)
	@ranlib $(NAME_DEBUG)


t:
	@make
	@clear
	@gcc -Wall -Werror -Wextra main.c libft.a
	@clear
	@./a.out
