/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 14:40:35 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/26 17:17:07 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define FT_HEX_LOW "0123456789abcdef"
# define FT_HEX_UP "0123456789ABCDEF"
# define FT_DECIMAL "0123456789"

int		ft_printf(const char *format, ...);
int		ft_convert(const char **position, va_list *ap);
int		ft_write_letters(const char **position_c);

int		ft_write(const char *s, size_t len);
size_t	ft_str_len(const char *s);
int		ft_print_char(char c);
int		ft_puts_string(const char *s);
int		ft_print_unsigned_num(unsigned long n, const char *to_type);
int		ft_print_signed(int n);
int		ft_print_ptr(const void *p);

#endif
