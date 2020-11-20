# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/09/29 13:35:41 by lverdoes      #+#    #+#                  #
#    Updated: 2020/11/20 23:30:33 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCDIR = src/
OBJDIR = obj/

SRC = \
	ft_strlen.o \
	ft_strcpy.o \
	ft_strcmp.o \
	ft_strdup.o \
	ft_read.o \
	ft_write.o
	
OBJ = $(addprefix $(OBJDIR), $(SRC:.s=.o))

CC = gcc

FLAGS = -Wall -Wextra -Werror

NASM = nasm -f macho64

UNUSED = -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function

INCLUDES = libasm.h

$(OBJDIR)%.o: $(SRCDIR)%.s
	@mkdir -p obj
	$(NASM) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean untest
	rm -f $(NAME)
	rm -f test
	rm -f test_bonus
	rm -rf objs

re: fclean all

.PHONY: all clean fclean re bonus

test: all untest
	@$(CC) $(FLAGS) $(UNUSED) $(NAME) -o test ./test_files/*.c
	@touch ./test_files/normal_test
	@touch ./test_files/more_write_than_read_chars
	@mkdir -p ./test_files/'.dir'
	@touch ./test_files/NO_PERMISSION
	@chmod 001 ./test_files/NO_PERMISSION
	@./test
	@make untest

untest:	
	@rm -rf test 
	@rm -rf ./test_files/normal_test
	@rm -rf ./test_files/more_write_than_read_chars
	@rm -rf ./test_files/file_does_not_exist
	@rm -rf ./test_files/.dir
	@rm -rf ./test_files/NO_PERMISSION
