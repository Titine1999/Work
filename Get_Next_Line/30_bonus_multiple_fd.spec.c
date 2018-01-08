//#include <project.h>
#include <stdio.h>

int		main()
{
	char	*line_fd0;
	int		p_fd0[2];
	int		fd0 = 0;
	int		out_fd0 = dup(fd0);

	char	*line_fd1;
	int		p_fd1[2];
	int		fd1 = 1;
	int		out_fd1 = dup(fd1);

	char	*line_fd2;
	int		p_fd2[2];
	int		fd2 = 2;
	int		out_fd2 = dup(fd2);

	char	*line_fd3;
	int		p_fd3[2];
	int		fd3 = 3;
	int		out_fd3 = dup(fd3);

	pipe(p_fd0);
	dup2(p_fd0[1], fd0);
	write(fd0, "aaa\nbbb\n", 8);
	printf("fd0= \naaa\nbbb\n", fd0);
	dup2(out_fd0, fd0);
	close(p_fd0[1]);

	pipe(p_fd1);
	dup2(p_fd1[1], fd1);
	write(fd1, "111\n222\n", 8);
	printf("fd1= \n111\n222\n", fd1);
	dup2(out_fd1, fd1);
	close(p_fd1[1]);

	pipe(p_fd2);
	dup2(p_fd2[1], fd2);
	write(fd2, "www\nzzz\n", 8);
	printf("fd2= \nwww\nzzz\n", fd2);
	dup2(out_fd2, fd2);
	close(p_fd2[1]);

	pipe(p_fd3);
	dup2(p_fd3[1], fd3);
	write(fd3, "888\n999\n", 8);
	printf("fd3= \n888\n999\n", fd3);
	dup2(out_fd3, fd3);
	close(p_fd3[1]);

	get_next_line(p_fd0[0], &line_fd0);
	printf("fd0-%s\n", line_fd0);
	get_next_line(p_fd1[0], &line_fd1);
	printf("fd1-%s\n", line_fd1);
	get_next_line(p_fd2[0], &line_fd2);
	printf("fd2-%s\n", line_fd2);
	get_next_line(p_fd3[0], &line_fd3);
	printf("fd3-%s\n", line_fd3);
	get_next_line(p_fd0[0], &line_fd0);
	printf("fd0-%s\n", line_fd0);
	get_next_line(p_fd1[0], &line_fd1);
	printf("fd1-%s\n", line_fd1);
	get_next_line(p_fd2[0], &line_fd2);
	printf("fd2-%s\n", line_fd2);
	get_next_line(p_fd3[0], &line_fd3);
	printf("fd3-%s\n", line_fd3);
	return (0);
}
