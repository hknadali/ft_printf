/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadali <hadali@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:03:58 by hadali            #+#    #+#             */
/*   Updated: 2022/02/21 18:04:01 by hadali           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_divide(char *x, unsigned int nbr, long int len)
{
	while (nbr > 0)
	{
		x[len--] = 48 + (nbr % 10);
		nbr /= 10;
	}
	return (x);
}

static long int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(long n)
{
	unsigned long	nbr;
	long int		len;
	char			*str;

	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		nbr = n * -1;
		str[0] = '-';
	}
	else
		nbr = n;
	str = ft_divide(str, nbr, len);
	return (str);
}

static size_t	ft_num_len(unsigned long long n, const char *base)
{
	size_t				len;
	unsigned long long	i;

	len = 1;
	i = 0;
	while (base[i])
		i++;
	while (n >= i)
	{
		n /= i;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long n, const char *base)
{
	char	*str;
	int		num_len;
	int		i;

	num_len = ft_num_len(n, base);
	i = 0;
	while (base[i])
		i++;
	str = malloc((size_t)(num_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[num_len] = 0;
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[n % i];
		n /= i;
	}
	return (str);
}
