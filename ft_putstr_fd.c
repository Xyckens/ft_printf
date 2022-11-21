/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <fvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:38:11 by fvieira           #+#    #+#             */
/*   Updated: 2022/08/22 15:41:03 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_alt_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count] != '\0' && s[count] != '%')
	{
		ft_alt_putchar_fd(s[count], fd);
		count++;
	}
	if (s[count] == '%')
		return (s[count + 1])
	else
		return (NULL);
}
