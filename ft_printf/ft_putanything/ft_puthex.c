/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaarour <szaarour@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:06:59 by szaarour          #+#    #+#             */
/*   Updated: 2025/12/29 14:06:59 by szaarour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	if (format == 'x')
		count += ft_putchar("0123456789abcdef"[n % 16]);
	else if (format == 'X')
		count += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (count);
}

// int main()
// {
// 	ft_puthex(670, 'X');
//  ft_puthex(255, 'x');
// 	return (0);
// }