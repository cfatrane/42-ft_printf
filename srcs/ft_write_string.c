#include "ft_printf.h"

void	ft_write_string(t_env *env, va_list ap)
{
	char	*str;
	size_t	len;

	str = va_arg(ap, char *);
	ft_putstr(str);
}
