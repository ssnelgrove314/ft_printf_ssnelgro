/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:39 by mhurd            ###   ########.fr       */
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

int		test_ld( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_ld.in", "w+");
	//fprintf(fpin, "%D", 42);
	//fprintf(fpin, "Kashim a %D histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %D\n", -8000);
	//fprintf(fpin, "%D", -0);
	//fprintf(fpin, "%D", 0);
	//fprintf(fpin, "%D", INT_MAX);
	//fprintf(fpin, "%D", INT_MIN);
	//fprintf(fpin, "%D", INT_MIN - 1);
	//fprintf(fpin, "%D", INT_MAX + 1);
	//fprintf(fpin, "%%D 0000042 == |%D|\n", 0000042);
	//fprintf(fpin, "%%D \t == |%D|\n", '\t');
	//fprintf(fpin, "%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_ld.out", "w+", stdout);
	ft_printf("%D", 42);
	ft_printf("Kashim a %D histoires à raconter", 1001);
	ft_printf("Il fait au moins %D\n", -8000);
	ft_printf("%D", -0);
	ft_printf("%D", 0);
	ft_printf("%D", INT_MAX);
	ft_printf("%D", INT_MIN);
	ft_printf("%D", INT_MIN - 1);
	ft_printf("%D", INT_MAX + 1);
	ft_printf("%%D 0000042 == |%D|\n", 0000042);
	ft_printf("%%D \t == |%D|\n", '\t');
	ft_printf("%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_ld.out", 0644);
	fpin = fopen("test_ld.in", "r+");
	fpout = fopen("test_ld.out", "r+");
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
		printf("test_ld: [ok]\n");
		return 1;
	}
	printf("test_ld: [ko]\n");
	return 0;
}
