/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:57:06 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/22 14:59:00 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	setyear(t_htime *t, uintmax_t *day)
{
	uintmax_t	nbjour;

	nbjour = 365;
	while (*day > nbjour)
	{
		*day -= nbjour;
		t->year++;
		nbjour = 365 + (t->year % 4 == 0);
	}
}

static void	setmoth(t_htime *t, uintmax_t *day)
{
	int	nbjour;

	nbjour = 31;
	while ((int)*day > nbjour)
	{
		*day -= nbjour;
		t->moth++;
		if (t->moth == 1)
			nbjour = 28 + (t->year % 4 == 0);
		else if (t->moth == 2 || t->moth == 4 || t->moth == 6 ||
				t->moth == 7 || t->moth == 9 || t->moth == 11)
			nbjour = 31;
		else
			nbjour = 30;
	}
}

t_htime		gethtime(time_t t, int local)
{
	t_htime		ret;
	uintmax_t	hour;
	uintmax_t	day;

	ret.sec = t % 60;
	ret.min = (t / 60) % 60;
	hour = t / (60 * 60) + local;
	ret.hour = hour % 24;
	day = hour / 24;
	ret.year = 1970;
	ret.moth = 0;
	ret.dayname = (day - 4) % 7;
	setyear(&ret, &day);
	setmoth(&ret, &day);
	ret.moth++;
	ret.day = day + 1;
	ret.zone = local;
	return (ret);
}
