/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:46:51 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/27 17:54:48 by ffidha           ###   ########.fr       */
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
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		a = (unsigned char)s1[i];
		b = (unsigned char)s2[i];
		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}

double	atof(char *s)
{
	long	int_pt;
	double	fract_pt;
	double	pow;
	int		sign;

	int_pt = 0;
	fract_pt = 0;
	sign = +1;
	pow = 1;
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
		pow /= 10;
		fract_pt = fract_pt + (*s++ - 48) * pow;
	}
	return ((int_pt + fract_pt) * sign);
}

int	is_valid_julia_parameter(const char *param)
{
	int	decimal_point_count;
	int	length;
	int	valid;
	int	i;

	decimal_point_count = 0;
	length = (int)strlen(param);
	valid = 1;
	i = 0;
	while (i < length)
	{
		if (param[i] == '.')
		{
			decimal_point_count++;
		}
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