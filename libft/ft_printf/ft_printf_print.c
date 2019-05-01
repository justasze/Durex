/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:50:27 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/23 14:57:46 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

intmax_t	ft_printf_getmi(t_printfpara *p, va_list vl)
{
	if (p->h == 'h')
		return ((short)va_arg(vl, int));
	if (p->h == 's')
		return ((char)va_arg(vl, int));
	if (p->h == 'l' || p->conv == 'D')
		return (va_arg(vl, long int));
	if (p->h == 'e')
		return (va_arg(vl, long long int));
	if (p->h == 'j')
		return (va_arg(vl, intmax_t));
	if (p->h == 'z')
		return (va_arg(vl, ssize_t));
	if (p->conv == 'd' || p->conv == 'i')
		return (va_arg(vl, int));
	if (p->conv == 'c')
		return ((char)va_arg(vl, int));
	if (p->conv == 'C')
		return (va_arg(vl, wchar_t));
	return (0);
}

uintmax_t	ft_printf_getmu(t_printfpara *p, va_list vl)
{
	if (p->h == 'h')
		return ((unsigned short)va_arg(vl, int));
	if (p->h == 's')
		return ((unsigned char)va_arg(vl, int));
	if (p->h == 's')
		return ((unsigned char)va_arg(vl, int));
	if (p->h == 'l' || p->conv == 'O' || p->conv == 'U' || p->conv == 'B')
		return (va_arg(vl, unsigned long int));
	if (p->h == 'e')
		return (va_arg(vl, unsigned long long int));
	if (p->h == 'j')
		return (va_arg(vl, uintmax_t));
	if (p->h == 'z')
		return (va_arg(vl, size_t));
	if (p->conv == 'o' || p->conv == 'u' || p->conv == 'x' || p->conv == 'X' ||
			p->conv == 'b')
		return (va_arg(vl, unsigned int));
	if (p->conv == 'p')
		return ((uintmax_t)va_arg(vl, void*));
	return (0);
}

char		*ft_printf_print2(t_printfpara *p, va_list args)
{
	if (p->conv == 'c' || p->conv == 'C')
		return (ft_wcntoms(ft_printf_getmi(p, args), p->pre));
	if (p->conv == 'd' || p->conv == 'D' || p->conv == 'i')
		return (ft_mitoa(ft_printf_getmi(p, args)));
	if (p->conv == 'o' || p->conv == 'O')
		return (ft_mutoa_base(ft_printf_getmu(p, args), 8));
	if (p->conv == 'b' || p->conv == 'B')
		return (ft_mutoa_base(ft_printf_getmu(p, args), 2));
	if (p->conv == 'u' || p->conv == 'U')
		return (ft_mutoa(ft_printf_getmu(p, args)));
	if (p->conv == 'x')
		return (ft_mutoa_base(ft_printf_getmu(p, args), 16));
	if (p->conv == 'X')
		return (ft_mutoa_mbase(ft_printf_getmu(p, args), 16));
	if (p->conv == '%')
		return (ft_strdup("%"));
	return (NULL);
}

char		*ft_printf_print1(t_printfpara *p, va_list args)
{
	if (p->conv == 'p')
		return (ft_mutoa_base(ft_printf_getmu(p, args), 16));
	if (p->conv == 'r')
		return (ft_printf_spechar((char*)va_arg(args, char*)));
	if (p->conv == 'k')
	{
		ft_print_time(gethtime(va_arg(args, time_t), 1));
		return (ft_strdup(""));
	}
	return (NULL);
}

char		*ft_printf_print(t_printfpara *p, va_list args)
{
	void *ptr;

	if (p->conv == 'S' || (p->conv == 's' && p->h == 'l'))
	{
		ptr = (void*)va_arg(args, wchar_t*);
		if (ptr == NULL)
			return (ft_strdup("(null)"));
		return (ft_wcsntostr(ptr, p->pre));
	}
	if (p->conv == 's')
	{
		ptr = (void*)va_arg(args, char*);
		if (ptr == NULL)
			return (ft_strdup("(null)"));
		return (ft_strdup(ptr));
	}
	ptr = ft_printf_print1(p, args);
	if (ptr != NULL)
		return (ptr);
	ptr = ft_printf_print2(p, args);
	return (ptr);
}
