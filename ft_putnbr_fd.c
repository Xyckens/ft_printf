/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:42:51 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:47:39 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	absolute_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_alga(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n != 0)
		count--;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_itoa(int n)
{
	int		count;
	char	*string;

	count = ft_alga(n);
	string = (char *) malloc((count + 2) * sizeof(char));
	if (!string)
		return (NULL);
	string[count + 1] = '\0';
	if (n == 0)
		string[count] = '0';
	if (n < 0)
		string[0] = '-';
	while (n != 0)
	{
		string[count--] = absolute_value(n % 10) + '0';
		n /= 10;
	}
	return (string);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	*s;
	int		count;

	s = ft_itoa(n);

	count = 0;
	while (s[count] != '\0')
	{
		ft_putchar_fd(s[count], fd);
		count++;
	}
	free(s);
	return (count);
}
