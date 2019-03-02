/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:28:42 by clboutry          #+#    #+#             */
/*   Updated: 2019/01/14 14:05:23 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "GNL/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "GNL/libft/libft.h"
#include <stdio.h>

int main(void)
{
	int fd1;
	int fd2;
	int fd3;
	char *str;
	int cmpt;

	cmpt = 0;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	if ((str = (char *)malloc(sizeof(char *) * 4)) == NULL)
		return (0);
	while (cmpt < 3)
	{
		get_next_line(fd1, &str);
		printf("%s", str);
		getchar();
		cmpt++;
	}
	while (cmpt < 8)
	{
		get_next_line(fd2, &str);
		printf("%s", str);
		getchar();
		cmpt++;
	}
	while (get_next_line(fd3, &str))
	{
		printf("%s", str);
		getchar();
	}
	while (get_next_line(fd2, &str))
	{
		printf("%s", str);
		getchar();
	}
	while (get_next_line(fd1, &str))
	{
		printf("%s", str);
		getchar();
	}
	write(1, "FINI", 4);
	free(str);
	return (0);
}
