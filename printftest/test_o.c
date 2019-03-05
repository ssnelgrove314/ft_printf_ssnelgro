/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:59 by mhurd            ###   ########.fr       */
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

int		test_o( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_o.in", "w+");
	//fprintf(fpin, "%o", 42);
	//fprintf(fpin, "Kashim a %o histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %o\n", -8000);
	//fprintf(fpin, "%o", -0);
	//fprintf(fpin, "%o", 0);
	//fprintf(fpin, "%o", INT_MAX);
	//fprintf(fpin, "%o", INT_MIN);
	//fprintf(fpin, "%o", INT_MIN - 1);
	//fprintf(fpin, "%o", INT_MAX + 1);
	//fprintf(fpin, "%%o 0000042 == |%o|\n", 0000042);
	//fprintf(fpin, "%%o \t == |%o|\n", '\t');
	//fprintf(fpin, "%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_o.out", "w+", stdout);
	ft_printf("%o", 42);
	ft_printf("Kashim a %o histoires à raconter", 1001);
	ft_printf("Il fait au moins %o\n", -8000);
	ft_printf("%o", -0);
	ft_printf("%o", 0);
	ft_printf("%o", INT_MAX);
	ft_printf("%o", INT_MIN);
	ft_printf("%o", INT_MIN - 1);
	ft_printf("%o", INT_MAX + 1);
	ft_printf("%%o 0000042 == |%o|\n", 0000042);
	ft_printf("%%o \t == |%o|\n", '\t');
	ft_printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_o.out", 0644);
	fpin = fopen("test_o.in", "r+");
	fpout = fopen("test_o.out", "r+");
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
		printf("test_o: [ok]\n");
		return 1;
	}
	printf("test_o: [ko]\n");
	return 0;
}
