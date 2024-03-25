/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:29:55 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/25 16:06:57 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <unistd.h>

int	ft_print_hex(unsigned long long n, int upper)
{
	int count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex(n / 16, upper);
		count += ft_print_hex(n % 16, upper);
	}
	else
	{
		if (n < 10)
		{
			count += write(1, &n, 1);
			write(1, "0", 1);
		}
		else
		{
			if (upper)
				count += write(1, &"0123456789ABCDEF"[n % 16], 1);
			else
				count += write(1, &"0123456789abcdef"[n % 16], 1);
		}
	}
	return (count);
}