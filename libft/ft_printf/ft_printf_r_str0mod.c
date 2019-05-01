/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_r_str0mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:34:27 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/23 13:34:54 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_printf_str0mod_p(char *str, t_printfpara *p,
		size_t *i, size_t *size)
{
	if (!p->filw0 || p->ljustifi == 1)
		return (-1);
	*i = ft_strlen(str);
	if ((p->hachtag && (p->conv == 'x' || p->conv == 'X')) || p->conv == 'p')
		*size -= 2;
	if (p->hachtag && (p->conv == 'o' || p->conv == 'O'))
		*size -= 1;
	if (*i >= *size)
		return (-1);
	return (1);
}

static void	setsigne(char *str, char *signe)
{
	*signe = *str;
	*str = '0';
}

char		*ft_printf_str0mod(char *str, t_printfpara *p)
{
	size_t	i;
	char	*s;
	size_t	n;
	char	signe;
	size_t	size;

	size = p->len;
	if (ft_printf_str0mod_p(str, p, &i, &size) != 1)
		return (str);
	signe = 0;
	if (*str == '-' || *str == '+' || *str == ' ')
		setsigne(str, &signe);
	if ((s = ft_malloc(size - i + 1)) == NULL)
	{
		ft_free(str);
		return (NULL);
	}
	n = 0;
	while (n < size - i)
		s[n++] = '0';
	s[n] = '\0';
	str = ft_strjoinff(s, str);
	if (signe != 0)
		*str = signe;
	return (str);
}
