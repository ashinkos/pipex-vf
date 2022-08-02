NAME= pipex
SRC = ft_strlen.c ft_putstr.c ft_strlcpy.c ft_split.c ft_strnstr.c ft_strncmp.c \
	ft_strjoin.c ft_strdup.c pipex_utils.c pipex.c  \

#BONUS_NAME = 
#SRC_BONUS = 

CC = cc
FLAGS= -Wall -Werror -Wextra
PARA  = -c 

OBJ= $(SRC:.c=.o)

#OBJ_BONUS= $(SRC_BONUS:.c=.o)

%.o : %.c 
	$(CC) $(PARA) $(FLAGS) $<  -o $@


all: $(NAME)
	
$(NAME): $(OBJ)
		${CC} $(OBJ) -o ${NAME}

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

#bonus: $(OBJ_BONUS)
#	$(CC)   $(OBJ_BONUS) -o $(BONUS_NAME)