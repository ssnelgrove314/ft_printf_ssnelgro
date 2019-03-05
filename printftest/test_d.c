/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:04:42 by mhurd            ###   ########.fr       */
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

int		test_d( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_d.in", "w+");
	//fprintf(fpin, "%d", 42);
	//fprintf(fpin, "Kashim a %d histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %d\n", -8000);
	//fprintf(fpin, "%d", -0);
	//fprintf(fpin, "%d", 0);
	//fprintf(fpin, "%d", INT_MAX);
	//fprintf(fpin, "%d", INT_MIN);
	//fprintf(fpin, "%d", INT_MIN - 1);
	//fprintf(fpin, "%d", INT_MAX + 1);
	//fprintf(fpin, "%%d 0000042 == |%d|\n", 0000042);
	//fprintf(fpin, "%%d \t == |%d|\n", '\t');
	//fprintf(fpin, "%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_d.out", "w+", stdout);
	ft_printf("%d", 42);
	ft_printf("Kashim a %d histoires à raconter", 1001);
	ft_printf("Il fait au moins %d\n", -8000);
	ft_printf("%d", -0);
	ft_printf("%d", 0);
	ft_printf("%d", INT_MAX);
	ft_printf("%d", INT_MIN);
	ft_printf("%d", INT_MIN - 1);
	ft_printf("%d", INT_MAX + 1);
	ft_printf("%%d 0000042 == |%d|\n", 0000042);
	ft_printf("%%d \t == |%d|\n", '\t');
	ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);

	chmod("test_d.out", 0644);
	fpin = fopen("test_d.in", "r+");
	fpout = fopen("test_d.out", "r+");
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

	if (r00 == 0) {
		printf("test_d: [ok]\n");
		return 1;
	}
	printf("test_d: [ko]\n");
	return 0;
}
