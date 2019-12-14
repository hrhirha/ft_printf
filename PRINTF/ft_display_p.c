/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:21:55 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/14 12:41:24 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	zero_flag_and_noflag(t_form *form, int *gap, char **s)
{
	char *tmp;
	char *tmp1;

	tmp1 = NULL;
	if (form->flag[1] == '0' && form->width > *gap && form->precision < 0)
	{
		tmp = *s;
		tmp1 = fill(gap, form->width, '0');
		*s = ft_strjoin(tmp1, *s);
		free(tmp1);
		free(tmp);
	}
	if (form->width > 0 && form->flag[0] != '-')
	{
		tmp = *s;
		tmp1 = fill(gap, form->width, ' ');
		*s = ft_strjoin(tmp1, *s);
		free(tmp1);
		free(tmp);
	}
}

void			ft_display_p(t_form *form)
{
	void	*ptr;
	char	*s;
	char	*tmp;
	char	*tmp1;
	int		gap;

	ptr = va_arg(form->args, void *);
	s = ft_putptr(ptr);
	gap = ft_strlen(s);
	if (form->flag[0] == '-' && form->width > 0)
	{
		tmp = s;
		tmp1 = fill(&gap, form->width, ' ');
		s = ft_strjoin(s, tmp1);
		free(tmp1);
		free(tmp);
	}
	zero_flag_and_noflag(form, &gap, &s);
	form->count += ft_strlen(s);
	ft_putstr(s);
	free(s);
}
