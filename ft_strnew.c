/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:50:06 by kcarrot           #+#    #+#             */
/*   Updated: 2018/12/30 17:12:34 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strnew(size_t size)
{
	char *p;

	p = (char *)malloc(size + 1);
	p[size] = '\0';
	return (p);
}

unsigned char	*ft_strnew_uns(size_t size)
{
	unsigned char *p;

	p = (unsigned char *)malloc(size + 1);
	p[size] = '\0';
	return (p);
}
