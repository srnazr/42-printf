/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaarour <szaarour@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:24:37 by szaarour          #+#    #+#             */
/*   Updated: 2025/12/29 12:24:37 by szaarour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		count += ft_putunbr(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(*args, unsigned int), c);
	else if (c == 'p')
		count += ft_putptr(va_arg(*args, void *));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}
