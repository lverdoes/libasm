/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strcpy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 11:26:16 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/20 14:31:06 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

void	test_ft_strcpy(void)
{
	printf("\nft_strcpy:\n\n");
	
	int tests = 8;
	char *src[tests];
	
	src[0] = "";
	src[1] = "a";
	src[2] = "22";
	src[3] = "333";
	src[4] = "hoiiii00012334556679000000fghflgkdfklgldkghoiiii00012334556679000000fghflgkdfklgldkghoiiii00012334556679000000fghflgkdfklgldkg";
	src[5] = "";
	src[6] = "\0\0nulls";
	src[7] = "\n\n\n\n\nnewlines";

	char *ft_dst[tests];
	char *dst[tests];
	int i = 0;
	while (i < tests)
	{
		printf("\tTest %d:", i);
		ft_dst[i] = malloc(strlen(src[i]) + 1);
		dst[i] = malloc(strlen(src[i]) + 1);
		if (!strcmp(ft_strcpy(ft_dst[i], src[i]), strcpy(dst[i], src[i])))
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
