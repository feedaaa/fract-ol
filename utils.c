/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:46:51 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/28 20:15:44 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s2_s;
	unsigned char	*s1_s;

	s2_s = (unsigned char *)s2;
	s1_s = (unsigned char *)s1;
	if (n == 0)
		return (0);
	i = 0;
	while (s1_s[i] == s2_s[i] && s1_s[i] != '\0')
	{
		i++;
	}
	return (s1_s[i] - s2_s[i]);
}

double	atobbl(char *s)
{
	long		int_pt;
	double		fract_pt;
	double		power;
	int			sign;

	int_pt = 0;
	fract_pt = 0;
	sign = +1;
	power = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		int_pt = (int_pt * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		power /= 10;
		fract_pt = fract_pt + (*s++ - 48) * power;
	}
	return ((int_pt + fract_pt) * sign);
}

int	julia_param_check(const char *param)
{
	int		decimal_point_count;
	int		length;
	int		valid;
	int		i;

	decimal_point_count = 0;
	length = (int)strlen(param);
	valid = 1;
	i = 0;
	while (i < length)
	{
		if (param[i] == '.')
			decimal_point_count++;
		else if (!isdigit(param[i]) && (param[i] != '-' || i != 0))
		{
			valid = 0;
			break ;
		}
		i++;
	}
	if (decimal_point_count > 1)
		valid = 0;
	return (valid);
}
