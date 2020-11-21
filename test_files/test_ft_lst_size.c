/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lst_size.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:34:15 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/21 14:50:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

void    print_list(t_list *head)
{
    t_list *tmp;
    
    tmp = head;
	printf("start\n");
    while (tmp)
    {
        printf("data = [%s]\n", tmp->data);
        tmp = tmp->next;
    }
	printf("list size = [%d]\n", ft_lst_size(head));
	printf("end\n");
}

void    test_ft_lst_size(void)
{
    t_list *head;

    head = ft_lstnew("hoi0");
    print_list(head);
	
    ft_lstadd_back(&head, ft_lstnew("hoi1"));
    print_list(head);
    ft_lstadd_back(&head, ft_lstnew("hoi2"));
    print_list(head);
    ft_lstadd_back(&head, ft_lstnew("hoi3"));
    print_list(head);
}
