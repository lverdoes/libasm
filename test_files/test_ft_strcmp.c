/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strcmp.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 11:32:40 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/20 22:14:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

void	test_ft_strcmp(void)
{
	printf("\nft_strcmp:\n\n");

	int tests = 8;
	char *str[tests];

	str[0] = "hoiiii00012334556679000000fghflgkdfklgldkg";
	str[1] = "\0";
	str[2] = "la\0\0\0hoi\0";
	str[3] = "\0L";
	str[4] = "hsdlfjsldjflsjdfjsdf\0\0\0\0jsdlfjsldjfsdfafjsldjflsjdfjsdf\0\0\0\0jsdlfjsld234234\n\n\n\n\n\ndfgdfgdgf";
	str[5] = "H";
	str[6] = "HH";
	str[7] = "HHH";
	 
	int	ret[2];
	int i = 0;
	int j;
	while (i < tests)
	{
		j = i;
		while (j < tests)
		{
			printf("\tTest %d.%d:", i, j);
			ret[0] = ft_strcmp(str[i], str[j] + 0);
			ret[1] = strcmp(str[i], str[j]);
			if (ret[0] == ret[1])
				printf("\t[OK]\n");
			else
			{
				printf("\t[FAIL]\n");
				printf("src = [%s] [%s]\n", str[i], str[j]);
				printf("ft_: [%d]\n", ret[0]);
				printf("man: [%d]\n\n", ret[1]);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}