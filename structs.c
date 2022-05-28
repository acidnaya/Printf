/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:07:39 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/06 17:24:00 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*new_struct(void)
{
	t_flags	*new;

	if (!(new = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	new->space = 0;
	new->plus = 0;
	new->minus = 0;
	new->zero = 0;
	new->sharp = 0;
	new->color = 0;
	new->width = 0;
	new->pres = -1;
	new->len = ft_strnew(2);
	(new->len)[0] = '\0';
	return (new);
}
