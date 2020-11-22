/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 14:28:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/21 19:55:51 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

t_list  *ft_lstnew(void *data)
{
    t_list *list;
	
    list = calloc(1, sizeof(t_list));
    if (!list)
            return (NULL);
    list->data = data;
    list->next = NULL;
    return (list);
}

void    ft_lstadd_front(t_list **alst, t_list *new)
{
    if (!new)
            return ;
    new->next = *alst;
    *alst = new;
}

void    ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *list;
	
    list = *alst;
    if (list)
    {
        while (list->next)
                  list = list->next;
        list->next = new;
    }
    else
        ft_lstadd_front(alst, new);
}

int		ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
