/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 14:00:09 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/18 11:42:10 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void	test_ft_strlen(void)
{
	printf("\nft_strlen:\n\n");
	
	int i = 0;
	char *str[8];

	str[0] = "hoiiii00012334556679000000fghflgkdfklgldkg";
	str[1] = "\0";
	str[3] = "\0L";
	str[2] = "la\0\0\0hoi\0";
	str[4] = "hsdlfjsldjflsjdfjsdf\0\0\0\0jsdlfjsldjfsdfafjsldjflsjdfjsdf\0\0\0\0jsdlfjsld234234\n\n\n\n\n\ndfgdfgdgf";
	str[5] = "H";
	str[6] = "HH";
	str[7] = "HGH";
	 
	printf("\tTest %d:", i);
	if (ft_strlen(str[i]) == strlen(str[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");

	i++;
	printf("\tTest %d:", i);
	if (ft_strlen(str[i]) == strlen(str[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	
	i++;
	printf("\tTest %d:", i);
	if (ft_strlen(str[i]) == strlen(str[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	
	i++;
	printf("\tTest %d:", i);
	if (ft_strlen(str[i]) == strlen(str[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");

	i++;
	printf("\tTest %d:", i);
	if (ft_strlen(str[i]) == strlen(str[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");

	i++;
	printf("\tTest %d:", i);
	if (ft_strlen(str[i]) == strlen(str[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");

	i++;
	printf("\tTest %d:", i);
	if (ft_strlen(str[i]) == strlen(str[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");


	i++;
	printf("\tTest %d:", i);
	if (ft_strlen(str[i]) == strlen(str[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
}
static void	test_ft_strcpy(void)
{
	printf("\nft_strcpy:\n\n");
	
	int i = 0;
	char *ft_dst[8];
	char *dst[8];
	char *src[8];
	
	src[0] = "";
	src[1] = "a";
	src[2] = "22";
	src[3] = "333";
	src[4] = "hoiiii00012334556679000000fghflgkdfklgldkghoiiii00012334556679000000fghflgkdfklgldkghoiiii00012334556679000000fghflgkdfklgldkg";
	src[5] = "";
	src[6] = "\0\0";
	src[7] = "\n\n\n\n\nnew";
	
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	if (!strcmp(ft_strcpy(ft_dst[i], src[i]), strcpy(dst[i], src[i])))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);
	
	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	if (!strcmp(ft_strcpy(ft_dst[i], src[i]), strcpy(dst[i], src[i])))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);
	
	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	if (!strcmp(ft_strcpy(ft_dst[i], src[i]), strcpy(dst[i], src[i])))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);
	
	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	if (!strcmp(ft_strcpy(ft_dst[i], src[i]), strcpy(dst[i], src[i])))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);
	
	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	if (!strcmp(ft_strcpy(ft_dst[i], src[i]), strcpy(dst[i], src[i])))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);
	
	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	if (!strcmp(ft_strcpy(ft_dst[i], src[i]), strcpy(dst[i], src[i])))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);
	
	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	if (!strcmp(ft_strcpy(ft_dst[i], src[i]), strcpy(dst[i], src[i])))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);
	
	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	if (!strcmp(ft_strcpy(ft_dst[i], src[i]), strcpy(dst[i], src[i])))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);
}
static void	test_ft_strdup(void)
{
	printf("\nft_strdup:\n\n");
	
	int i = 0;
	char *ft_dst[8];
	char *dst[8];
	char *src[8];
	
	src[0] = "string";
	src[1] = "a";
	src[2] = "22";
	src[3] = "333";
	src[4] = "hoiiii00012334556679000000fghflgkdfklgldkghoiiii00012334556679000000fghflgkdfklgldkghoiiii00012334556679000000fghflgkdfklgldkg";
	src[5] = "something";
	src[6] = "\0\0";
	src[7] = "\n\n\n\n\nnew";
	
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	ft_dst[i] = ft_strdup(src[i]);
	dst [i] = strdup(src[i]); 
	if (!strcmp(ft_dst[i], dst[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);

	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	ft_dst[i] = ft_strdup(src[i]);
	dst [i] = strdup(src[i]); 
	if (!strcmp(ft_dst[i], dst[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);

	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	ft_dst[i] = ft_strdup(src[i]);
	dst [i] = strdup(src[i]); 
	if (!strcmp(ft_dst[i], dst[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);

	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	ft_dst[i] = ft_strdup(src[i]);
	dst [i] = strdup(src[i]); 
	if (!strcmp(ft_dst[i], dst[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);

	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	ft_dst[i] = ft_strdup(src[i]);
	dst [i] = strdup(src[i]); 
	if (!strcmp(ft_dst[i], dst[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);

	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	ft_dst[i] = ft_strdup(src[i]);
	dst [i] = strdup(src[i]); 
	if (!strcmp(ft_dst[i], dst[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);

	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	ft_dst[i] = ft_strdup(src[i]);
	dst [i] = strdup(src[i]); 
	if (!strcmp(ft_dst[i], dst[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);

	i++;
	ft_dst[i] = malloc(strlen(src[i]));
	dst[i] = malloc(strlen(src[i]));
	printf("\tTest %d:", i);
	ft_dst[i] = ft_strdup(src[i]);
	dst [i] = strdup(src[i]); 
	if (!strcmp(ft_dst[i], dst[i]))
		printf("\t\t[OK]\n");
	else
		printf("\t\t[FAIL]\n");
	free(ft_dst[i]);
	free(dst[i]);
}
static void	test_ft_strcmp(void)
{
	printf("\nft_strcmp:\n\n");
	
	int i = 0;
	int j;
	char *str[8];
	int	ret[2];

	str[0] = "hoiiii00012334556679000000fghflgkdfklgldkg";
	str[1] = "\0";
	str[2] = "la\0\0\0hoi\0";
	str[3] = "\0L";
	str[4] = "hsdlfjsldjflsjdfjsdf\0\0\0\0jsdlfjsldjfsdfafjsldjflsjdfjsdf\0\0\0\0jsdlfjsld234234\n\n\n\n\n\ndfgdfgdgf";
	str[5] = "H";
	str[6] = "HH";
	str[7] = "HHH";
	 
	while (i < 8)
	{
		j = i;
		printf("\tTest %d:", i);
		printf("\t\t");
		while (j < 8)
		{
			ret[0] = ft_strcmp(str[i], str[j]);
			ret[1] = strcmp(str[i], str[j]);
//			printf("ft_:[%d] man:[%d]\t", ret[0], ret[1]);
			//if (ft_strcmp(str[i], str[j]) == strcmp(str[i], str[j]))
			if (ret[0] == ret[1])
				printf("[OK]");
			else
				printf("[FAIL]");
			j++;
		}
		printf("\n");
		i++;
	}

}
static void	test_ft_read(void)
{
	printf("\nft_read:\n\n");
	
	int fd;
	char **buffer;
	int ret[2];
	int i = 0;
	int read_test = 6;
	char **filename = calloc(read_test + 1, sizeof(char *));
	filename[0] = strdup("./read_files/ls");
	filename[1] = strdup("./read_files/lswc");
	filename[2] = strdup("./read_files/pwd");
	filename[3] = strdup("./read_files/DOES_NOT_EXIST");
	filename[4] = strdup("");
	filename[5] = strdup("./read_files/.dir");
	
	while (i < read_test)
	{
		buffer = calloc(2 + 1, sizeof(char *));
		buffer[0] = calloc(128 + 1, sizeof(char));
		buffer[1] = calloc(128 + 1, sizeof(char));
		fd = open(filename[i], O_RDONLY);
		ret[0] = ft_read(fd, buffer[0], 128);
//		printf("errno[%d]-[%s]\n", errno, strerror(errno)); errno = 0;
		close(fd);
		fd = open(filename[i], O_RDONLY);
		ret[1] = read(fd, buffer[1], 128);
//		printf("errno[%d]-[%s]\n", errno, strerror(errno)); errno = 0;
		close(fd);
		printf("\tTest [%d]:", i);
		printf("ft_ read: [%d]\t\t", ret[0]);
		printf("man read: [%d]\n", ret[1]);
		if (!strncmp(buffer[0], buffer[1], 128) && ret[0] == ret[1])
			printf("\t[OK]\n");
		else
			printf("\t[FAIL]\n");
		free(buffer[1]);
		free(buffer[0]);
		free(buffer);
		i++;
	}
}
static void	test_ft_write(void)
{
	printf("\nft_write:\n\n");
	
	int fd;
	int ret[2];
	int i = 0;
	int write_test = 5;
	char **filename = calloc(write_test + 1, sizeof(char *));
	filename[0] = strdup("./test_files/write_files/hi_there");
	filename[1] = strdup("./test_files/write_files/DOES_NOT_EXIST");
	filename[2] = strdup("");
	filename[3] = strdup("./test_files/write_files/.dir");
	filename[4] = strdup("./test_files/write_files/NO_PERMISSION");
	
	while (i < write_test)
	{
		fd = open(filename[i], O_RDWR);
//		printf("fd = %d\n", fd);
		ret[0] = ft_write(fd, filename[i], strlen(filename[i]));
//		system("cat ./test_files/write_files/hi_there");
		close(fd);
		fd = open(filename[i], O_RDONLY);
		char *buffer = calloc(129, sizeof(char));
		if (i !=4)
			ret[1] = read(fd, buffer, 128);
		else
			ret[1] = -1;
		close(fd);
		printf("\tTest [%d]:", i);
//		printf("errno[%d]-[%s]\n", errno, strerror(errno));
		printf("ft_ write: [%d]\t\t", ret[0]);
		printf("man write: [%d]\n", ret[1]);
		if ((!strncmp(buffer, filename[i], 129) && ret[0] == ret[1]) || (ret[0] == ret[1] && ret[0] == -1))
			printf("\t[OK]\n");
		else
			printf("\t[FAIL]\n");
		free(buffer);
		i++;
	}
}

int main(void)
{
//	test_ft_strlen();
//	test_ft_strcpy();
//	test_ft_strdup();
//	test_ft_strcmp();
//	test_ft_read();
//	test_ft_write();
    return (0);
}
