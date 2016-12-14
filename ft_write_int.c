#include "ft_printf.h"

void	ft_write_int(t_env *env, va_list ap)
{
	int di;

	di = va_arg(ap, int);
	ft_putnbr(di);

}
