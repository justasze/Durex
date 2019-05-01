/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:33:39 by ndombre           #+#    #+#             */
/*   Updated: 2017/03/06 13:14:06 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft.h"
#include <stdlib.h>

static int	ft_getpara(char **tab, t_printfpara *p, va_list args)
{
	ft_bzero(p, sizeof(t_printfpara));
	p->pre = 4294967295;
	ft_printf_flag(tab, p);
	ft_printf_minlen(tab, p, args);
	ft_printf_presition(tab, p, args);
	ft_printf_modlen(tab, p);
	ft_printf_conversion(tab, p);
	if (p->conv == 0)
		return (-1);
	return (1);
}

static int	ft_printf_prosses(char **str, t_printfpara *p, int *ret,
		int fd)
{
	int bz;

	bz = (**str == '\0');
	ft_printf_strpre(*str, p);
	if ((*str = ft_printf_numpre(*str, p)) == NULL)
		return (-1);
	if ((*str = ft_printf_numsigne(*str, p)) == NULL)
		return (-1);
	if ((*str = ft_printf_str0mod(*str, p)) == NULL)
		return (-1);
	if ((*str = ft_printf_strprefix(*str, p)) == NULL)
		return (-1);
	if ((*str = ft_printf_strmod(*str, p)) == NULL)
		return (-1);
	ft_putstr_fd(*str, fd);
	if ((p->conv == 'c' || p->conv == 'C') && bz && p->ljustifi == 0)
		ft_putchar('\0');
	if (p->conv == 'k')
		*ret = 26;
	return (1);
}

static int	ft_printcomp(char **tab, va_list args, int fd)
{
	t_printfpara	p;
	char			*str;
	int				ret;

	ret = 0;
	if (ft_getpara(tab, &p, args) != 1)
		return (-1);
	ft_printf_incompatible_flag(&p);
	if ((str = ft_printf_print(&p, args)) == NULL)
		return (-1);
	if ((p.conv == 'c' || p.conv == 'C') && *str == '\0')
	{
		if (p.pre != 4294967295 && p.pre > 0)
			p.pre--;
		if (p.len > 0)
			p.len--;
		ret++;
		if (p.ljustifi == 1)
			ft_putchar('\0');
	}
	if (ft_printf_prosses(&str, &p, &ret, fd) == -1)
		return (-1);
	ret += ft_strlen(str);
	free(str);
	return (ret);
}

static int	ft_printfargs(char *tab, va_list args, int fd)
{
	int nbprint;
	int retpara;

	nbprint = 0;
	while (*tab != '\0')
	{
		retpara = 1;
		if (*tab == '%')
		{
			if (*++tab == '%')
			{
				tab++;
				ft_putchar('%');
			}
			else if ((retpara = ft_printcomp(&tab, args, fd)) == -1)
				return (-1);
		}
		else if (ft_printf_color(&tab, &retpara) == 1)
			;
		else
			ft_putchar(*tab++);
		nbprint += retpara;
	}
	return (nbprint);
}

int			ft_printf(char *tab, ...)
{
	int		ret;
	va_list	args;

	va_start(args, tab);
	ret = ft_printfargs(tab, args, 1);
	va_end(args);
	return (ret);
}
