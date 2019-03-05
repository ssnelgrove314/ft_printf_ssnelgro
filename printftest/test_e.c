/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:04:45 by mhurd            ###   ########.fr       */
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

int		test_e( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_e.in", "w+");
	//fprintf(fpin, "%e", (double)42);
	//fprintf(fpin, "Kashim a %e histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %e\n", (double)-8000);
	//fprintf(fpin, "%e", (double)-0);
	//fprintf(fpin, "%e", (double)0);
	//fprintf(fpin, "%e", (double)INT_MAX);
	//fprintf(fpin, "%e", (double)INT_MIN);
	//fprintf(fpin, "%e", (double)INT_MIN - 1);
	//fprintf(fpin, "%e", (double)INT_MAX + 1);
	//fprintf(fpin, "%%e 0000042 == |%e|\n", (double)0000042);
	//fprintf(fpin, "%%e \t == |%e|\n", (double)'\t');
	//fprintf(fpin, "%%e Lydie == |%e|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%e 42.42 == |%e|\n", 42.42);
	//fprintf(fpin, "%E", (double)42);
	//fprintf(fpin, "Kashim a %E histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %E\n", (double)-8000);
	//fprintf(fpin, "%E", (double)-0);
	//fprintf(fpin, "%E", (double)0);
	//fprintf(fpin, "%E", (double)INT_MAX);
	//fprintf(fpin, "%E", (double)INT_MIN);
	//fprintf(fpin, "%E", (double)INT_MIN - 1);
	//fprintf(fpin, "%E", (double)INT_MAX + 1);
	//fprintf(fpin, "%%E 0000042 == |%E|\n", (double)0000042);
	//fprintf(fpin, "%%E \t == |%E|\n", (double)'\t');
	//fprintf(fpin, "%%E Lydie == |%E|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%E 42.42 == |%E|\n", 42.42);
	//fprintf(fpin, "%%E 42.42 == |%.2E|\n", 42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_e.out", "w+", stdout);
	ft_printf("%e", (double)42);
	ft_printf("Kashim a %e histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %e\n", (double)-8000);
	ft_printf("%e", (double)-0);
	ft_printf("%e", (double)0);
	ft_printf("%e", (double)INT_MAX);
	ft_printf("%e", (double)INT_MIN);
	ft_printf("%e", (double)INT_MIN - 1);
	ft_printf("%e", (double)INT_MAX + 1);
	ft_printf("%%e 0000042 == |%e|\n", (double)0000042);
	ft_printf("%%e \t == |%e|\n", (double)'\t');
	ft_printf("%%e Lydie == |%e|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%e 42.42 == |%e|\n", 42.42);
	ft_printf("%E", (double)42);
	ft_printf("Kashim a %E histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %E\n", (double)-8000);
	ft_printf("%E", (double)-0);
	ft_printf("%E", (double)0);
	ft_printf("%E", (double)INT_MAX);
	ft_printf("%E", (double)INT_MIN);
	ft_printf("%E", (double)INT_MIN - 1);
	ft_printf("%E", (double)INT_MAX + 1);
	ft_printf("%%E 0000042 == |%E|\n", (double)0000042);
	ft_printf("%%E \t == |%E|\n", (double)'\t');
	ft_printf("%%E Lydie == |%E|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%E 42.42 == |%E|\n", 42.42);
	ft_printf("%%E 42.42 == |%.2E|\n", 42.42);

	chmod("test_e.out", 0644);
	fpin = fopen("test_e.in", "r+");
	fpout = fopen("test_e.out", "r+");
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
		printf("test_e: [ok]\n");
		return 1;
	}
	printf("test_e: [ko]\n");
	return 0;
}
