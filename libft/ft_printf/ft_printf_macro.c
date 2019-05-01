/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_macro.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:27:33 by ndombre           #+#    #+#             */
/*   Updated: 2017/02/22 18:43:54 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static const char		*g_tab[][2] = {{"{eoc}", "\x1B[0m"},
	{"{R}", "\x1B[0m"},
	{"{black}", "\x1B[30m"},
	{"{red}", "\x1B[31m"},
	{"{green}", "\x1B[32m"},
	{"{yellow}", "\x1B[33m"},
	{"{blue}", "\x1B[34m"},
	{"{magenta}", "\x1B[35m"},
	{"{cyan}", "\x1B[36m"},
	{"{white}", "\x1B[37m"},
	{"{BLACK}", "\x1B[40m"},
	{"{RED}", "\x1B[41m"},
	{"{GREEN}", "\x1B[42m"},
	{"{YELLOW}", "\x1B[43m"},
	{"{BLUE}", "\x1B[44m"},
	{"{MAGENTA}", "\x1B[45m"},
	{"{CYAN}", "\x1B[46m"},
	{"{WHITE}", "\x1B[47m"},
	{"{RV}", "\x1B[7m"},
	{"{_}", "\x1B[4m"},
	{"{BO}", "\x1B[1m"},
	{0, 0}};

int						ft_printf_color(char **str, int *r)
{
	int	i;
	int	j;

	i = 0;
	while (g_tab[i][0])
	{
		j = 0;
		while (g_tab[i][0][j] && (*str)[j] && g_tab[i][0][j] == (*str)[j])
			j++;
		if (g_tab[i][0][j] == '\0')
		{
			(*str) += ft_strlen(g_tab[i][0]);
			ft_putstr(g_tab[i][1]);
			*r = ft_strlen(g_tab[i][1]);
			return (1);
		}
		i++;
	}
	return (0);
}
