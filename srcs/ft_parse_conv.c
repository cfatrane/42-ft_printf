#include "ft_printf.h"

int	ft_parse_conv(t_env *env)
{
	if (env->str[env->cur] == 's')
		env->conv = 's';
	else if (env->str[env->cur] == 'S')
		env->conv = 'S';
	else if (env->str[env->cur] == 'p')
		env->conv = 'p';
	else if (env->str[env->cur] == 'd')
		env->conv = 'd';
	else if (env->str[env->cur] == 'D')
		env->conv = 'D';
	else if (env->str[env->cur] == 'i')
		env->conv = 'i';
	else if (env->str[env->cur] == 'o')
		env->conv = 'o';
	else if (env->str[env->cur] == 'O')
		env->conv = 'O';
	else if (env->str[env->cur] == 'u')
		env->conv = 'u';
	else if (env->str[env->cur] == 'U')
		env->conv = 'U';
	else if (env->str[env->cur] == 'x')
		env->conv = 'x';
	else if (env->str[env->cur] == 'X')
		env->conv = 'X';
	else if (env->str[env->cur] == 'c')
		env->conv = 'c';
	else if (env->str[env->cur] == 'C')
		env->conv = 'C';
	return (0);
}
