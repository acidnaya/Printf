/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:07:51 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/05 17:34:47 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	num(unsigned long int n, char *base, char **res)
{
	unsigned long int	m;
	char				*str;
	char				*tmp;

	if (n / 16 > 0)
		num(n / 16, base, res);
	m = n % 16;
	str = ft_strnew(1);
	str[0] = base[m];
	tmp = *res;
	*res = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
}

char		*take_addr(unsigned long int n)
{
	char	*base;
	char	*res;

	res = ft_strnew(0);
	base = "0123456789abcdef";
	num(n, base, &res);
	return (res);
}
