/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:15 by mhurd            ###   ########.fr       */
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

int		test_precision( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_precision.in", "w+");
	//fprintf(fpin, "%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	//fprintf(fpin, "%% 4.5i 42 == |% 4.5i|\n", 42);
	//fprintf(fpin, "%%04.5i 42 == |%04.5i|\n", 42);
	//fprintf(fpin, "%%04.3i 42 == |%04.3i|\n", 42);
	//fprintf(fpin, "%%04.2i 42 == |%04.2i|\n", 42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_precision.out", "w+", stdout);
	ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	ft_printf("%% 4.5i 42 == |% 4.5i|\n", 42);
	ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
	ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	ft_printf("%%04.2i 42 == |%04.2i|\n", 42);

	chmod("test_precision.out", 0644);
	fpin = fopen("test_precision.in", "r+");
	fpout = fopen("test_precision.out", "r+");
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
		printf("test_precision: [ok]\n");
		return 1;
	}
	printf("test_precision: [ko]\n");
	return 0;
}
