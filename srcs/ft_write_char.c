#include "ft_printf.h"

void	ft_write_char(t_env *env, va_list ap)
{
	char c;

	c = va_arg(ap, char);
	ft_putchar(c);
}
