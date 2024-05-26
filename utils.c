/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:46:51 by ffidha            #+#    #+#             */
/*   Updated: 2024/05/26 16:07:21 by ffidha           ###   ########.fr       */
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

// double	atodbl(char *s)
// {
// 	long	integer_part;
// 	double	fractional_part;
// 	double	pow;
// 	int		sign;

// 	integer_part = 0;
// 	fractional_part = 0;
// 	sign = +1;
// 	pow = 1;
// 	while ((*s >= 9 && *s <= 13) || 32 == *s)
// 		++s;
// 	while ('+' == *s || '-' == *s)
// 		if ('-' == *s++)
// 			sign = -sign;
// 	while (*s != '.' && *s)
// 		integer_part = (integer_part * 10) + (*s++ - 48);
// 	if ('.' == *s)
// 		++s;
// 	while (*s)
// 	{
// 		pow /= 10;
// 		fractional_part = fractional_part + (*s++ - 48) * pow;
// 	}
// 	return ((integer_part + fractional_part) * sign);
// }