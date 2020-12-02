/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_list_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 21:36:22 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/02 22:49:58 by lverdoes      ########   odam.nl         */
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
	printf("\nft_list_sort:\n\n");
	
	t_list *head = NULL;
	
	head = 				  ft_lstnew(strdup("b"));
	ft_lstadd_back(&head, ft_lstnew(strdup("d")));
	ft_lstadd_back(&head, ft_lstnew(strdup("e")));
	ft_lstadd_back(&head, ft_lstnew(strdup("a")));
	ft_lstadd_back(&head, ft_lstnew(strdup("c")));

	printf("list is unsorted:\n\n");
	print_list(head);
	ft_list_sort(&head, ft_strcmp);
	
	printf("list is sorted:\n\n");
	print_list(head);
}