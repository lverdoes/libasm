/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_list_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 21:36:22 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/23 21:42:30 by lverdoes      ########   odam.nl         */
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
	printf("\nend of list\n\n");
}

void    test_ft_list_sort(void)
{
	t_list *head = ft_lstnew(strdup("bbhead"));
	ft_lstadd_back(&head, ft_lstnew(strdup("bbback")));
	printf("head = [%p]\n", head);
	ft_list_push_front(&head, strdup("bbbfrontpush"));
	printf("head = [%p]\n", head);
	
	print_list(head);
	ft_list_sort(&head, ft_strcmp);
	print_list(head);
}