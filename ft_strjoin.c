/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:46:21 by jfriesen          #+#    #+#             */
/*   Updated: 2018/12/30 17:35:59 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	new = NULL;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		new[i] = *s2;
		i++;
		s2++;
	}
	new[i] = '\0';
	return (new);
}

unsigned char	*ft_strjoin_uns(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*new;
	unsigned char	*res;

	new = NULL;
	if (!s1 || !s2)
		return (NULL);
	if (!(new = (unsigned char*)malloc(sizeof(char) *
		(ft_strlen_u(s1) + ft_strlen_u(s2) + 1))))
		return (NULL);
	res = new;
	while (*s1)
	{
		*new = *s1;
		s1++;
		new++;
	}
	while (*s2)
	{
		*new = *s2;
		s2++;
		new++;
	}
	*new = '\0';
	return (res);
}
