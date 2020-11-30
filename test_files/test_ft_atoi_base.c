/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi_base.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 13:06:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/30 21:13:51 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

/*
**  Write a function that converts the initial portion of the string 
**  pointed by str to int representation.
**
**  •	str is in a specific base given as a second parameter.
**  • 	excepted the base rule, the function should work exactly like ft_atoi.
**  • 	If there’s an invalid argument, the function should return 0.
**		Examples of invalid arguments :
**
**  		◦ base is empty or size of 1;
**  		◦ base contains the same character twice ;
**  		◦ base contains + or - or whitespaces;
**
** 	• 	Here’s how it should be prototyped :
**
** 			int ft_atoi_base(char *str, char *base);
*/


void	test_ft_atoi_base(void)
{
	int tests = 13;
	char *str[tests];
	char *base[tests];
	
	str[0] = ft_strdup("5");
	base[0] = ft_strdup("0123456789");
	
	str[1] = ft_strdup("a");
	base[1] = ft_strdup("0123456789abcdef");
	
	str[2] = ft_strdup("ff");
	base[2] = ft_strdup("0123456789abcdef");
	
	str[3] = ft_strdup("a");
	base[3] = ft_strdup("abcdefghijklmnopqrstuvwxyz");
	
	str[4] = ft_strdup("z");
	base[4] = ft_strdup("abcdefghijklmnopqrstuvwxyz");
	
	str[5] = ft_strdup("az");
	base[5] = ft_strdup("abcdefghijklmnopqrstuvwxyz");
	
	str[6] = ft_strdup("aza");
	base[6] = ft_strdup("abcdefghijklmnopqrstuvwxyz");
	
	str[7] = ft_strdup("\t  -10");
	base[7] = ft_strdup("0123456789");
	
	str[8] = ft_strdup("\t  -+10");
	base[8] = ft_strdup("0123456789");
	
	str[9] = ft_strdup("wat?");
	base[9] = ft_strdup("0123456789");
	
	str[10] = ft_strdup("1001");
	base[10] = ft_strdup("012");
	
	str[11] = ft_strdup("314");
	base[11] = ft_strdup("314");
	
	str[12] = ft_strdup("114");
	base[12] = ft_strdup("314");
	

	int i = 0;
	while (i < tests)
	{
		printf("\nTest [%.2d]:\n", i);
		printf("str  = [%s]\nbase = [%s]\nmine = [%d]\nreal = [%d]\n", \
			str[i], base[i], ft_atoi_base(str[i], base[i]), qb1t0_atoi_base(str[i], base[i]));
		i++;
	}
}
