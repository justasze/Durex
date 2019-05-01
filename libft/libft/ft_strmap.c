/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:25:57 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/08 09:28:59 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = ft_strdup(s);
	if (ret == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = (*f)(s[i]);
		i++;
	}
	return (ret);
}
