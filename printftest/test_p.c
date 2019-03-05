/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:24:46 by mhurd            ###   ########.fr       */
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

int		test_p( void )
{
	int			r00 = 0;
	char		c = 0;
	char		*str = "pouet";
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	fpin = fopen("test_p.in", "w+");
	fgetpos(stdout, &pos);
	freopen("test_p.out", "w+", stdout);

	fprintf(fpin, "%p\n", &c);
	ft_printf("%p\n", &c);
	fprintf(fpin, "%p\n", str);
	ft_printf("%p\n", str);
	fprintf(fpin, "%p\n", &str);
	ft_printf("%p\n", &str);
	str = NULL;
	fprintf(fpin, "0x0\n");
	ft_printf("%p\n", str);
	str = (char *)malloc(sizeof(char) * 10);
	str = strdup("Coucou les haricots !");
	fprintf(fpin, "%p\n", str);
	ft_printf("%p\n", str);
	fclose(fpin);

	chmod("test_p.out", 0644);
	fpin = fopen("test_p.in", "r+");
	fpout = fopen("test_p.out", "r+");
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
		printf("test_p: [ok]\n");
		return 1;
	}
	printf("test_p: [ko]\n");
	return 0;
}
