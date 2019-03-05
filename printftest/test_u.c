/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:53 by mhurd            ###   ########.fr       */
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

int		test_u( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_u.in", "w+");
	//fprintf(fpin, "%u", 42);
	//fprintf(fpin, "Kashim a %u histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %u\n", -8000);
	//fprintf(fpin, "%u", -0);
	//fprintf(fpin, "%u", 0);
	//fprintf(fpin, "%u", INT_MAX);
	//fprintf(fpin, "%u", INT_MIN);
	//fprintf(fpin, "%u", INT_MIN - 1);
	//fprintf(fpin, "%u", INT_MAX + 1);
	//fprintf(fpin, "%%u 0000042 == |%u|\n", 0000042);
	//fprintf(fpin, "%%u \t == |%u|\n", '\t');
	//fprintf(fpin, "%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_u.out", "w+", stdout);
	ft_printf("%u", 42);
	ft_printf("Kashim a %u histoires à raconter", 1001);
	ft_printf("Il fait au moins %u\n", -8000);
	ft_printf("%u", -0);
	ft_printf("%u", 0);
	ft_printf("%u", INT_MAX);
	ft_printf("%u", INT_MIN);
	ft_printf("%u", INT_MIN - 1);
	ft_printf("%u", INT_MAX + 1);
	ft_printf("%%u 0000042 == |%u|\n", 0000042);
	ft_printf("%%u \t == |%u|\n", '\t');
	ft_printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_u.out", 0644);
	fpin = fopen("test_u.in", "r+");
	fpout = fopen("test_u.out", "r+");
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
		printf("test_u: [ok]\n");
		return 1;
	}
	printf("test_u: [ko]\n");
	return 0;
}
