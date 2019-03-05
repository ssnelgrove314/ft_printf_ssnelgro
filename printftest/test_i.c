/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:26 by mhurd            ###   ########.fr       */
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

int		test_i( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_i.in", "w+");
	//fprintf(fpin, "%i", 42);
	//fprintf(fpin, "Kashim a %i histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %i\n", -8000);
	//fprintf(fpin, "%i", -0);
	//fprintf(fpin, "%i", 0);
	//fprintf(fpin, "%i", INT_MAX);
	//fprintf(fpin, "%i", INT_MIN);
	//fprintf(fpin, "%i", INT_MIN - 1);
	//fprintf(fpin, "%i", INT_MAX + 1);
	//fprintf(fpin, "%%i 0000042 == |%i|\n", 0000042);
	//fprintf(fpin, "%%i \t == |%i|\n", '\t');
	//fprintf(fpin, "%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_i.out", "w+", stdout);
	ft_printf("%i", 42);
	ft_printf("Kashim a %i histoires à raconter", 1001);
	ft_printf("Il fait au moins %i\n", -8000);
	ft_printf("%i", -0);
	ft_printf("%i", 0);
	ft_printf("%i", INT_MAX);
	ft_printf("%i", INT_MIN);
	ft_printf("%i", INT_MIN - 1);
	ft_printf("%i", INT_MAX + 1);
	ft_printf("%%i 0000042 == |%i|\n", 0000042);
	ft_printf("%%i \t == |%i|\n", '\t');
	ft_printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_i.out", 0644);
	fpin = fopen("test_i.in", "r+");
	fpout = fopen("test_i.out", "r+");
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
		printf("test_i: [ok]\n");
		return 1;
	}
	printf("test_i: [ko]\n");
	return 0;
}
