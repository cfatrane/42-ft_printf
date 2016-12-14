#include "ft_printf.h"

int	ft_reader(t_env *env; va_list ap)
{
	while (env->str[env->cur] != '\0')
	{
		if (env->str[env->cur] == '%')
		{
			ft_parse(env, ap);

		}


		env->cur++;
	}



	return (0);
}


int	ft_parse(t_env *env, va_list ap)
{
	ft_parse_conv(env);
	ft_parse_attr(env);



}
