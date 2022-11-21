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

#include "libftprintf.h"
#include <stdio.h>

void	ft_encontreipercent(char p, void *s)
{
	if (p == 'c')
		ft_putchar_fd((char)s[0], 1);
	else if (p == 's')
		ft_putstr_fd((char *)s, 0);
	else if (p == 'p')
		ft_print_pointer_fd(s, 0);
	else if (p == 'd')
		ft_putnbr_fd( (int)s[0], 0);
	else if (p == 'i')
		ft_putnbr_base_fd((int *)s, 10, 0);
	else if (p == 'u')
		ft_putnbr_base_fd((unsigned int *)s, 10, 0);
	else if (p == 'x')
		ft_putnbr_base_low_fd((int *)s, 16, 0);
	else if (p == 'X')
		ft_putnbr_base_up_fd((int *)s, 16, 0);
	else if (p == '%')
		write(0, '%', 1);

}
int	ft_printf(const char *fds, ...)
{
	va_list	args;
	va_list copy;
	va_start(args, fds);
	va_copy(copy, args);
	int count;

	count = 0;
	while (fds[count] != '\0')
	{
		if (fds[count] != '%')
			ft_putchar_fd(fds[count], 0);
		if (fds[count] == '%')
		{
			ft_encontreipercent(fds[count + 1], va_arg(args, char *));
			count++;
		}
		count++;
	}
	va_end(copy);
	va_end(args);
	return (0);
}
int main(void)
{
	ft_printf("feasfs","aaaaa", "bbbbb");
	return (0);
}
	/*printf("%s",va_arg(args,char *));
	printf("%s",va_arg(args,char *));*/