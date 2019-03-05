/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:55 by mhurd            ###   ########.fr       */
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

int		test_n( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_n.in", "w+");
	int		nb = 42;
	//fprintf(fpin, "LALALALALAL\n%n", &nb);
	//fprintf(fpin, "%d\n", nb);
	//fprintf(fpin, "Kashim a %d histoires à raconter\n%n", 1001, &nb);
	//fprintf(fpin, "%d\n", nb);
	//fprintf(fpin, "%d%n", '\t', &nb);
	//fprintf(fpin, "%d\n", nb);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_n.out", "w+", stdout);
	int nb2 = 42;
	ft_printf("LALALALALAL\n%n", &nb2);
	ft_printf("%d\n", nb2);
	ft_printf("Kashim a %d histoires à raconter\n%n", 1001, &nb2);
	ft_printf("%d\n", nb2);
	ft_printf("%d%n", '\t', &nb2);
	ft_printf("%d\n", nb2);

	chmod("test_n.out", 0644);
	fpin = fopen("test_n.in", "r+");
	fpout = fopen("test_n.out", "r+");
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
		printf("test_n: [ok]\n");
		return 1;
	}
	printf("test_n: [ko]\n");
	return 0;
}
