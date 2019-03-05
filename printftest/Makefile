SRCT		=	main.c \
				test_a.c \
				test_c.c \
				test_d.c \
				test_e.c \
				test_f.c \
				test_g.c \
				test_hhhllljz.c \
				test_i.c \
				test_l.c \
				test_lc.c \
				test_ls.c \
				test_minus.c \
				test_mix.c \
				test_n.c \
				test_o.c \
				test_p.c \
				test_plus.c \
				test_precision.c \
				test_s.c \
				test_sharp.c \
				test_space.c \
				test_star.c \
				test_u.c \
				test_x.c \
				test_ld.c \
				test_mix2.c \
				test_zero.c


OBJT		= $(SRCT:.c=.o)

NAMET		=	test_printf

CC			=	gcc
CFLAGS		+=	 -g3 -w

LD			=	gcc

ARFLAGS		=	rcs
AR			=	ar $(ARFLAGS)

RM			=	/bin/rm

all			:	$(OBJT)
				python clean.py  2>/dev/null || true
				echo "--split--"
				make -C ../
				echo "--end-split--"
				cp ../libftprintf.a .  2>/dev/null || true
				cp ../libft/libft.a .  2>/dev/null || true
			    	$(CC) $(CFLAGS) -o $(NAMET) $(OBJT) -L. -lftprintf -lft
				-./test_printf

.SILENT : all

clean		:
				$(RM) -f $(OBJT)

fclean		:	clean
				$(RM) -f $(NAMET)

re			:	fclean all
