/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadali <hadali@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:50:37 by hadali            #+#    #+#             */
/*   Updated: 2022/02/21 17:54:59 by hadali           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *input, ...);
int		ft_print_char(int c);
int		ft_print_decimal(int number);
int		ft_print_string(char *str);
int		ft_print_lower_hexa(unsigned int hexa);
int		ft_print_upper_hexa(unsigned int hexa);
int		ft_print_pointer(void *ptr);
int		ft_print_unsgnd_int(unsigned int num);
char	*ft_itoa(long n);
char	*ft_itoa_base(unsigned long long n, const char *base);

#endif
