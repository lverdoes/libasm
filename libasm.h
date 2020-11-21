/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 09:37:01 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/21 13:56:46 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sys/types.h"

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char 				*ft_strdup(const char *s1);
int					ft_strcmp(const char *s1, const char *s2);
ssize_t				ft_read(int fildes, void *buf, size_t nbyte);
ssize_t				ft_write(int fildes, const void *buf, size_t nbyte);

typedef struct      s_list{
    void            *data;
    struct s_list   *next;
}                   t_list;

int                 ft_lst_size(t_list *head);
int                 ft_atoi_base(char *str);

// • ft_list_push_front (like the one in the piscine)
// • ft_list_sort (like the one in the piscine)
// • ft_list_remove_if (like the one in the piscine)