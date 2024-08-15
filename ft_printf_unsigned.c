/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 22:04:28 by marvin            #+#    #+#             */
/*   Updated: 2024/08/15 22:04:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int digits_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

int	ft_putnumber_unsigned(unsigned int n)
{
	char	d;
	int	count;

	count = digits_unsigned(n);
	if (n >= 10)
	{
		ft_putnumber_unsigned(n / 10);
		ft_putchar((n % 10) + '0');
	} else
	{
		d = n + '0';
		write(1, &d, 1);
	}
	return (count);
}

