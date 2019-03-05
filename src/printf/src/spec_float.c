#include "../ft_printf.h"
#include <math.h>
#define DABS(x) (((x) < 0.0f) ? (-x) : (x))
#define UPPER(x) ((x)=='X'||(x)=='F'||(x)=='E'||(x)=='G'||(x)=='A')

uintmax_t		ft_pw(uintmax_t nb, uintmax_t power)
{
	uintmax_t i;

	if (power == 0)
		return (1);
	if (power % 2 == 0)
	{
		i = ft_pw(nb, power / 2);
		return (i * i);
	}
	else
		return (nb * ft_pw(nb, power - 1));
}

void reverse(char *str, int len) 
{ 
    int i=0, j=len-1, temp; 
    while (i<j) 
    { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; j--; 
    } 
} 
  
 // Converts a given integer x to string str[].  d is the number 
 // of digits required in output. If d is more than the number 
 // of digits in x, then 0s are added at the beginning. 
int intToStr(int x, char str[], int d) 
{ 
    int i = 0; 
    while (x) 
    { 
        str[i++] = (x%10) + '0'; 
        x = x/10; 
    } 
  
    // If number of digits required is more, then 
    // add 0s at the beginning 
    while (i < d) 
        str[i++] = '0'; 
  
    reverse(str, i); 
    str[i] = '\0'; 
    return i; 
} 

int get_int_len(uintmax_t nbr)
{
	int num;

	num = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		num++;
	}
	return (num);
}

void			pf_ldtoa_int_base(t_printf *prtf, uintmax_t nbr, int int_len,
									char *res)
{
	char		char_case;
	int			base;
	int			tmp_len;
	int			len_diff;
	// size_t		len_diff;

	base = 10;
	char_case = ('a' - 10 - (('a' - 'A') * UPPER(prtf->args.spec)));
	tmp_len = get_int_len(nbr);
	len_diff = int_len - tmp_len;
	int_len = tmp_len + ((prtf->args.neg == 1) ? 1 : 0);
	while (int_len-- > (prtf->args.neg ==1) ? 1 : 0)
	{
		res[int_len] = (nbr % base) + ((nbr % base < 10) ? '0' : char_case);
		nbr /= base;
	}
	while (len_diff--)
	{
		res[tmp_len++] = (nbr % base) + ((nbr % base < 10) ? '0' : char_case);
	}
}


// Converts a floating point number to string. 
char *ft_ftoa(t_printf *prtf, long double n)
{ 
	char		*res;
	long double	frac;
	int			base;
	int			int_len;
	int			tot_len;
	int			neg;

	base = 10;
	prtf->args.neg = 0;
	int_len = 0;
	neg = 0;
	res = (char*)malloc(sizeof(char) * 59);
	tot_len = (prtf->args.precision != 0 || prtf->args.flags & PF_ALT_FORM) ? 1 : 0;
	if (n < 0)
	{
		n *= -1;
		neg = 1;
		int_len++;
		prtf->args.neg = 1;
	}
	if (n == 0)
		int_len = 1;
	while ((uintmax_t)n > 0)
	{
		int_len++;
		n /= 10;
	}
	tot_len += int_len + prtf->args.precision;
	// pf_ldtoa_int_base(prtf, (uintmax_t)DABS(n), int_len, res);
	if (prtf->args.precision != 0)
	{
		prtf->args.precision++;
		frac = (DABS(n) - (uintmax_t)DABS(n)) * ft_pw(base, prtf->args.precision + int_len);
		frac = ((uintmax_t)DABS(frac) % base >= (uintmax_t)(base / 2)) ?
			(frac / base) + 1 : frac / base;
		pf_ldtoa_int_base(prtf, (uintmax_t)DABS(frac), tot_len, res);
	}
	if (prtf->args.precision != 0 || prtf->args.flags & PF_ALT_FORM)
	{
		char tmp = res[int_len];

		res[int_len] = '.';
		int_len++;
		tot_len--;
		while (tot_len > int_len)
		{
			res[tot_len] = res[tot_len - 1];
			tot_len--;
		}
		res[int_len] = tmp;
	}
	if (neg)
		res[0] = '-';
	return (res);
} 

void ft_get_float_val(t_printf *prtf)
{
	prtf->args.val.double_double = va_arg(prtf->args.arg, double);
}

void	spec_float(t_printf *prtf)
{
	t_vector output;
    char *val;

	ft_vector_init(&output, 10);
	ft_get_float_val(prtf);
    if (prtf->args.precision <= 0)
        prtf->args.precision = 6;
	val = ft_ftoa(prtf, prtf->args.val.double_double);
	ft_vector_append(&output, val);
	ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}