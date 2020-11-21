/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tol <ivan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 12:15:49 by ivan-tol      #+#    #+#                 */
/*   Updated: 2020/07/20 12:15:49 by ivan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

static void		test_ft_strlen(void)
{
	int		ret1;
	int		ret2;
	char	s1[] = "123456789";
	char	s2[] = " ";
	char	s3[] = "01001abcd\t\t\0123";
	char	s4[] = "Hello world!";
	char	s5[] = "\0";
	char	s6[] = "";
	char	s7[] = "01";
	char	s8[] = "01\0tyuiop";

	ret1 = strlen(s1);
	ret2 = ft_strlen(s1);
	printf("_____ft_strlen_____\n");
	printf("strlen : \t[%d]\nft_strlen : \t[%d]\n\n", ret1, ret2);
	if ((ft_strlen(s1) == strlen(s1)) &&
	(ft_strlen(s2) == strlen(s2)) &&
	(ft_strlen(s3) == strlen(s3)) &&
	(ft_strlen(s4) == strlen(s4)) &&
	(ft_strlen(s5) == strlen(s5)) &&
	(ft_strlen(s6) == strlen(s6)) &&
	(ft_strlen(s7) == strlen(s7)) &&
	(ft_strlen(s8) == strlen(s8)))
		printf("ft_strlen\t[OK]\n\n");
	else
		printf("ft_strlen\t[ERROR]\n\n");
}

static void		test_ft_strcpy(void)
{
	char	src[] = "hello";
	char	dest[] = "lalalal";
	char	s1[] = "\0";
	char	s2[] = "";
	char	s3[] = "0123456789";
	char	*ret1;
	char	*ret2;
	char	*ret3;
	char	*ret4;

	ret1 = strcpy(dest, src);
	ret2 = ft_strcpy(dest, src);
	printf("_____ft_strcpy_____\n");
	printf("strcpy : \t[%s]\nft_strcpy : \t[%s]\n", ret1, ret2);

	ret3 = malloc(20);
	ret4 = malloc(20);
	ret3 = strcpy(ret3, "adfdfaadfdsfasdfdsfasfd");
	ret4 = ft_strcpy(ret4, "adfdfaadfdsfasdfdsfasfd");
	printf("strcpy : \t[%s]\nft_strcpy : \t[%s]\n", ret3, ret4);
	ret3 = strcpy(ret3, "adfdfa");
	ret4 = ft_strcpy(ret4, "adfdfa");
	printf("strcpy : \t[%s]\nft_strcpy : \t[%s]\n", ret3, ret4);
	ret3 = ft_strcpy(ret3, "");
	ret4 = strcpy(ret4, "");
	printf("strcpy : \t[%s]\nft_strcpy : \t[%s]\n\n", ret3, ret4);

	if ((ft_strcpy(dest, src) == strcpy(dest, src)) &&
	(ft_strcpy(s3, s2) == strcpy(s3, s2)) &&
	(ft_strcpy(dest, s3) == strcpy(dest, s3)) &&
	(ft_strcpy(s3, dest) == strcpy(s3, dest)) &&
	(ft_strcpy(src, s1) == strcpy(src, s1)))
		printf("ft_strcpy\t[OK]\n\n");
	else
		printf("ft_strcpy\t[ERROR]\n\n");
}

static void		test_ft_strcmp(void)
{
	int		ret1;
	int		ret2;
	char	s1[] = "123456789";
	char	s2[] = "123456788";
	char	s3[] = "Hello world!";
	char	s4[] = "Hello world!";
	char	s5[] = "Hello worl!";
	char	s6[] = "\0";
	char	s7[] = "\0";
	char	s8[] = "01";
	char	s9[] = "01tyuiop";
	char	s11[] = "bonjour";
	char	s10[] = "";

	printf("_____ft_strcmp_____\n");
	ret1 = strcmp(s11, s10);
	ret2 = ft_strcmp(s11, s10);
	printf("strcmp : \t[%d]\nft_strcmp : \t[%d]\n\n", ret1, ret2);
	if ((ft_strcmp(s1, s2) == strcmp(s1, s2)) &&
	(ft_strcmp(s3, s4) == strcmp(s3, s4)) &&
	(ft_strcmp(s4, s5) == strcmp(s4, s5)) &&
	(ft_strcmp(s6, s7) == strcmp(s6, s7)) &&
	(ft_strcmp(s8, s9) == strcmp(s8, s9)) &&
	(ft_strcmp(s10, s11) == strcmp(s10, s11)) &&
	(ft_strcmp(s11, s10) == strcmp(s11, s10)) &&
	(ft_strcmp(s1, s10) == strcmp(s1, s10)) &&
	(ft_strcmp(s4, s10) == strcmp(s4, s10)) &&
	(ft_strcmp(s6, s10) == strcmp(s6, s10)))
		printf("ft_strcmp\t[OK]\n\n");
	else
		printf("ft_strcmp\t[ERROR]\n\n"); 
}

static void		test_ft_write(void)
{
	int		ret1;
	int		ret2;
	char	s1[] = "hello\n";
	char	s2[] = "test\n";
	char	s3[] = "\0";

	printf("_____ft_write_____\n");
	ret1 = write(1, s1, strlen(s1));
	ret2 = ft_write(1, s1, strlen(s1));
	printf("write : \t[%d]\nft_write : \t[%d]\n\n", ret1, ret2);
	ret1 = write(1, s2, strlen(s2));
	ret2 = ft_write(1, s2, strlen(s2));
	printf("write : \t[%d]\nft_write : \t[%d]\n\n", ret1, ret2);
	ret1 = write(1, s3, strlen(s3));
	ret2 = ft_write(1, s3, strlen(s3));
	printf("write : \t[%d]\nft_write : \t[%d]\n\n", ret1, ret2);
	close(42);
	ret1 = write(42, s1, strlen(s1));
	close(42);
	ret2 = ft_write(42, s1, strlen(s1));
	printf("write : \t[%d]\nft_write : \t[%d]\n\n", ret1, ret2);
	close(42);
	ret1 = write(42, NULL, -1);
	close(42);
	ret2 = ft_write(42, NULL, -1);
	printf("write : \t[%d]\nft_write : \t[%d]\n\n", ret1, ret2);

	printf("__test met error message__\n\n");
	errno = 0;
	ret1 = write(1, s1, strlen(s1));
	ret2 = ft_write(1, s1, strlen(s1));
	printf("\n");
	printf("write : \t{%i}\nerrno : \t[%i]\n", ret1, errno);
	perror("Error message");
	printf("ft_write : \t{%i}\nerrno : \t[%i]\n", ret2, errno);
	perror("Error message");
	errno = 0;
	printf("\n");
	ret1 = write(1, s2, strlen(s2));
	ret2 = ft_write(1, s2, strlen(s2));
	printf("\n");
	printf("write : \t{%i}\nerrno : \t[%i]\n", ret1, errno);
	perror("Error message");
	printf("ft_write : \t{%i}\nerrno : \t[%i]\n", ret2, errno);
	perror("Error message");
	errno = 0;
	printf("\n");   
	ret1 = write(1, s3, strlen(s3));
	ret2 = ft_write(1, s3, strlen(s3));
	printf("write : \t{%i}\nerrno : \t[%i]\n", ret1, errno);
	perror("Error message");
	printf("ft_write : \t{%i}\nerrno : \t[%i]\n", ret2, errno);
	perror("Error message");
	errno = 0;
	printf("\n");
	close(42);
	ret1 = write(42, s1, strlen(s1));
	close(42);
	ret2 = ft_write(42, s1, strlen(s1));
	printf("write : \t{%i}\nerrno : \t[%i]\n", ret1, errno);
	perror("Error message");
	printf("ft_write : \t{%i}\nerrno : \t[%i]\n", ret2, errno);
	perror("Error message");
	errno = 0;
	printf("\n");
	close(42);
	ret1 = write(42, NULL, -1);
	close(42);
	ret2 = ft_write(42, NULL, -1);
	printf("write : \t{%i}\nerrno : \t[%i]\n", ret1, errno);
	perror("Error message");
	printf("ft_write : \t{%i}\nerrno : \t[%i]\n", ret2, errno);
	perror("Error message");
	printf("\n");
}

static void		test_ft_read(void)
{
	int		fd1;
	int		fd2;
	int		ret1;
	int		ret2;
	char	buf[100];

	printf("_____ft_read_____\n");
	fd1 = open("read_test.txt", O_RDONLY);
	fd2 = open("read_test.txt", O_RDONLY);
	ret1 = read(fd1, buf, 99);
	buf[ret1] = '\0';
	ret2 = ft_read(fd2, buf, 99);
	buf[ret2] = '\0';
	printf("read : \t\t[%d]\nft_read : \t[%d]\n\n", ret1, ret2);
	close(42);
	ret1 = read(42, buf, 99);
	buf[ret1] = '\0';
	close(42);
	ret2 = ft_read(42, buf, 99);
	buf[ret2] = '\0';
	printf("read : \t\t[%d]\nft_read : \t[%d]\n\n", ret1, ret2);

	printf("__test met error message__\n\n");
	errno = 0;
	ret1 = read(fd1, buf, 99);
	buf[ret1] = '\0';
	ret2 = ft_read(fd2, buf, 99);
	buf[ret2] = '\0';
	printf("read : \t\t{%i}\nerrno : \t[%i]\n", ret1, errno);
	perror("Error message");
	printf("ft_read : \t{%i}\nerrno : \t[%i]\n", ret2, errno);
	perror("Error message");
	errno = 0;
	close(42);
	ret1 = read(42, buf, 99);
	buf[ret1] = '\0';
	close(42);
	ret2 = ft_read(42, buf, 99);
	buf[ret2] = '\0';
	printf("read : \t\t{%i}\nerrno : \t[%i]\n", ret1, errno);
	perror("Error message");
	printf("ft_read : \t{%i}\nerrno : \t[%i]\n", ret2, errno);
	perror("Error message");
	printf("\n");
}

static void		test_ft_strdup(void)
{
	char	*ret1;
	char	*ret2;
	char	s1[] = "hello";
	char	s2[] = "lalalal";
	char	s3[] = "\0";
	char	s4[] = "";
	char	s5[] = "0123456789";

	ret1 = strdup(s2);
	ret2 = ft_strdup(s2);
	printf("_____ft_strdup_____\n");
	printf("strdup :\t[%s]\nft_strdup :\t[%s]\n\n", ret1, ret2);
	if ((strcmp(ft_strdup(s1), strdup(s1)) == 0) &&
	(strcmp(ft_strdup(s2), strdup(s2)) == 0) &&
	(strcmp(ft_strdup(s3), strdup(s3)) == 0) &&
	(strcmp(ft_strdup(s4), strdup(s4)) == 0) &&
	(strcmp(ft_strdup(s5), strdup(s5)) == 0))
		printf("ft_strdup\t[OK]\n\n");
	else
		printf("ft_strdup\t[ERROR]\n\n");
	free(ret1);
	free(ret2);
}

int				main(void)
{
//	test_ft_strlen();
//	test_ft_strcpy();
//	test_ft_strcmp();
//	test_ft_write();
//	test_ft_read();
	test_ft_strdup();
	return (0);
}
