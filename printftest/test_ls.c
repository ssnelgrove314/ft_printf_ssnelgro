/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:42 by mhurd            ###   ########.fr       */
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

int		test_ls( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	wchar_t wz [3] = L"@@";       // Zero-terminated
	int			fd = dup(fileno(stdout));

	fpin = fopen("test_ls.in", "w+");
	fprintf(fpin,"%ls", wz);   // Outputs 6 bytes
	fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_ls.out", "w+", stdout);
	ft_printf("%ls", wz);   // Outputs 6 bytes

	chmod("test_ls.out", 0644);
	fpin = fopen("test_ls.in", "r+");
	fpout = fopen("test_ls.out", "r+");
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
		printf("test_S: [ok]\n");
		return 1;
	}
	printf("test_S: [ko]\n");
	return 0;
}
