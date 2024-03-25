/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:29:08 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/25 12:33:24 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatter(const char *format, va_list args, int i)
{
	int	count;

	count = 0;
	if (format[i] == '%')
		count += ft_print_char('%');
	else if (format[i] == 'c')
		count += ft_print_char(va_arg(args, int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		outputLength;

	i = 0;
	outputLength = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			outputLength += ft_formatter(format, args, ++i);
		else
		{
			outputLength += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args); // It will free the allocated memory
	return (outputLength);
	// printf("Printing: %s\n", format);
}

int	main(void)
{
	int returnPrintf;

	returnPrintf = ft_printf("Main string:%c", 'c');
	printf("\nReturn value: %d\n", returnPrintf);
}