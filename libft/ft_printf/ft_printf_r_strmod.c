/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_r_strmod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:32:50 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/22 11:29:26 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*ft_printf_strmod(char *str, t_printfpara *p)
{
	size_t	i;
	char	*s;
	size_t	n;

	i = ft_strlen(str);
	if (i < p->len)
	{
		s = ft_malloc(p->len - i + 1);
		if (s == NULL)
		{
			ft_free(str);
			return (NULL);
		}
		n = 0;
		while (n < p->len - i)
			s[n++] = ' ';
		s[n] = '\0';
		if (p->ljustifi)
			str = ft_strjoinff(str, s);
		else
			str = ft_strjoinff(s, str);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}
