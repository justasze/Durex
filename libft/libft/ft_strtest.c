/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:49:48 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 13:03:58 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strtest(char const *tab, int (*f)(int))
{
	while (*tab != '\0')
	{
		if ((*f)((int)*tab) == 0)
			return (0);
		tab++;
	}
	return (1);
}
