/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numyktyb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:49:08 by numyktyb          #+#    #+#             */
/*   Updated: 2019/08/24 20:53:16 by numyktyb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nurik.h"

int		priority(char ch)
{
	if (ch == '+' || ch == '-')
		return (1);
	if (ch == '*' || ch == '/' || ch == '%')
		return (2);
	return (0);
}

int		is_operator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return (1);
	return (0);
}

int		do_op(char op, int b, int a)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
		return (a / b);
	return (a % b);
}

int		get_num(char *str, int *i)
{
	int		res;
	int		is_neg;

	res = 0;
	is_neg = 1;
	if (str[*i] == '-')
	{
		is_neg = -1;
		*i = *i + 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9' && str[*i] != '\0')
	{
		res = res * 10;
		res = res + (str[*i]) - '0';
		(*i) = *i + 1;
	}
	(*i) = *i - 1;
	return (res * is_neg);
}

int		get_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
