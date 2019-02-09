/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:30 by mhurd            ###   ########.fr       */
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

int		test_l( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_l.in", "w+");
	//fprintf(fpin, "%Le", (long double)42);
	//fprintf(fpin, "Kashim a %Le histoires à raconter", (long double)1001);
	//fprintf(fpin, "Il fait au moins %Le\n", (long double)-8000);
	//fprintf(fpin, "%Le", (long double)-0);
	//fprintf(fpin, "%Le", (long double)0);
	//fprintf(fpin, "%Le", (long double)INT_MAX);
	//fprintf(fpin, "%Le", (long double)INT_MIN);
	//fprintf(fpin, "%Le", (long double)INT_MIN - 1);
	//fprintf(fpin, "%Le", (long double)INT_MAX + 1);
	//fprintf(fpin, "%Le", (long double)LONG_MAX);
	//fprintf(fpin, "%Le", (long double)LONG_MIN);
	//fprintf(fpin, "%Le", (long double)LONG_MIN - 1);
	//fprintf(fpin, "%Le", (long double)LONG_MAX + 1);
	//fprintf(fpin, "%%Le 0000042 == |%Le|\n", (long double)0000042);
	//fprintf(fpin, "%%Le \t == |%Le|\n", (long double)'\t');
	//fprintf(fpin, "%%Le Lydie == |%Le|\n", (long double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%Le 42.42 == |%Le|\n", (long double)42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_l.out", "w+", stdout);
	ft_printf("%Le", (long double)42);
	ft_printf("Kashim a %Le histoires à raconter", (long double)1001);
	ft_printf("Il fait au moins %Le\n", (long double)-8000);
	ft_printf("%Le", (long double)-0);
	ft_printf("%Le", (long double)0);
	ft_printf("%Le", (long double)INT_MAX);
	ft_printf("%Le", (long double)INT_MIN);
	ft_printf("%Le", (long double)INT_MIN - 1);
	ft_printf("%Le", (long double)INT_MAX + 1);
	ft_printf("%Le", (long double)LONG_MAX);
	ft_printf("%Le", (long double)LONG_MIN);
	ft_printf("%Le", (long double)LONG_MIN - 1);
	ft_printf("%Le", (long double)LONG_MAX + 1);
	ft_printf("%%Le 0000042 == |%Le|\n", (long double)0000042);
	ft_printf("%%Le \t == |%Le|\n", (long double)'\t');
	ft_printf("%%Le Lydie == |%Le|\n", (long double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%Le 42.42 == |%Le|\n", (long double)42.42);

	chmod("test_l.out", 0644);
	fpin = fopen("test_l.in", "r+");
	fpout = fopen("test_l.out", "r+");
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
		printf("test_L: [ok]\n");
		return 1;
	}
	printf("test_L: [ko]\n");
	return 0;
}
