/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strdup.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 11:28:36 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/20 14:30:49 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

void	test_ft_strdup(void)
{
	printf("\nft_strdup:\n\n");
	
	int tests = 8;
	char *src[tests];
	
	src[0] = "string";
	src[1] = "a";
	src[2] = "22";
	src[3] = "333";
	src[4] = "hoiiii00012334556679000000fghflgkdfklgldkghoiiii00012334556679000000fghflgkdfklgldkghoiiii00012334556679000000fghflgkdfklgldkg";
	src[5] = "something";
	src[6] = "\0\0";
	src[7] = "\n\n\n\n\nnew";
	
	char *ft_dst[tests];
	char *dst[tests];
	int i = 0;
	while (i < tests)
	{
		printf("\tTest %d:", i);
		ft_dst[i] = ft_strdup(src[i]);
		dst [i] = strdup(src[i]);
		if (!strcmp(ft_dst[i], dst[i]))
			printf("\t\t[OK]\n");
		else
		{
			printf("\t\t[FAIL]\n");
			printf("src: [%s]\n", src[i]);
			printf("ft_: [%s]\n", ft_dst[i]);
			printf("man: [%s]\n\n", dst[i]);
		}
		free(ft_dst[i]);
		free(dst[i]);
		i++;
	}
	printf("\n");
}
