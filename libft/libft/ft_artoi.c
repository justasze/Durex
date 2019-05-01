/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_artoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:50:57 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/30 14:00:38 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_artoi_r(unsigned int ret, int signe, int *err)
{
	if (signe == 0 || signe == 1 || signe == -1)
		*err = 1;
	if (ret > 2147483647 && signe > 0)
		*err = 1;
	if (ret > 2147483648 && signe < 0)
		*err = 1;
	if (signe < 0)
		return (-ret);
	return (ret);
}

int			ft_artoi(char *c, int *err)
{
	unsigned int	ret;
	int				s;

	ret = 0;
	s = 0;
	while (*c != '\0')
	{
		if (*c >= '0' && *c <= '9' && ret < 2147483648)
		{
			ret = 10 * ret + (*c - '0');
			s = ((s >= 0) ? 2 : -2);
		}
		else if (*c == '+' && s == 0 && ret == 0)
			s = 1;
		else if (*c == '-' && s == 0 && ret == 0)
			s = -1;
		else if (ret == 0 && s == 0 && (*c == ' ' || *c == '\t' || *c == '\n' ||
					*c == 13 || *c == 12 || *c == '\v' || *c == '\r'))
			;
		else
			*err = 1;
		c++;
	}
	return (ft_artoi_r(ret, s, err));
}
