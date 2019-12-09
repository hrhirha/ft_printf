#include "ft_printf.h"

void	ft_neg(t_form *form, int *i)
{
	if (*i < 0)
	{
		*i *= -1;
		form->count++;
		form->width--;
	}
}

char	*fill(int *i, int width, int c)
{
	int		len;
	int		index;
	char	*s;

	index = 0;
	len = width - *i;
	s = malloc(len + 1);
	while (index < len)
	{
		s[index++] = c;
		*i += 1;
	}
	s[index] = '\0';
	return (s);
}

void	diplay_prec(t_form *form, int *i, int *gap, char **s)
{
	int		neg_i;
	char	*str_i;

	neg_i = *i;
	if (form->precision == 0)
		*s = ft_itoa(*i);
	else if (form->precision > 0)
	{
		ft_neg(form, i);
		str_i = ft_itoa(*i);
		*gap = ft_strlen(str_i);
		if (*i == 0)
			str_i = "";
		*s = ft_strjoin(fill(gap, form->precision, '0'), str_i);
		if (neg_i < 0)
			*s = ft_strjoin("-", *s);
	}
}

void	ft_display_d(t_form *form)
{
	int		i;
	char	*s;
	char	*tmp;
	int		gap;
	
	tmp = NULL;
	i = va_arg(form->args, int);
	s = ft_itoa(i);
	gap = ft_strlen(ft_itoa(i));
	diplay_prec(form, &i, &gap, &s);
	tmp = s;
	if (form->flag[0] == '-' && form->width > 0 && i > 0)
		s = ft_strjoin(s, fill(&gap, form->width, ' '));
	else if (form->width > 0 && form->flag[0] != '-' && i > 0)
		s = ft_strjoin(fill(&gap, form->width, ' '), s);
	free(tmp);
	form->count += ft_strlen(s);
	ft_putstr(s);
}