/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:33 by mhurd            ###   ########.fr       */
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

int		test_lc( void )
{
	int			r00 = 0;
	wchar_t		c = L'\x82';
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_lc.in", "w+");
	//fprintf(fpin, "%C\n", c);
	//fprintf(fpin, "%C\n", L'ø');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_lc.out", "w+", stdout);
	ft_printf("%C\n", c);
	ft_printf("%C\n", L'ø');

	chmod("test_lc.out", 0644);
	fpin = fopen("test_lc.in", "r+");
	fpout = fopen("test_lc.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}
	if (fdin != fdout)
		r00 = 1;

	if (r00 == 0) {
		printf("test_C: [ok]\n");
		return 1;
	}
	printf("test_C: [ko]\n");
	return 0;
}
