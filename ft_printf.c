/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:29:08 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/19 15:17:59 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	va_end(args); // It will free the allocated memory
	printf("Printing: %s\n", format);
}

int	main(void)
{
	char world[] = "Hello World!";
	int returnPrintf = ft_printf(world);
	printf("Return value: %d\n", returnPrintf);
}