/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadali <hadali@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:15:23 by hadali            #+#    #+#             */
/*   Updated: 2022/02/21 18:48:34 by hadali           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_format(char c)
{
	return (c == 'd' || c == 'p' || c == 'u' || c == 's' || c == 'i' \
			|| c == 'c' || c == 'x' || c == 'X' || c == '%');
}

static int	ft_format(char c, va_list argument)
{
	if (c == 'd' || c == 'i')
		return (ft_print_decimal(va_arg(argument, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(argument, char *)));
	else if (c == 'u')
		return (ft_print_unsgnd_int(va_arg(argument, unsigned long)));
	else if (c == 'c')
		return (ft_print_char(va_arg(argument, int)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(argument, void *)));
	else if (c == 'x')
		return (ft_print_lower_hexa(va_arg(argument, unsigned long)));
	else if (c == 'X')
		return (ft_print_upper_hexa(va_arg(argument, unsigned long)));
	else
		return (ft_print_char('%'));
}

static int	ft_separate_input(char const *input, va_list arguments)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			while (input[i] && !ft_is_format(input[i]) && input[i] != ' ')
				i++;
			if (ft_is_format(input[i]))
			{
				count += ft_format(input[i], arguments);
				i++;
			}		
		}
		else
		{
			count += ft_print_char(input[i]);
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int			count;
	va_list		arguments;

	if (!input)
		return (0);
	count = 0;
	va_start(arguments, input);
	count = ft_separate_input(input, arguments);
	va_end(arguments);
	return (count);
}
