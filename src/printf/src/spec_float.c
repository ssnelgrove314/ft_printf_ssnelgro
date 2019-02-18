#include "../ft_printf.h"
#include <math.h>

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
  
// Converts a floating point number to string. 
char *ft_ftoa(long double n)
{ 
	char *res;
    // Extract integer part 

	res = ft_strnew(100);
    int ipart = (int)n; 
  
    // Extract floating part 
     long double fpart = n - (float)ipart;
	 int afterpoint = ft_numlen(ipart);
	 
  
    // convert integer part to string 
    int i = intToStr(ipart, res, 0); 
  
    // check for display option after point 
    if (afterpoint != 0) 
    { 
        res[i] = '.';  // add dot 
  
        // Get the value of fraction part upto given no. 
        // of points after dot. The third parameter is needed 
        // to handle cases like 233.007 
        fpart = fpart * pow(10, afterpoint); 
  
        intToStr((int)fpart, res + i + 1, afterpoint); 
    } 
	return (res);
} 

void ft_get_float_val(t_printf *prtf)
{
	prtf->args.val.signed_double = (double)va_arg(prtf->args.arg, double);
}

void	spec_float(t_printf *prtf)
{
	t_vector output;
    char *val;

	ft_vector_init(&output, 10);
	ft_get_float_val(prtf);
	val = ft_ftoa(prtf->args.val.double_double);
	ft_vector_append(&output, val);
	ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}