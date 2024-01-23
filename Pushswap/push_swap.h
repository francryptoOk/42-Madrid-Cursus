/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:06:05 by fsantill          #+#    #+#             */
/*   Updated: 2024/01/23 15:49:14 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"

typedef struct t_stack
{
	int				number;
	struct t_stack	*next;
}					t_stack;

char		*ft_freedom(char **p);
int			args_sign_numbers_or_spaces(int argc, char **argv);
int			empty_or_not_repeated_numbers(t_stack *begin);
t_stack		*args_to_integer_and_add(int argc, char **argv);
void		ft_sa(t_stack **lst_a);
void		ft_sb(t_stack **lst_b);
void		ft_ss(t_stack **lst_a, t_stack **lst_b);
void		ft_pa(t_stack **lst_a, t_stack **lst_b);
void		ft_pb(t_stack **lst_a, t_stack **lst_b);
void		ft_ra(t_stack **lst_a);
void		ft_rb(t_stack **lst_b);
void		ft_rr(t_stack **lst_a, t_stack **lst_b);
void		ft_rra(t_stack **lst_a);
void		ft_rrb(t_stack **lst_b);
void		ft_rrr(t_stack **lst_a, t_stack **lst_b);
long long	ft_atol_int(char *str);
void		ft_stack_add(int nb, t_stack **new);
t_stack		*ft_stack_second_last(t_stack *lst);
t_stack		*ft_stack_last(t_stack *lst);

#endif
