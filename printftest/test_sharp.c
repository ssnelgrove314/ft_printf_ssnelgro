/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sharp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:44 by mhurd            ###   ########.fr       */
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

int		test_sharp( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_sharp.in", "w+");
	//fprintf(fpin, "%%#X 42 ==  %#X\n", 42);
	//fprintf(fpin, "%%X 42 ==  %X\n", 42);
	//fprintf(fpin, "%%#o 0 ==  %#o\n", 0);
	//fprintf(fpin, "%%o 0 ==  %o\n", 0);
	//fprintf(fpin, "%%#o INT_MAX ==  %#o\n", INT_MAX);
	//fprintf(fpin, "%%o INT_MAX ==  %o\n", INT_MAX);
	//fprintf(fpin, "%%#o INT_MIN ==  %#o\n", INT_MIN);
	//fprintf(fpin, "%%o INT_MIN ==  %o\n", INT_MIN);
	//fprintf(fpin, "%%#X INT_MIN ==  %#X\n", INT_MIN);
	//fprintf(fpin, "%%X INT_MIN ==  %X\n", INT_MIN);
	//fprintf(fpin, "%%#X INT_MAX ==  %#X\n", INT_MAX);
	//fprintf(fpin, "%%X INT_MAX ==  %X\n", INT_MAX);

	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_sharp.out", "w+", stdout);
	ft_printf("%%#X 42 ==  %#X\n", 42);
	ft_printf("%%X 42 ==  %X\n", 42);
	ft_printf("%%#o 0 ==  %#o\n", 0);
	ft_printf("%%o 0 ==  %o\n", 0);
	ft_printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
	ft_printf("%%o INT_MAX ==  %o\n", INT_MAX);
	ft_printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	ft_printf("%%o INT_MIN ==  %o\n", INT_MIN);
	ft_printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	ft_printf("%%X INT_MIN ==  %X\n", INT_MIN);
	ft_printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
	ft_printf("%%X INT_MAX ==  %X\n", INT_MAX);

	chmod("test_sharp.out", 0644);
	fpin = fopen("test_sharp.in", "r+");
	fpout = fopen("test_sharp.out", "r+");
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
		printf("test_sharp: [ok]\n");
		return 1;
	}
	printf("test_sharp: [ko]\n");
	return 0;
}
