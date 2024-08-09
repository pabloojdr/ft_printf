/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampoy- <pcampoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:16:42 by pcampoy-          #+#    #+#             */
/*   Updated: 2024/07/25 18:24:05 by pcampoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_hexa(unsigned long int n)
{
	char	*alph;
	int		res;

	alph = "0123456789ABCDEF";
	if (n <= 0)
		return (0);
	if (n > 0)
	{
		ft_hexa(n / 16);
		write(1, &alph[n % 16], 1);
		res++;
	}
	return (res);
}

int	ft_putpointer(unsigned long int n)
{
	int	res;

	write(1, "0x", 2);
	res = 2;
	res += ft_hexa(n);
	return (res);
}

int main() {
    void    *p;
    ft_putpointer((unsigned long int) p);
    printf("\n%p", p);
}