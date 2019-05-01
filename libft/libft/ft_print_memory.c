/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:14:19 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/12 17:24:07 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_data(const void *d, size_t n)
{
	size_t i;

	i = 0;
	while (i < 16)
	{
		if (i < n)
		{
			if (((unsigned char*)d)[i] < 16)
				ft_putchar('0');
			ft_puthex(((unsigned char*)d)[i]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

static void		print_str(unsigned char const *d, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (d[i] <= '~' && d[i] >= ' ')
			ft_putchar(d[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void			ft_print_memory(const void *addr, size_t size)
{
	int ps;

	while (size > 0)
	{
		if (size >= 16)
			ps = 16;
		else
			ps = size;
		print_data(addr, ps);
		print_str((unsigned char const*)addr, ps);
		ft_putchar('\n');
		if (size >= 16)
			size -= 16;
		else
			size = 0;
		addr += 16;
	}
}
