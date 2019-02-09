/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:04:39 by mhurd            ###   ########.fr       */
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

int		test_c( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_c.in", "w+");
	//fprintf(fpin, "%c", 42);
	//fprintf(fpin, "Kashim a %c histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %c\n", -8000);
	//fprintf(fpin, "%c", -0);
	//fprintf(fpin, "%c", 0);
	//fprintf(fpin, "%c\n", INT_MAX);
	//fprintf(fpin, "%c\n", 'c');
	//fprintf(fpin, "%c\n", '\n');
	//fprintf(fpin, "%c", 'l');
	//fprintf(fpin, "%c", 'y');
	//fprintf(fpin, "%c", ' ');
	//fprintf(fpin, "%c", 'e');
	//fprintf(fpin, "%c", 's');
	//fprintf(fpin, "%c", 't');
	//fprintf(fpin, "%c", ' ');
	//fprintf(fpin, "%c", 'f');
	//fprintf(fpin, "%c", 'a');
	//fprintf(fpin, "%c", 'n');
	//fprintf(fpin, "%c", 't');
	//fprintf(fpin, "%c", 'a');
	//fprintf(fpin, "%c", 's');
	//fprintf(fpin, "%c", 't');
	//fprintf(fpin, "%c", 'i');
	//fprintf(fpin, "%c", 'q');
	//fprintf(fpin, "%c", 'u');
	//fprintf(fpin, "%c", 'e');
	//fprintf(fpin, "%c\n", '!');
	//fprintf(fpin, "%c\n", '\r');
	//fprintf(fpin, "%c\n", '\t');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_c.out", "w+", stdout);
	ft_printf("%c", 42);
	ft_printf("Kashim a %c histoires à raconter", 1001);
	ft_printf("Il fait au moins %c\n", -8000);
	ft_printf("%c", -0);
	ft_printf("%c", 0);
	ft_printf("%c\n", INT_MAX);
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '\n');
	ft_printf("%c", 'l');
	ft_printf("%c", 'y');
	ft_printf("%c", ' ');
	ft_printf("%c", 'e');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", ' ');
	ft_printf("%c", 'f');
	ft_printf("%c", 'a');
	ft_printf("%c", 'n');
	ft_printf("%c", 't');
	ft_printf("%c", 'a');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", 'i');
	ft_printf("%c", 'q');
	ft_printf("%c", 'u');
	ft_printf("%c", 'e');
	ft_printf("%c\n", '!');
	ft_printf("%c\n", '\r');
	ft_printf("%c\n", '\t');

	chmod("test_c.out", 0644);
	fpin = fopen("test_c.in", "r+");
	fpout = fopen("test_c.out", "r+");
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
		printf("test_c: [ok]\n");
		return 1;
	}
	printf("test_c: [ko]\n");
	return 0;
}
