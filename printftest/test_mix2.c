/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mix2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:52 by mhurd            ###   ########.fr       */
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

int		test_mix2( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_mix2.in", "w+");
	//fprintf(fpin, "Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_mix2.out", "w+", stdout);
	ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");

	chmod("test_mix2.out", 0644);
	fpin = fopen("test_mix2.in", "r+");
	fpout = fopen("test_mix2.out", "r+");
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
		printf("test_mix2: [ok]\n");
		return 1;
	}
	printf("test_mix2: [ko]\n");
	return 0;
}
