/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:37:24 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/21 13:37:26 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_encontreipercent(char p, va_list args, int fd)
{
	if (p == 'c')
	{
		ft_putchar_fd(va_arg(args, int), fd);
		return(1);
	}
	else if (p == 's')
		return(ft_putstr_fd(va_arg(args, char *), fd));
	else if (p == 'p')
		return(ft_print_pointer_fd(va_arg(args, unsigned long long), fd));
	else if (p == 'd')
		return(ft_putnbr_fd(va_arg(args, int), fd));
	else if (p == 'i')
		return(ft_putnbr_fd(va_arg(args, int), fd));
	else if (p == 'u')
		return(ft_putlongnbr_fd(va_arg(args, unsigned int), fd));
	else if (p == 'x')
		return(ft_putnbr_hex_fd(va_arg(args, unsigned int), fd, p));
	else if (p == 'X')
		return(ft_putnbr_hex_fd(va_arg(args, unsigned int), fd, p));
	else if (p == '%')
	{
		ft_putchar_fd('%', fd);
		return(1);
	}
	else
		return(ft_putstr_fd("erro", fd));
}

int	ft_printf(const char *fds, ...)
{
	va_list	args;
	va_start(args, fds);
	int count;
	int count2;

	count = 0;
	count2 = 0;
	while (fds[count] != '\0')
	{
		if (fds[count] != '%')
		{
			count2++;
			ft_putchar_fd(fds[count], 1);
		}
		if (fds[count] == '%')
		{
			count2 += ft_encontreipercent(fds[count + 1], args, 1);
			count++;
		}
		count++;
	}
	va_end(args);
	//printf(" o meu len  = %d\n", count2);

	return (count2);
}
/*int main(void)
{
	int d = 364;
	int c;
	char l = 'L';
	char *str = "era uma vez";
	printf("\n\n printf\n");
	c = printf(" char         = %c\n str          = %s\n pointer      = %p\n dec          = %d\n int          = %i\n unsigned int = %u\n hexmin       = %x\n hexhigh      = %X\n percent      = %%\n ", l, str, str, d, d, d, d, d);
	printf("\n\n o meu\n");

	ft_printf(" char         = %c\n str          = %s\n pointer      = %p\n dec          = %d\n int          = %i\n unsigned int = %u\n hexmin       = %x\n hexhigh      = %X\n percent      = %%\n", l, str, str, d, d, d, d, d);
	
	c = printf(" gdfgdfgdfgdgdr %d\n",d);

	ft_printf(" gdfgdfgdfgdgdr %d\n",d);
	printf(" printf len = %d\n", c);
	return (0);
}*/
