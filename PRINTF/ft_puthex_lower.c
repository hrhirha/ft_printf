/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:18:20 by hrhirha           #+#    #+#             */
/*   Updated: 2019/12/01 16:22:51 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_malloc_len(unsigned int u_nbr)
{
	int ret;

	ret = 0;
	while (u_nbr != 0)
	{
		u_nbr /= 16;
		ret++;
	}
	return (ret);
}

char		*ft_puthex_lower(int nbr)
{
	unsigned int	u_nbr;
	char			*digits;
	char			*str;
	int				i;

	u_nbr = (unsigned int)nbr;
	digits = "0123456789abcdef";
	i = ft_malloc_len(u_nbr);
	if (!(str = malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	while (i-- >= 0 && u_nbr != 0)
	{
		str[i] = digits[u_nbr % 16];
		u_nbr /= 16;
	}
	return (str);
}
