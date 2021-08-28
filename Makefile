NAMEC =		checker

NAMEP =		push_swap

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

SRC_C =		c/analysis.c c/apply.c c/check.c \
			c/create_tab.c c/end.c c/functions_r.c \
			c/functions_sp.c c/main.c c/split_join.c \
			c/utils.c

SRC_P =		ps/analysis.c ps/check.c ps/create_tab.c \
			ps/functions_r.c ps/functions_sp.c ps/main.c \
			ps/rotate_right.c ps/small.c ps/utils_big.c \
			ps/utils.c

OBJ_C =		${SRC_C:.c=.o}

OBJ_P =		${SRC_P:.c=.o}


all:		${NAMEC} ${NAMEP}

${NAMEC}:	${OBJ_C}
			${CC} ${FLAGS} ${OBJ_C} -o ${NAMEC}

${NAMEP}:	${OBJ_P}
			${CC} ${FLAGS} ${OBJ_P} -o ${NAMEP}

.c.o:
			${CC} ${FLAGS} -c $< -o $@

clean:
			rm -f ${OBJ_C} ${OBJ_P}

fclean:		clean
			rm -f ${NAMEC} ${NAMEP}

re:			fclean all

.PHONY :	all clean fclean re
