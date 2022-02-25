/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadali <hadali@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:36:41 by hadali            #+#    #+#             */
/*   Updated: 2022/02/21 19:09:47 by hadali           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str == NULL)
	{
		count += ft_print_string("(null)");
		return (count);
	}
	while (str[i])
	{
		count += ft_print_char(str[i]);
		i++;
	}
	return (count);
}

int	ft_print_decimal(int nbr)
{
	char	*tmp;
	int		count;

	tmp = ft_itoa(nbr);
	count = ft_print_string(tmp);
	free((void *)tmp);
	return (count);
}

int	ft_print_unsgnd_int(unsigned int num)
{
	int		count;
	char	*tmp;

	if ((int)num < 0)
		tmp = ft_itoa(4294967295 + num + 1);
	else
		tmp = ft_itoa(num);
	count = ft_print_string(tmp);
	free((void *)tmp);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	address;
	char			*tmp;
	int				count;

	count = 0;
	address = (unsigned long)ptr;
	tmp = ft_itoa_base(address, "0123456789abcdef");
	count += ft_print_string("0x");
	count += ft_print_string(tmp);
	free((void *)tmp);
	return (count);
}
