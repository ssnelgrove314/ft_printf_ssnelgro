/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:07:05 by mhurd            ###   ########.fr       */
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

int		test_a( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_a.in", "w+");
	//fprintf(fpin, "%a", (double)42);
	//fprintf(fpin, "Kashim a %a histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %a\n", (double)-8000);
	//fprintf(fpin, "%a", (double)-0);
	//fprintf(fpin, "%a", (double)0);
	//fprintf(fpin, "%a", (double)INT_MAX);
	//fprintf(fpin, "%a", (double)INT_MIN);
	//fprintf(fpin, "%a", (double)INT_MIN - 1);
	//fprintf(fpin, "%a", (double)INT_MAX + 1);
	//fprintf(fpin, "%%a 0000042 == |%a|\n", (double)0000042);
	//fprintf(fpin, "%%a \t == |%a|\n", (double)'\t');
	//fprintf(fpin, "%%a Lydie == |%a|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%a 42.42 == |%a|\n", 42.42);
	//fprintf(fpin, "%A", (double)42);
	//fprintf(fpin, "Kashim a %A histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %A\n", (double)-8000);
	//fprintf(fpin, "%A", (double)-0);
	//fprintf(fpin, "%A", (double)0);
	//fprintf(fpin, "%A", (double)INT_MAX);
	//fprintf(fpin, "%A", (double)INT_MIN);
	//fprintf(fpin, "%A", (double)INT_MIN - 1);
	//fprintf(fpin, "%A", (double)INT_MAX + 1);
	//fprintf(fpin, "%%A 0000042 == |%A|\n", (double)0000042);
	//fprintf(fpin, "%%A \t == |%A|\n", (double)'\t');
	//fprintf(fpin, "%%A Lydie == |%A|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%A 42.42 == |%A|\n", 42.42);
	//fprintf(fpin, "%%A 42.42 == |%.2A|\n", 42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_a.out", "w+", stdout);
	ft_printf("%a", (double)42);
	ft_printf("Kashim a %a histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %a\n", (double)-8000);
	ft_printf("%a", (double)-0);
	ft_printf("%a", (double)0);
	ft_printf("%a", (double)INT_MAX);
	ft_printf("%a", (double)INT_MIN);
	ft_printf("%a", (double)INT_MIN - 1);
	ft_printf("%a", (double)INT_MAX + 1);
	ft_printf("%%a 0000042 == |%a|\n", (double)0000042);
	ft_printf("%%a \t == |%a|\n", (double)'\t');
	ft_printf("%%a Lydie == |%a|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%a 42.42 == |%a|\n", 42.42);
	ft_printf("%A", (double)42);
	ft_printf("Kashim a %A histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %A\n", (double)-8000);
	ft_printf("%A", (double)-0);
	ft_printf("%A", (double)0);
	ft_printf("%A", (double)INT_MAX);
	ft_printf("%A", (double)INT_MIN);
	ft_printf("%A", (double)INT_MIN - 1);
	ft_printf("%A", (double)INT_MAX + 1);
	ft_printf("%%A 0000042 == |%A|\n", (double)0000042);
	ft_printf("%%A \t == |%A|\n", (double)'\t');
	ft_printf("%%A Lydie == |%A|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%A 42.42 == |%A|\n", 42.42);
	ft_printf("%%A 42.42 == |%.2A|\n", 42.42);

	chmod("test_a.out", 0644);
	fpin = fopen("test_a.in", "r+");
	fpout = fopen("test_a.out", "r+");
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
		printf("test_a: [ok]\n");
		return 1;
	}
	printf("test_a: [ko]\n");
	return 0;
}
