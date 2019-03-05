/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:47 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include "tests.h"

int		test_minus( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_minus.in", "w+");
	//fprintf(fpin, "%%-i 42 == %-i\n", 42);
	//fprintf(fpin, "%%-d 42 == %-d\n", INT_MIN);
	//fprintf(fpin, "%%-i -42 == %-i\n", -42);
	//fprintf(fpin, "%%-4d 42 == |%-4d|\n", 42);
	//fprintf(fpin, "%%-5d -42 == |%-5d|\n", -42);
	//fprintf(fpin, "|%3i|%-3i|\n", 42, 42);
	//fprintf(fpin, "%%-4i 42 == |%-4i|\n", 42);

	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_minus.out", "w+", stdout);
	ft_printf("%%-i 42 == %-i\n", 42);
	ft_printf("%%-d 42 == %-d\n", INT_MIN);
	ft_printf("%%-i -42 == %-i\n", -42);
	ft_printf("%%-4d 42 == |%-4d|\n", 42);
	ft_printf("%%-5d -42 == |%-5d|\n", -42);
	ft_printf("|%3i|%-3i|\n", 42, 42);
	ft_printf("%%-4i 42 == |%-4i|\n", 42);

	chmod("test_minus.out", 0644);
	fpin = fopen("test_minus.in", "r+");
	fpout = fopen("test_minus.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}
	if (fdin != fdout)
		r00 = 1;

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	if (r00 == 0) {
		printf("test_minus: [ok]\n");
		return 1;
	}
	printf("test_minus: [ko]\n");
	return 0;
}
