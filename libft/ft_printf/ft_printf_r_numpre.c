/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_r_numpre.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:49:36 by ndombre           #+#    #+#             */
/*   Updated: 2017/03/01 11:42:52 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_printf_numpre_p(char *str, int *neg)
{
	*neg = *str;
	*str = '0';
}

static char	*ft_freenl(void *ptr)
{
	ft_free(ptr);
	return (NULL);
}

char		*ft_printf_numpre(char *str, t_printfpara *p)
{
	size_t	i;
	char	*s;
	size_t	n;
	int		neg;

	i = ft_strlen(str);
	if (!(i - (*str == '-') < p->pre && p->type != 's' && p->pre != 4294967295))
		return (str);
	neg = 0;
	if (*str == '-')
		ft_printf_numpre_p(str, &neg);
	if ((s = ft_malloc(p->pre - i + 1)) == NULL)
		return (ft_freenl(str));
	n = 0;
	while (n < p->pre - i)
		s[n++] = '0';
	s[n] = '\0';
	if ((str = ft_strjoinff(s, str)) == NULL)
		return (NULL);
	if (neg != 0)
		str = ft_strjoinnf("-", str);
	return (str);
}
