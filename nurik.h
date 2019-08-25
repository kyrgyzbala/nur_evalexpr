/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nurik.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numyktyb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:51:35 by numyktyb          #+#    #+#             */
/*   Updated: 2019/08/24 20:29:27 by numyktyb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NURIK_H
# define NURIK_H

typedef struct		s_int
{
	int		*s;
	int		top;
}					t_int;

typedef struct		s_char
{
	char	*o;
	int		t;
}					t_char;

int					priority(char ch);
int					is_operator(char ch);
int					do_op(char op, int b, int a);
int					get_num(char *str, int *i);
int					get_len(char *str);
int					eval_expr(char *str);
#endif
