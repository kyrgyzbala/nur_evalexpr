/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numyktyb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:46:31 by numyktyb          #+#    #+#             */
/*   Updated: 2019/08/24 19:57:11 by numyktyb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "nurik.h"

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putnbr(int num)
{
	char	str[12];
	int		top;

	top = 0;
	if (num < 0)
	{
		ft_putchar('-');
		num = num * -1;
	}
	while (num > 0)
	{
		str[top++] = (num % 10) + '0';
		num = num / 10;
	}
	while (--top >= 0)
		ft_putchar(str[top]);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
