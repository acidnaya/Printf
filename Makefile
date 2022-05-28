SOURCES = ft_printf.c
SOURCES += ft_ftoa.c
SOURCES += ft_width.c
SOURCES += ft_precision.c
SOURCES += ft_itoa_unsigned.c
SOURCES += structs.c
SOURCES += ft_itoa_base.c
SOURCES += apply_flags.c
SOURCES += print_pointer.c
SOURCES += delete.c
SOURCES += checking_length.c
SOURCES += ft_atoi.c
SOURCES += ft_itoa.c
SOURCES += ft_putchar.c
SOURCES += ft_putendl.c
SOURCES += ft_putstr.c
SOURCES += ft_strchr.c
SOURCES += ft_strclr.c
SOURCES += ft_strdup.c
SOURCES += ft_strjoin.c
SOURCES += ft_strlen.c
SOURCES += ft_strnew.c
SOURCES += ft_strsub.c
SOURCES += check_type.c
SOURCES += ft_memcpy.c
SOURCES += ft_putstr_unsigned.c
SOURCES += unicode.c
SOURCES += ft_get_flags.c
SOURCES += ft_agregator.c

OBJECTS = $(SOURCES:.c=.o)

NAME = libftprintf.a

APP = ft_printf

all: $(NAME)

$(NAME):
	@gcc -c $(SOURCES) -I ft_printf.h
	@ar rc $(NAME) $(OBJECTS)
clean:
	@rm -f $(OBJECTS)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(APP)
re: fclean all