/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:13 by mhurd            ###   ########.fr       */
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

int		test_plus( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_plus.in", "w+");
	//fprintf(fpin, "%%+i 42 == %+i\n", 42);
	//fprintf(fpin, "%%+d 42 == %+d\n", INT_MAX);
	//fprintf(fpin, "%%+i -42 == %+i\n", -42);
	//fprintf(fpin, "%%+04d 42 == %0+04d\n", 42);

	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_plus.out", "w+", stdout);
	ft_printf("%%+i 42 == %+i\n", 42);
	ft_printf("%%+d 42 == %+d\n", INT_MAX);
	ft_printf("%%+i -42 == %+i\n", -42);
	ft_printf("%%+04d 42 == %0+04d\n", 42);

	chmod("test_plus.out", 0644);
	fpin = fopen("test_plus.in", "r+");
	fpout = fopen("test_plus.out", "r+");
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
		printf("test_plus: [ok]\n");
		return 1;
	}
	printf("test_plus: [ko]\n");
	return 0;
}
