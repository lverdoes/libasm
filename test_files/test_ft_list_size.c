/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_list_size.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:34:15 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/21 19:59:33 by lverdoes      ########   odam.nl         */
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
	printf("end\n");
}

void    test_ft_list_size(void)
{
    t_list *head = NULL;

	printf("\nft_list_size:\n\n");
    
    
    printf("\tTest %d:", 0);
    if (ft_list_size(head) == ft_lstsize(head))
        printf("\t[OK]\n");
    else
        printf("\t[FAIL]\n");
        
    printf("\tTest %d:", 1); 
    ft_lstadd_back(&head, ft_lstnew("hoi1"));
    if (ft_list_size(head) == ft_lstsize(head))
        printf("\t[OK]\n");
    else
        printf("\t[FAIL]\n");

    printf("\tTest %d:", 2); 
    ft_lstadd_back(&head, ft_lstnew("hoi2"));
    if (ft_list_size(head) == ft_lstsize(head))
        printf("\t[OK]\n");
    else
        printf("\t[FAIL]\n");

    printf("\tTest %d:", 3); 
    ft_lstadd_back(&head, ft_lstnew("hoi3"));
    if (ft_list_size(head) == ft_lstsize(head))
        printf("\t[OK]\n");
    else
        printf("\t[FAIL]\n");
	
    printf("\tTest %d:", 4); 
    ft_lstadd_back(&head, ft_lstnew("hoi4"));
    if (ft_list_size(head) == ft_lstsize(head))
        printf("\t[OK]\n");
    else
        printf("\t[FAIL]\n");
    printf("\n");
}
