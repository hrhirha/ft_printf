#include "ft_printf.h"

void	ft_handle_flags(t_form *form)
{
	size_t	i;

	i = 0;
	while (form->flags[i])
	{
		while (form->flags[i] == form->copy[form->pos])
		{
			while (form->copy[form->pos] == '-' && form->pos++)
				form->flag[0] = '-';
			while (form->copy[form->pos] == '0' && form->pos++)
				form->flag[1] = '0';
			i = 0;
		}
		i++;
	}
}
