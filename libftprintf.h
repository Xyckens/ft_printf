/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:37:04 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/21 13:37:06 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *fds, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_print_pointer_fd(unsigned long long s, int fd);
void		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_hex_fd(unsigned int hex, int fd, int p);
int		ft_putstr_fd(char *s, int fd);

#endif
