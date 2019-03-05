/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hhhllljz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:21 by mhurd            ###   ########.fr       */
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

int		test_hhhllljz( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));
	unsigned char a = -125;
	unsigned int b = -125;
	unsigned long c = -125;
	unsigned short d = -125;
	size_t e = -125;
	uintmax_t f = -125;
	unsigned long long	g = -125;

	unsigned char h = 0;
	unsigned int i = 0;
	unsigned long j = 0;
	unsigned short k = 0;
	size_t l = 0;
	uintmax_t m = 0;
	unsigned long long n = 0;

	unsigned char o = (unsigned char)~0U>>1;
	unsigned int p = ~0U>>1;
	unsigned long q = ~0U>>1;
	unsigned short r = (short)~0U>>1;
	size_t s = (size_t)~0U>>1;
	uintmax_t t = (uintmax_t)~0U>>1;
	unsigned long long u = (unsigned long long)~0U>>1;

	unsigned char v = -m-1;
	unsigned int w = -n-1;
	unsigned long x = -o-1;
	unsigned short y = -p-1;
	unsigned long z = -q-1;
	uintmax_t zz = -r-1;
	unsigned long long aa = -r-1;

	//fpin = fopen("test_hhhllljz.in", "w+");
	//fprintf(fpin, "unsigned char		a = %hhu sizeof a = %lu\n", a,sizeof(a));
	//fprintf(fpin, "unsigned int		b = %u sizeof b = %lu\n",b,sizeof(b));
	//fprintf(fpin, "unsigned long		c = %lu sizeof c = %lu\n",c,sizeof(c));
	//fprintf(fpin, "unsigned short		d = %hu sizeof d = %lu\n",d,sizeof(d));
	//fprintf(fpin, "size_t			e = %zu sizeof e = %lu\n",e,sizeof(e));
	//fprintf(fpin, "uintmax_t		f = %ju sizeof f = %lu\n",f,sizeof(f));
	//fprintf(fpin, "unsigned long long	g = %llu sizeof g = %lu\n\n",g,sizeof(g));

	//fprintf(fpin, "unsigned char		h = %hhu sizeof h = %lu\n", h,sizeof(h));
	//fprintf(fpin, "unsigned int		i = %u sizeof i = %lu\n",i,sizeof(i));
	//fprintf(fpin, "unsigned long		j = %lu sizeof j = %lu\n",j,sizeof(j));
	//fprintf(fpin, "unsigned short		k = %hu sizeof k = %lu\n",k,sizeof(k));
	//fprintf(fpin, "size_t			l = %zu sizeof l = %lu\n",l,sizeof(l));
	//fprintf(fpin, "uintmax_t		m = %ju sizeof m = %lu\n",m,sizeof(m));
	//fprintf(fpin, "unsigned long long	n = %llu sizeof n = %lu\n\n",n,sizeof(n));

	//fprintf(fpin, "unsigned char		o = %hhu sizeof o = %lu\n", o,sizeof(o));
	//fprintf(fpin, "unsigned int		p = %u sizeof p = %lu\n",p,sizeof(p));
	//fprintf(fpin, "unsigned long		q = %lu sizeof q = %lu\n",q,sizeof(q));
	//fprintf(fpin, "unsigned short		r = %hu sizeof r = %lu\n",r,sizeof(r));
	//fprintf(fpin, "size_t			s = %zu sizeof s = %lu\n",s,sizeof(s));
	//fprintf(fpin, "uintmax_t		t = %ju sizeof t = %lu\n",t,sizeof(t));
	//fprintf(fpin, "unsigned long long	u = %llu sizeof u = %lu\n\n",u,sizeof(u));

	//fprintf(fpin, "unsigned char		v = %hhu sizeof v = %lu\n", v,sizeof(v));
	//fprintf(fpin, "unsigned int		w = %u sizeof w = %lu\n",w,sizeof(w));
	//fprintf(fpin, "unsigned long		x = %lu sizeof x = %lu\n",x,sizeof(x));
	//fprintf(fpin, "unsigned short		y = %hu sizeof y = %lu\n",y,sizeof(y));
	//fprintf(fpin, "size_t			z = %zu sizeof z = %lu\n",z,sizeof(z));
	//fprintf(fpin, "uintmax_t		zz = %ju sizeof zz = %lu\n",zz,sizeof(zz));
	//fprintf(fpin, "unsigned long long	aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa));
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_hhhllljz.out", "w+", stdout);
	ft_printf("unsigned char		a = %hhu sizeof a = %lu\n", a,sizeof(a));
	ft_printf("unsigned int		b = %u sizeof b = %lu\n",b,sizeof(b));
	ft_printf("unsigned long		c = %lu sizeof c = %lu\n",c,sizeof(c));
	ft_printf("unsigned short		d = %hu sizeof d = %lu\n",d,sizeof(d));
	ft_printf("size_t			e = %zu sizeof e = %lu\n",e,sizeof(e));
	ft_printf("uintmax_t		f = %ju sizeof f = %lu\n",f,sizeof(f));
	ft_printf("unsigned long long	g = %llu sizeof g = %lu\n\n",g,sizeof(g));

	ft_printf("unsigned char		h = %hhu sizeof h = %lu\n", h,sizeof(h));
	ft_printf("unsigned int		i = %u sizeof i = %lu\n",i,sizeof(i));
	ft_printf("unsigned long		j = %lu sizeof j = %lu\n",j,sizeof(j));
	ft_printf("unsigned short		k = %hu sizeof k = %lu\n",k,sizeof(k));
	ft_printf("size_t			l = %zu sizeof l = %lu\n",l,sizeof(l));
	ft_printf("uintmax_t		m = %ju sizeof m = %lu\n",m,sizeof(m));
	ft_printf("unsigned long long	n = %llu sizeof n = %lu\n\n",n,sizeof(n));

	ft_printf("unsigned char		o = %hhu sizeof o = %lu\n", o,sizeof(o));
	ft_printf("unsigned int		p = %u sizeof p = %lu\n",p,sizeof(p));
	ft_printf("unsigned long		q = %lu sizeof q = %lu\n",q,sizeof(q));
	ft_printf("unsigned short		r = %hu sizeof r = %lu\n",r,sizeof(r));
	ft_printf("size_t			s = %zu sizeof s = %lu\n",s,sizeof(s));
	ft_printf("uintmax_t		t = %ju sizeof t = %lu\n",t,sizeof(t));
	ft_printf("unsigned long long	u = %llu sizeof u = %lu\n\n",u,sizeof(u));

	ft_printf("unsigned char		v = %hhu sizeof v = %lu\n", v,sizeof(v));
	ft_printf("unsigned int		w = %u sizeof w = %lu\n",w,sizeof(w));
	ft_printf("unsigned long		x = %lu sizeof x = %lu\n",x,sizeof(x));
	ft_printf("unsigned short		y = %hu sizeof y = %lu\n",y,sizeof(y));
	ft_printf("size_t			z = %zu sizeof z = %lu\n",z,sizeof(z));
	ft_printf("uintmax_t		zz = %ju sizeof zz = %lu\n",zz,sizeof(zz));
	ft_printf("unsigned long long	aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa));

	chmod("test_hhhllljz.out", 0644);
	fpin = fopen("test_hhhllljz.in", "r+");
	fpout = fopen("test_hhhllljz.out", "r+");
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
		printf("test_hhhllljz: [ok]\n");
		return 1;
	}
	printf("test_hhhllljz: [ko]\n");
	return 0;
}
