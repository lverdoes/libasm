/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_write.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 11:33:47 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/21 13:15:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"


static void	buffer_to_zero(int ret[4], int error_ret[2], char read_buffer[2][BUFFER_SIZE + 1])
{
	bzero(ret, sizeof(ret[4]));
	bzero(error_ret, sizeof(error_ret[2]));
	bzero(read_buffer[0], BUFFER_SIZE + 1);
	bzero(read_buffer[1], BUFFER_SIZE + 1);
}

void	test_ft_write(void)
{
	printf("\nft_write:\n\n");
	
	int write_test = 6;
	char *filename[write_test];
	
	filename[0] = strdup("./test_files/normal_test");
	filename[1] = strdup("./test_files/more_write_than_read_chars");
	filename[2] = strdup("./test_files/file_does_not_exist");
	filename[3] = strdup("");
	filename[4] = strdup("./test_files/.dir");
	filename[5] = strdup("./test_files/NO_PERMISSION");
	
	int fd;
	int ret[4];
	int	error_ret[2];
	char read_buffer[2][BUFFER_SIZE + 1];
	int i = 0;
	while (i < write_test)
	{
		buffer_to_zero(ret, error_ret, read_buffer);
		
		fd = open(filename[i], O_WRONLY);
		errno = 0;
		ret[0] = ft_write(fd, filename[i], strlen(filename[i]));
		error_ret[0] = errno;
		close(fd);
		fd = open(filename[i], O_RDONLY);
		ret[1] = read(fd, read_buffer[0], BUFFER_SIZE);
		close(fd);
		
		fd = open(filename[i], O_RDWR);
		errno = 0;
		ret[2] = write(fd, filename[i], strlen(filename[i]));
		error_ret[1] = errno;
		close(fd);
		fd = open(filename[i], O_RDONLY);
		ret[3] = read(fd, read_buffer[1], BUFFER_SIZE);
		close(fd);
		
		printf("\tTest [%d]:", i);
		if (ret[0] == ret[2] && error_ret[0] == error_ret[1] && !strncmp(read_buffer[0], read_buffer[1], BUFFER_SIZE + 1))
			printf("\t[OK]\n");
		else
		{
			printf("\t[FAIL]\n");
			printf("ft_: write_ret[0] = [%2d]\tread_ret[1] = [%2d]\terrno:[%s]\n", ret[0], ret[1], strerror(error_ret[0]));
			printf("man: write_ret[2] = [%2d]\tread_ret[3] = [%2d]\terrno:[%s]\n", ret[2], ret[3], strerror(error_ret[1]));
			printf("ft_: write = [%s]\tread = [%s]\n", filename[i], read_buffer[0]);
			printf("man: write = [%s]\tread = [%s]\n\n", filename[i], read_buffer[1]);
		}
		i++;
	}
	printf("\n");
}
