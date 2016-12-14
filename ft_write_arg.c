#include "ft_printf.h"

void	ft_write_arg(t_env *env, va_list ap)
{
	if ((env->conv == 's') || (env->conv == 'p') || (env->conv == 'd') || (env->conv == 'i') || (env->conv == 'o') || (env->conv == 'u') || (env->conv == 'x') ||  (env->conv == 'c'))
		ft_write_min(env, ap);





}

void	ft_write_min(t_env *env, va_list ap)
{
	if (env->conv == 's')
	{
		ft_write_string(env, ap);
	}
	else if (env->conv == 'p')
	{
		ft_write_adress(env, ap);
	}
	else if (env->conv == 'd' || env->conv == 'i')
	{
		ft_write_int(env, ap);
	}
	else if (env->conv == 'o')
	{

	}
	else if (env->conv == 'u')
	{
		ft_write_dec(env, ap);
	}
	else if (env->conv == 'x')
	{
		ft_write_hexa(env, ap);
	}
	else if (env->conv == 'c')
	{
		ft_write_char(env, ap);
	}
}
