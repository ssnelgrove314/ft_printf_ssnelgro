/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:16 by mhurd            ###   ########.fr       */
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

int		test_g( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_g.in", "w+");
	//fprintf(fpin, "%g", (double)42);
	//fprintf(fpin, "Kashim a %g histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %g\n", (double)-8000);
	//fprintf(fpin, "%g", (double)-0);
	//fprintf(fpin, "%g", (double)0);
	//fprintf(fpin, "%g", (double)INT_MAX);
	//fprintf(fpin, "%g", (double)INT_MIN);
	//fprintf(fpin, "%g", (double)INT_MIN - 1);
	//fprintf(fpin, "%g", (double)INT_MAX + 1);
	//fprintf(fpin, "%%g 0000042 == |%g|\n", (double)0000042);
	//fprintf(fpin, "%%g \t == |%g|\n", (double)'\t');
	//fprintf(fpin, "%%g Lydie == |%g|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%g 42.42 == |%g|\n", 42.42);
	//fprintf(fpin, "%G", (double)42);
	//fprintf(fpin, "Kashim a %G histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %G\n", (double)-8000);
	//fprintf(fpin, "%G", (double)-0);
	//fprintf(fpin, "%G", (double)0);
	//fprintf(fpin, "%G", (double)INT_MAX);
	//fprintf(fpin, "%G", (double)INT_MIN);
	//fprintf(fpin, "%G", (double)INT_MIN - 1);
	//fprintf(fpin, "%G", (double)INT_MAX + 1);
	//fprintf(fpin, "%%G 0000042 == |%G|\n", (double)0000042);
	//fprintf(fpin, "%%G \t == |%G|\n", (double)'\t');
	//fprintf(fpin, "%%G Lydie == |%G|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%G 42.42 == |%G|\n", 42.42);
	//fprintf(fpin, "%%G 42.42 == |%.2G|\n", 42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_g.out", "w+", stdout);
	ft_printf("%g", (double)42);
	ft_printf("Kashim a %g histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %g\n", (double)-8000);
	ft_printf("%g", (double)-0);
	ft_printf("%g", (double)0);
	ft_printf("%g", (double)INT_MAX);
	ft_printf("%g", (double)INT_MIN);
	ft_printf("%g", (double)INT_MIN - 1);
	ft_printf("%g", (double)INT_MAX + 1);
	ft_printf("%%g 0000042 == |%g|\n", (double)0000042);
	ft_printf("%%g \t == |%g|\n", (double)'\t');
	ft_printf("%%g Lydie == |%g|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%g 42.42 == |%g|\n", 42.42);
	ft_printf("%G", (double)42);
	ft_printf("Kashim a %G histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %G\n", (double)-8000);
	ft_printf("%G", (double)-0);
	ft_printf("%G", (double)0);
	ft_printf("%G", (double)INT_MAX);
	ft_printf("%G", (double)INT_MIN);
	ft_printf("%G", (double)INT_MIN - 1);
	ft_printf("%G", (double)INT_MAX + 1);
	ft_printf("%%G 0000042 == |%G|\n", (double)0000042);
	ft_printf("%%G \t == |%G|\n", (double)'\t');
	ft_printf("%%G Lydie == |%G|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%G 42.42 == |%G|\n", 42.42);
	ft_printf("%%G 42.42 == |%.2G|\n", 42.42);

	chmod("test_g.out", 0644);
	fpin = fopen("test_g.in", "r+");
	fpout = fopen("test_g.out", "r+");
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
		printf("test_g: [ok]\n");
		return 1;
	}
	printf("test_g: [ko]\n");
	return 0;
}
