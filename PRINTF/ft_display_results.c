#include "ft_printf.h"

void	ft_display_results(t_form *form)
{
	char c;

	c = form->conv;
	if (c == 'c')
		ft_display_c(form);
//	else if (c == 's')
//		ft_display_s(form);
	else if (c == 'd' || c == 'i')
		ft_display_d(form);
//	else if (c == 'u')
//		ft_display_u(form);
//	else if (c == 'x')
//		ft_display_x(form);
//	else if (c == 'X')
//		ft_display_X(form);
//	else if (c == 'p')
//		ft_display_p(form);
}
