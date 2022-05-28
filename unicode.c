/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:19:09 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/05 16:05:00 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*octet_4(int num)
{
	unsigned char	*s;

	s = NULL;
	s = (unsigned char *)malloc(5 * sizeof(unsigned char));
	s[0] = 240 + num / 32768;
	num %= 32768;
	s[1] = 128 + num / 4096;
	num %= 4096;
	s[2] = 128 + num / 64;
	s[3] = 128 + num % 64;
	s[4] = '\0';
	return (s);
}

unsigned char	*octet_3(int num)
{
	unsigned char	*s;

	s = NULL;
	s = (unsigned char *)malloc(4 * sizeof(unsigned char));
	s[0] = 224 + num / 4096;
	num %= 4096;
	s[1] = 128 + num / 64;
	s[2] = 128 + num % 64;
	s[3] = '\0';
	return (s);
}

unsigned char	*octet_2(int num)
{
	unsigned char	*s;

	s = NULL;
	s = (unsigned char *)malloc(3 * sizeof(unsigned char));
	s[0] = 192 + num / 64;
	s[1] = 128 + num % 64;
	s[2] = '\0';
	return (s);
}

unsigned char	*octet(int num)
{
	unsigned char	*s;

	s = NULL;
	s = (unsigned char *)malloc(2 * sizeof(unsigned char));
	s[0] = (unsigned char)num;
	s[1] = '\0';
	return (s);
}

unsigned char	*unicode(int num, t_flags *fl)
{
	unsigned char	*res;
	int				i;

	res = NULL;
	res = (num > 31 && num < 256) ? octet(num) : res;
	if ((num >= 0 && num <= 31) || num == 127)
	{
		res = (unsigned char *)malloc(3 * sizeof(unsigned char));
		res[0] = '^';
		res[1] = (num == 127) ? '?' : num + 64;
		res[2] = '\0';
		if (fl)
			fl->width += (fl->width) ? 1 : 0;
	}
	res = ((num >= 256) && (num <= 2047)) ? octet_2(num) : res;
	res = ((num >= 2048) && (num <= 65535)) ? octet_3(num) : res;
	res = ((num >= 65536) && (num <= 1114111)) ? octet_4(num) : res;
	return (res);
}
