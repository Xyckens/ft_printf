/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:24:03 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/22 14:24:05 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_ptr(unsigned long long s)
{
	int	count;

	count = 0;
	while (s != 0)
	{
		s /= 16;
		count++;
	}
	return (count);
}

int	ft_print_pointer_fd(unsigned long long s, int fd)
{

	if (s >= 16)
	{
		ft_print_pointer_fd(s / 16, fd);
		ft_print_pointer_fd(s % 16, fd);
	}
	else
	{
		if (s <= 9)
			ft_putchar_fd(s + 48, fd);
		else
			ft_putchar_fd(s - 10 + 'a', fd);
	}
	return (count_ptr(s));
}
