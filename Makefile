CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
NAME = libft.a
AR = ar rcs
LIB = ranlib

SRCS = ft_printf.o

OBJS = ${SRCS:.c=.o}

######### Targets ########
all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

######### Clean ########
# Clean obj files (.o)
clean:
	${RM} ${OBJS}

# Clean obj and library (.o .a)
fclean: clean
	${RM} ${NAME}

# Re-Make the library
re: fclean all

# Dependency of header file for all obj
${OBJS}: libft.h

.PHONY: all clean fclean re