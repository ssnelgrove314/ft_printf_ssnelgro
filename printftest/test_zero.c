/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:07:01 by mhurd            ###   ########.fr       */
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

int		test_zero( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_zero.in", "w+");
	//fprintf(fpin, "%%04i 42 == |%04i|\n", 42);
	//fprintf(fpin, "%%05i 42 == |%05i|\n", 42);
	//fprintf(fpin, "%%0i 42 == |%0i|\n", 42);
	//fprintf(fpin, "%%0d 0000042 == |%0d|\n", 0000042);

	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_zero.out", "w+", stdout);
	ft_printf("%%04i 42 == |%04i|\n", 42);
	ft_printf("%%05i 42 == |%05i|\n", 42);
	ft_printf("%%0i 42 == |%0i|\n", 42);
	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);

	chmod("test_zero.out", 0644);
	fpin = fopen("test_zero.in", "r+");
	fpout = fopen("test_zero.out", "r+");
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
		printf("test_zero: [ok]\n");
		return 1;
	}
	printf("test_zero: [ko]\n");
	return 0;
}
