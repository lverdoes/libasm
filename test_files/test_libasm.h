/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_libasm.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 11:25:29 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/21 14:40:54 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 32

//      mandatory part

void	test_ft_strlen(void);
void	test_ft_strcpy(void);
void	test_ft_strdup(void);
void	test_ft_strcmp(void);
void	test_ft_read(void);
void	test_ft_write(void);

//		bonus part

void	test_ft_lst_size(void);
//void	test_ft_atoi_base(char *str);


//		t_list utils

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
