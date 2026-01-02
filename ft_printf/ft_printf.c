/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaarour <szaarour@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:24:43 by szaarour          #+#    #+#             */
/*   Updated: 2025/12/29 12:24:43 by szaarour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *first, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, first);
	i = 0;
	count = 0;
	while (first[i])
	{
		if (first[i] == '%' && first[i + 1])
		{
			i++;
			count += ft_convert(&args, first[i]);
		}
		else
			count += ft_putchar(first[i]);
		i++;
	}
	va_end(args);
	return (count);
}
