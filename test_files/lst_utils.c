/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 14:28:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/30 18:07:13 by lverdoes      ########   odam.nl         */
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

static int qb1t0_isblank(int c) 
{
  return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
	  || c == ' ');
}


static int qb1t0_ind(char c, const char *str)
{
  int i;

  i = 0;
  while (str[i] && str[i] != c)
    i++;
  return (i);
}

static int qb1t0_strlen(const char *s, int a)
{
  int i = 0;
  while (s[i])
    i++;
  return (i);
}

int qb1t0_atoi_base(const char *nptr, const char *base)
{
  int result;
  int neg;
  int blen;

  result = 0;
  blen = qb1t0_strlen(base, 0);
  if (blen < 2)
    return (0);
  while (qb1t0_isblank(*nptr))
    nptr++;
  neg = *nptr == '-';
  if (*nptr == '+' || *nptr == '-')
    nptr++;
  while (qb1t0_ind(*nptr, base) < blen)
    result = result * blen - qb1t0_ind(*nptr++, base);
  return (neg ? result : -result);
}