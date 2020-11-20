/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strlen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 11:23:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/20 11:51:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

void	test_ft_strlen(void)
{
	printf("\nft_strlen:\n\n");
	
	int		tests = 8;
	char	*src[tests];

	src[0] = "hoiiii00012334556679000000fghflgkdfklgldkg";
	src[1] = "\0";
	src[3] = "\0L";
	src[2] = "la\0\0\0hoi\0";
	src[4] = "hsdlfjsldjflsjdfjsdf\0\0\0\0jsdlfjsldjfsdfafjsldjflsjdfjsdf\0\0\0\0jsdlfjsld234234\n\n\n\n\n\ndfgdfgdgf";
	src[5] = "H";
	src[6] = "HH";
	src[7] = "HGH";

	int i = 0;
	while (i < tests)
	{
		printf("\tTest %d:", i);
		if (ft_strlen(src[i]) == strlen(src[i]))
			printf("\t\t[OK]\n");
		else
		{
			printf("\t\t[FAIL]\n");
			printf("ft_: [%zu]\n", ft_strlen(src[i]));
			printf("man: [%zu]\n\n", strlen(src[i]));		
		}
		i++;
	}
	printf("\n");
}