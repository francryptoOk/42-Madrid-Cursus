/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:06:05 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/01 14:43:17 by fsantill         ###   ########.fr       */
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

void		ft_stack_clear(t_stack **stack);
int			ft_algorithm(t_stack **lst_a);
int			sorting_three_numbers(t_stack **lst_a);
int			ft_error(int e);
int			args_sign_numbers_or_spaces(int argc, char **argv);
t_stack		*args_to_integer_and_add(int argc, char **argv);
int			not_repeated_numbers(t_stack *begin);
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
void		*ft_freedom(char **splt);
int			numbers_in_order(t_stack *lst);
long long	ft_atoll_int(char *str);
void		ft_stack_add_back(t_stack **lst, t_stack *new);
void		ft_stack_add(int nb, t_stack **new);
int			stack_length(t_stack *stack);
int			ft_min_node(t_stack *node);
int			ft_max_node(t_stack *node);
t_stack		*ft_stack_second_last(t_stack *node);
t_stack		*ft_stack_last(t_stack *node);

#endif
