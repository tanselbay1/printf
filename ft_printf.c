/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:29:08 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/21 12:22:15 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
		outputLength += write(1, &format[i], 1);
		i++;
	}
	va_end(args); // It will free the allocated memory
	return (outputLength);
	// printf("Printing: %s\n", format);
}

int	main(void)
{
	char world[] = "Hello World!";
	int returnPrintf = ft_printf(world);
	printf("Return value: %d\n", returnPrintf);
}