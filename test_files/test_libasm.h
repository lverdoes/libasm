/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_libasm.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 11:25:29 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/20 23:05:36 by lverdoes      ########   odam.nl         */
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

void	test_ft_strlen(void);
void	test_ft_strcpy(void);
void	test_ft_strdup(void);
void	test_ft_strcmp(void);
void	test_ft_read(void);
void	test_ft_write(void);