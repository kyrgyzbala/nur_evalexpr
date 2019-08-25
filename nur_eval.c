/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nur_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numyktyb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:26:24 by numyktyb          #+#    #+#             */
/*   Updated: 2019/08/24 21:03:21 by numyktyb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "nurik.h"

void	help(t_char *op, t_int *st)
{
	int		res;

	while (op->o[op->t] != '(')
	{
		res = do_op(op->o[op->t], st->s[st->top], st->s[st->top - 1]);
		st->top = st->top - 1;
		st->s[st->top] = res;
		op->t = op->t - 1;
	}
	op->t = op->t - 1;
}

void	help2(t_char *op, t_int *st, char ch)
{
	int		res;

	res = 0;
	while (op->t >= 0 && priority(op->o[op->t]) >= priority(ch) &&
			op->o[op->t] != '(')
	{
		res = do_op(op->o[op->t], st->s[st->top], st->s[st->top - 1]);
		st->top = st->top - 1;
		st->s[st->top] = res;
		op->t = op->t - 1;
	}
	op->t = op->t + 1;
	op->o[op->t] = ch;
}

int		is_neg_num(char *str, int i)
{
	if (str[i] == '-')
	{
		if (i == 0)
			return (1);
		if (is_operator(str[i - 1]))
			return (1);
		if (str[i - 1] == '(')
			return (1);
		if (str[i - 1] == ' ' && is_operator(str[i - 2]))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		eval_expr_r(char *str, int len, int res, int i)
{
	t_char	op;
	t_int	st;

	op.o = (char *)malloc(sizeof(char) * len);
	st.s = (int *)malloc(sizeof(int) * len);
	st.top = -1;
	op.t = -1;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || is_neg_num(str, i))
			st.s[++st.top] = get_num(str, &i);
		else if (str[i] == '(')
			op.o[++op.t] = str[i];
		else if (str[i] == ')')
			help(&op, &st);
		else if (is_operator(str[i]))
			help2(&op, &st, str[i]);
		i++;
	}
	while (op.t >= 0)
	{
		res = do_op(op.o[op.t--], st.s[st.top], st.s[st.top - 1]);
		st.s[--st.top] = res;
	}
	return (st.s[st.top]);
}

int		eval_expr(char *str)
{
	int		res;
	int		len;
	int		i;

	res = 0;
	i = 0;
	len = get_len(str);
	return (eval_expr_r(str, len, res, i));
}
