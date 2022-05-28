/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:26:30 by jfriesen          #+#    #+#             */
/*   Updated: 2018/12/27 19:36:15 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_zeros_right(char **s, size_t width)
{
	int		len;
	char	*space;
	char	*result;

	space = NULL;
	result = NULL;
	len = width - ft_strlen(*s);
	if (!(space = ft_strnew(len)))
		return ;
	while (len > 0)
	{
		space[len - 1] = '0';
		len--;
	}
	result = ft_strjoin(*s, space);
	free(*s);
	free(space);
	*s = result;
}

void	ft_add_zeros_left(char **s, size_t width)
{
	int		len;
	char	*space;
	char	*new;

	space = NULL;
	new = NULL;
	len = width - ft_strlen(*s);
	if (!(space = ft_strnew(len)))
		return ;
	while (len > 0)
	{
		space[len - 1] = '0';
		len--;
	}
	new = ft_strjoin(space, *s);
	free(*s);
	free(space);
	*s = new;
}

void	ft_add_spaces_right(char **s, size_t width)
{
	int		len;
	char	*space;
	char	*result;

	space = NULL;
	result = NULL;
	len = width - ft_strlen(*s);
	if (!(space = ft_strnew(len)))
		return ;
	while (len > 0)
	{
		space[len - 1] = ' ';
		len--;
	}
	result = ft_strjoin(*s, space);
	free(*s);
	free(space);
	*s = result;
}

void	ft_add_spaces_left(char **s, size_t width)
{
	int		len;
	char	*space;
	char	*new;

	space = NULL;
	new = NULL;
	len = width - ft_strlen(*s);
	if (!(space = ft_strnew(len)))
		return ;
	while (len > 0)
	{
		space[len - 1] = ' ';
		len--;
	}
	new = ft_strjoin(space, *s);
	free(*s);
	free(space);
	*s = new;
}

void	ft_after_sharp(char **res, int w)
{
	char *cpy;
	char s[3];

	s[0] = **res;
	s[1] = *(*res + 1);
	s[2] = '\0';
	cpy = ft_strsub(*res, 2, ft_strlen(*res) - 2);
	free(*res);
	ft_add_zeros_left(&cpy, w - 2);
	*res = ft_strjoin(s, cpy);
}
