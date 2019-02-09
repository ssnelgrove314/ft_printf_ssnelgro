/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:57 by mhurd            ###   ########.fr       */
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

int		test_x( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_x.in", "w+");
	//fprintf(fpin, "%x", 42);
	//fprintf(fpin, "Kashim a %x histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %x\n", -8000);
	//fprintf(fpin, "%x", -0);
	//fprintf(fpin, "%x", 0);
	//fprintf(fpin, "%x", INT_MAX);
	//fprintf(fpin, "%x", INT_MIN);
	//fprintf(fpin, "%x", INT_MIN - 1);
	//fprintf(fpin, "%x", INT_MAX + 1);
	//fprintf(fpin, "%%x 0000042 == |%x|\n", 0000042);
	//fprintf(fpin, "%%x \t == |%x|\n", '\t');
	//fprintf(fpin, "%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_x.out", "w+", stdout);
	ft_printf("%x", 42);
	ft_printf("Kashim a %x histoires à raconter", 1001);
	ft_printf("Il fait au moins %x\n", -8000);
	ft_printf("%x", -0);
	ft_printf("%x", 0);
	ft_printf("%x", INT_MAX);
	ft_printf("%x", INT_MIN);
	ft_printf("%x", INT_MIN - 1);
	ft_printf("%x", INT_MAX + 1);
	ft_printf("%%x 0000042 == |%x|\n", 0000042);
	ft_printf("%%x \t == |%x|\n", '\t');
	ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_x.out", 0644);
	fpin = fopen("test_x.in", "r+");
	fpout = fopen("test_x.out", "r+");
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
		printf("test_x: [ok]\n");
		return 1;
	}
	printf("test_x: [ko]\n");
	return 0;
}
