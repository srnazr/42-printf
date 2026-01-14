/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaarour <szaarour@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:07:06 by szaarour          #+#    #+#             */
/*   Updated: 2025/12/29 14:07:06 by szaarour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex_ptr(unsigned long long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_ptr(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	address;
	int					count;

	address = (unsigned long long)ptr;
	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	if (address == 0)
		count += ft_putchar('0');
	else
		count += ft_puthex_ptr(address);
	return (count);
}

// int main()
// {
//     int a = 42;
//     int b = 45;
//     ft_putptr(&a);
//     ft_putchar('\n');
//     ft_putptr(&b);
//     return (0);
// }