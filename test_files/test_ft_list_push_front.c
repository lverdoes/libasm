/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_list_push_front.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 17:51:55 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/29 13:34:18 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

static void    print_list(t_list *list)
{
	while (list)
	{
		printf("data = [%s] at [%p]\n", list->data, list->data);
		list = list->next;
	}
}

void    test_ft_list_push_front(void)
{
	t_list *head = NULL;
	
	head = ft_lstnew(strdup("first head"));
	ft_lstadd_back(&head, ft_lstnew(strdup("added to back")));
	ft_list_push_front(&head, strdup("new head"));
	print_list(head);
}
