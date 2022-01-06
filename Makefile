NAME        =    ft_containers

SRCS        =    main/test_vector.cpp

OBJS        =    ${SRCS:.cpp=.o}

INCLUDES    =   .

HEADER      =	Containers/Vector.hpp Containers/Stack.hpp  Containers/Map.hpp  Containers/Set.hpp \
 				Iterators/iterator.hpp Iterators/reverse_iterator.hpp Iterators/random_access_iterator.hpp \
 				Iterators/iterator_traits.hpp Iterators/Others.hpp Containers/RedBlackTree/RBTree.hpp \
 				Containers/RedBlackTree/tree_iterator.hpp Containers/RedBlackTree/Node.hpp

CC			=    clang++

CPPFLAGS	=	-Wall -Wextra -Werror #-g3 -fsanitize=address

RM			=	rm -f

%.o:		%.cpp ${INCLUDES}/${HEADER}
			${CC} ${CPPFLAGS} -c $< -o ${<:.cpp=.o} -I ${INCLUDES}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CPPFLAGS} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re .c.o
