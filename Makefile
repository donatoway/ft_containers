SRCS			= tester/vector/main.cpp
SRCS2			= tester/map/main.cpp
SRCS3			= tester/stack/main.cpp

OBJ				= $(SRCS:.cpp=.o)
OBJ2			= $(SRCS2:.cpp=.o)
OBJ3			= $(SRCS3:.cpp=.o)

CC				= clang++
RM				= rm -f
CFLAGS			= -std=c++98 -Wall -Wextra -Werror
NAME			= vect_test
NAME2			= map_test
NAME3			= stack_test

%.o:			%.cpp
				@$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)		$(NAME2)	$(NAME3)


$(NAME):		$(OBJ)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
$(NAME2):		$(OBJ2)
				@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)
$(NAME3):		$(OBJ3)
				@$(CC) $(CFLAGS) -o $(NAME3) $(OBJ3)

clean:
				@$(RM) $(OBJ) $(OBJ2) $(OBJ3)

fclean:			clean
				@$(RM) $(NAME) $(NAME2) $(NAME3)

re:				fclean $(NAME) $(NAME2) $(NAME3)

g:				fclean $(OBJS)
				$(CC) -g -o $(NAME) $(NAME2) $(NAME3) ${SRCS} ${SRCS2} ${SRCS3} ${LIBS} 

.PHONY:			all clean fclean re g