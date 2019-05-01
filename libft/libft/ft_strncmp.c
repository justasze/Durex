/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 19:27:48 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/13 11:32:46 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char const *s1, char const *s2, unsigned int n)
{
	while (42)
	{
		if (n == 0)
			return (0);
		if (*s1 == *s2)
		{
			if (*s1 == '\0')
				return (0);
			s1++;
			s2++;
			n--;
			continue ;
		}
		return (*((unsigned char*)s1) - *((unsigned char*)s2));
	}
}
