/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:04:48 by mhurd            ###   ########.fr       */
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

int		test_f( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_f.in", "w+");
	//fprintf(fpin, "%f", (double)42);
	//fprintf(fpin, "Kashim a %f histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %f\n", (double)-8000);
	//fprintf(fpin, "%f", (double)-0);
	//fprintf(fpin, "%f", (double)0);
	//fprintf(fpin, "%f", (double)INT_MAX);
	//fprintf(fpin, "%f", (double)INT_MIN);
	//fprintf(fpin, "%f", (double)INT_MIN - 1);
	//fprintf(fpin, "%f", (double)INT_MAX + 1);
	//fprintf(fpin, "%%f 0000042 == |%f|\n", (double)0000042);
	//fprintf(fpin, "%%f \t == |%f|\n", (double)'\t');
	//fprintf(fpin, "%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%f 42.42 == |%f|\n", 42.42);
	//fprintf(fpin, "%F", (double)42);
	//fprintf(fpin, "Kashim a %F histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %F\n", (double)-8000);
	//fprintf(fpin, "%F", (double)-0);
	//fprintf(fpin, "%F", (double)0);
	//fprintf(fpin, "%F", (double)INT_MAX);
	//fprintf(fpin, "%F", (double)INT_MIN);
	//fprintf(fpin, "%F", (double)INT_MIN - 1);
	//fprintf(fpin, "%F", (double)INT_MAX + 1);
	//fprintf(fpin, "%%F 0000042 == |%F|\n", (double)0000042);
	//fprintf(fpin, "%%F \t == |%F|\n", (double)'\t');
	//fprintf(fpin, "%%F Lydie == |%F|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%F 42.42 == |%F|\n", 42.42);
	//fprintf(fpin, "%%F 42.42 == |%.2F|\n", 42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_f.out", "w+", stdout);
	ft_printf("%f", (double)42);
	ft_printf("Kashim a %f histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %f\n", (double)-8000);
	ft_printf("%f", (double)-0);
	ft_printf("%f", (double)0);
	ft_printf("%f", (double)INT_MAX);
	ft_printf("%f", (double)INT_MIN);
	ft_printf("%f", (double)INT_MIN - 1);
	ft_printf("%f", (double)INT_MAX + 1);
	ft_printf("%%f 0000042 == |%f|\n", (double)0000042);
	ft_printf("%%f \t == |%f|\n", (double)'\t');
	ft_printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%f 42.42 == |%f|\n", 42.42);
	ft_printf("%F", (double)42);
	ft_printf("Kashim a %F histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %F\n", (double)-8000);
	ft_printf("%F", (double)-0);
	ft_printf("%F", (double)0);
	ft_printf("%F", (double)INT_MAX);
	ft_printf("%F", (double)INT_MIN);
	ft_printf("%F", (double)INT_MIN - 1);
	ft_printf("%F", (double)INT_MAX + 1);
	ft_printf("%%F 0000042 == |%F|\n", (double)0000042);
	ft_printf("%%F \t == |%F|\n", (double)'\t');
	ft_printf("%%F Lydie == |%F|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%F 42.42 == |%F|\n", 42.42);
	ft_printf("%%F 42.42 == |%.2F|\n", 42.42);

	chmod("test_f.out", 0644);
	fpin = fopen("test_f.in", "r+");
	fpout = fopen("test_f.out", "r+");
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
		printf("test_f: [ok]\n");
		return 1;
	}
	printf("test_f: [ko]\n");
	return 0;
}
