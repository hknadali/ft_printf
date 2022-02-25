NAME	=	libftprintf.a

CC	=	@gcc
CFLAGS	=	-Wall -Wextra -Werror

RM	=	@rm -f

AR	=	@ar
ARFLAGS	=	rcs

SOURCES		=	./ft_printf.c 			\
				./ft_printf_formats.c 	\
				./ft_printf_formats2.c 	\
				./ft_printf_utils.c

OBJECTS	=	$(SOURCES:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)
			@echo "[LIBFTPRINTF.A CREATED!]"

clean:
		$(RM) $(OBJECTS)

fclean:	clean
		$(RM) $(NAME)
		@echo "[LIBFTPRINTF.A DELETED!]"

re:	fclean all

.PHONY:	all clean fclean re
