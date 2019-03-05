/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:50 by mhurd            ###   ########.fr       */
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

int		test_star( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_star.in", "w+");
	//fprintf(fpin, "%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	//fprintf(fpin, "%% *.5i 42 == |% *.5i|\n", 4, 42);
	//fprintf(fpin, "%%*i 42 == |%*i|\n", 5, 42);
	//fprintf(fpin, "%%*i 42 == |%*i|\n", 3, 42);
	//fprintf(fpin, "%%*i 42 == |%*i|\n", 2, 42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_star.out", "w+", stdout);
	ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	ft_printf("%%*i 42 == |%*i|\n", 5, 42);
	ft_printf("%%*i 42 == |%*i|\n", 3, 42);
	ft_printf("%%*i 42 == |%*i|\n", 2, 42);

	chmod("test_star.out", 0644);
	fpin = fopen("test_star.in", "r+");
	fpout = fopen("test_star.out", "r+");
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
		printf("test_star: [ok]\n");
		return 1;
	}
	printf("test_star: [ko]\n");
	return 0;
}
