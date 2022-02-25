/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadali <hadali@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:09:54 by hadali            #+#    #+#             */
/*   Updated: 2022/02/21 19:11:41 by hadali           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_hexa(unsigned int hexa)
{
	char	*tmp;
	int		count;

	tmp = ft_itoa_base(hexa, "0123456789ABCDEF");
	count = ft_print_string(tmp);
	free((void *)tmp);
	return (count);
}

int	ft_print_lower_hexa(unsigned int hexa)
{
	char	*tmp;
	int		count;

	tmp = ft_itoa_base(hexa, "0123456789abcdef");
	count = ft_print_string(tmp);
	free((void *)tmp);
	return (count);
}
