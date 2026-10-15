/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 14:38:06 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/26 19:47:30 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;
	int		i;

	total = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			i = ft_convert(&format, &ap);
		else
			i = ft_write_letters(&format);
		if (i < 0)
		{
			va_end(ap);
			return (-1);
		}
		total = total + i;
	}
	va_end(ap);
	return (total);
}

int	ft_convert(const char **position, va_list *ap)
{
	char	c;

	(*position)++;
	c = **position;
	if (c == '\0')
		return (-1);
	(*position)++;
	if (c == 'c')
		return (ft_print_char((char)va_arg(*ap, int)));
	if (c == 's')
		return (ft_puts_string(va_arg(*ap, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*ap, const void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_signed(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_print_unsigned_num(va_arg(*ap, unsigned int), FT_DECIMAL));
	if (c == 'x')
		return (ft_print_unsigned_num(va_arg(*ap, unsigned int), FT_HEX_LOW));
	if (c == 'X')
		return (ft_print_unsigned_num(va_arg(*ap, unsigned int), FT_HEX_UP));
	if (c == '%')
		return (ft_print_char('%'));
	return (-1);
}

int	ft_write_letters(const char **position_c)
{
	size_t	i;
	int		written_c;

	i = 0;
	while ((*position_c)[i] && (*position_c)[i] != '%')
		i++;
	written_c = ft_write(*position_c, i);
	if (written_c < 0)
		return (-1);
	*position_c += i;
	return (i);
}

int	ft_put_str(char *s)
{
	if (s == NULL)
		return (ft_write("(null)", 6));
	return (ft_write(s, ft_str_len(s)));
}
