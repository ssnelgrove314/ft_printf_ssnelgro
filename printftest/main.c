/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:24:57 by lle-blev          #+#    #+#             */
/*   Updated: 2016/12/19 20:27:55 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tests.h"
#include <locale.h>
int             main( void ) {

        unsigned int    count = 0;

        printf("Testing %%c\n");
        count += test_c();
        printf("Testing %%d\n");
        count += test_d();
        printf("Testing widths\n");
        count += test_hhhllljz();
        printf("Testing %%i\n");
        count += test_i();
        printf("Testing %%C\n");
        count += test_lc();
        printf("Testing %%S\n");
        count += test_ls();
        printf("Testing %%D\n");
        count += test_ld();
        printf("Testing minus\n");
        count += test_minus();
        printf("Testing mix (%%d %%s %%p)\n");
        count += test_mix();
        printf("Testing mix2 (%%d %%C %%s %%d %%u %%X %%c)\n");
        count += test_mix2();
        printf("Testing %%o\n");
        count += test_o();
        printf("Testing %%p\n");
        count += test_p();
        printf("Testing plus\n");
        count += test_plus();
        printf("Testing precision\n");
        count += test_precision();
        printf("Testing #\n");
        count += test_sharp();
        printf("Testing space\n");
        count += test_space();
        printf("Testing %%u\n");
        count += test_u();
        printf("Testing %%x\n");
        count += test_x();
        printf("Testing 0\n");
        count += test_zero();
        printf("Testing %%s\n");
        count += test_s();

        printf("Bonus:\n\n");
        printf("Testing *\n");
        count += test_star();
        printf("Testing %%a\n");
        count += test_a();
        printf("Testing %%e\n");
        count += test_e();
        printf("Testing %%f\n");
        count += test_f();
        printf("Testing %%g\n");
        count += test_g();
        printf("Testing %%Le\n");
        count += test_l();
        printf("Testing %%n\n");
        count += test_n();
        return 0;
}
