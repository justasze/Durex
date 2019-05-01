/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:57:42 by ndombre           #+#    #+#             */
/*   Updated: 2017/07/29 14:47:05 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct	s_printfpara
{
	char			ljustifi;
	char			forcedispsigne;
	char			forcespaceorsigne;
	char			filw0;
	char			hachtag;
	unsigned int	len;
	unsigned int	pre;
	int				h;
	char			conv;
	char			type;
}				t_printfpara;

int				ft_fprintf(int fd, char *tab, ...);
int				ft_printf(char *str, ...);
void			ft_printf_flag(char **tab, t_printfpara *p);
void			ft_printf_minlen(char **tab, t_printfpara *p, va_list args);
void			ft_printf_debugpara(t_printfpara *p);
void			ft_printf_presition(char **tab, t_printfpara *p, va_list args);
void			ft_printf_modlen(char **tab, t_printfpara *p);
void			ft_printf_conversion(char **tab, t_printfpara *p);
char			*ft_printf_print(t_printfpara *p, va_list args);

char			*ft_printf_spechar(char *src);
int				ft_printf_color(char **str, int *r);

char			*ft_printf_str0mod(char *str, t_printfpara *p);
char			*ft_printf_numpre(char *str, t_printfpara *p);
char			*ft_printf_strprefix(char *str, t_printfpara *p);
char			*ft_printf_numsigne(char *str, t_printfpara *p);
char			*ft_printf_strprefix(char *str, t_printfpara *p);
void			ft_printf_strpre(char *str, t_printfpara *p);
char			*ft_printf_strmod(char *str, t_printfpara *p);

void			ft_printf_incompatible_flag(t_printfpara *p);

#endif
