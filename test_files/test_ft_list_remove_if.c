/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_list_remove_if.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 11:45:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/02 22:49:42 by lverdoes      ########   odam.nl         */
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

void	test_ft_list_remove_if(void)
{
	printf("\nft_list_remove:\n\n");
	
//		make a list of strings

	t_list *head = ft_lstnew(strdup("head 00"));
	ft_lstadd_back(&head, ft_lstnew(strdup("node 01")));
	ft_lstadd_back(&head, ft_lstnew(strdup("node 02")));
	ft_lstadd_back(&head, ft_lstnew(strdup("Lars")));
	ft_lstadd_back(&head, ft_lstnew(strdup("Lars")));
	ft_lstadd_back(&head, ft_lstnew(strdup("node 03")));
	ft_lstadd_back(&head, ft_lstnew(strdup("node 04")));
	ft_lstadd_back(&head, ft_lstnew(strdup("Lars")));
	ft_lstadd_back(&head, ft_lstnew(strdup("Lars")));
	ft_lstadd_back(&head, ft_lstnew(strdup("node 05")));
	ft_lstadd_back(&head, ft_lstnew(strdup("node 06")));

//		print the list
	printf("List with all nodes:\n");
	print_list(head);
	printf("\n");

//		remove elements equal to Lars
	ft_list_remove_if(&head, "Lars", ft_strcmp);

//		print the list again, to show remove_if works
	printf("List with removed nodes:\n");
	print_list(head);
	printf("\n");
}
