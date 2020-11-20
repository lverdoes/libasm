/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_read.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 11:33:12 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/20 23:30:58 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_libasm.h"

static void	buffer_to_zero(char read_buffer[2][BUFFER_SIZE + 1])
{
	bzero(read_buffer[0], BUFFER_SIZE + 1);
	bzero(read_buffer[1], BUFFER_SIZE + 1);
}

void	test_ft_read(void)
{
	printf("\nft_read:\n\n");
	
	int read_test = 6;
	char *filename[read_test];
	
	filename[0] = strdup("./test_files/normal_test");
	filename[1] = strdup("./test_files/more_write_than_read_chars");
	filename[2] = strdup("./test_files/file_does_not_exist");
	filename[3] = strdup("");
	filename[4] = strdup("./test_files/.dir");
	filename[5] = strdup("./test_files/NO_PERMISSION");
	
	int fd;
	int function_ret[2];
	char read_buffer[2][BUFFER_SIZE + 1];
	int error_ret[2];
	int i = 0;
	while (i < read_test)
	{
		buffer_to_zero(read_buffer);

		fd = open(filename[i], O_RDONLY);
		errno = 0;
		function_ret[0] = ft_read(fd, read_buffer[0], BUFFER_SIZE);
        error_ret[0] = errno;
		close(fd);
		fd = open(filename[i], O_RDONLY);
		function_ret[1] = read(fd, read_buffer[1], BUFFER_SIZE);
        error_ret[1] = errno;
		close(fd);
		printf("\tTest [%d]:", i);
        if (!strncmp(read_buffer[0], read_buffer[1], BUFFER_SIZE + 1) && function_ret[0] == function_ret[1] && error_ret[0] == error_ret[1])
        	printf("\t\t[OK]\n");
        else
        {
            printf("\t\t[FAIL]\n");
            printf("ft_: ret:[%d] errno:[%s]\n", function_ret[0], strerror(error_ret[0]));
			printf("man: ret:[%d] errno:[%s]\n", function_ret[1], strerror(error_ret[1]));
            printf("ft_read buffer = [%s]\n", read_buffer[0]);
            printf("manread buffer = [%s]\n\n", read_buffer[1]);
        }
        i++;
    }
	printf("\n");
}
