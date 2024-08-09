/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampoy- <pcampoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:49:21 by pcampoy-          #+#    #+#             */
/*   Updated: 2024/07/25 18:25:57 by pcampoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digitos(signed long int n)
{
	int	res;
	int	signo;

	res = 1;
	signo = 0;
	if (n < 0)
	{
		n *= -1;
		signo = 1;
	}
	if (n < 10)
		return (res + signo);
	while (n >= 10)
	{
		res += 1;
		n /= 10;
	}
	return (res + signo);
}

int	ft_putinteger(int n)
{
	int				numdig;
	signed long int	dig;
	char			c;
	int				res;

	dig = (signed long int) n;
	res = 0;
	numdig = ft_digitos(dig);
	if (dig < 0)
	{
		write(1, "-", 1);
		res++;
		dig *= -1;
	}
	if (numdig != 1)
	{
		res++;
		ft_putinteger(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
	else if (numdig == 1)
	{
		res++;
		c = n % 10 + '0';
		write(1, &c, 1);
	}
	return (res);
}

int main() {
	ft_putinteger(0);
	printf("\n%i, %i", 1234, ft_putinteger(123));
}