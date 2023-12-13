/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:06:05 by fsantill          #+#    #+#             */
/*   Updated: 2023/12/13 12:41:29 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"

typedef struct stack
{
	int				number;
	struct stack	*next;
}					t_stack;

int		args_are_only_numbers_or_spaces(int argc, char **argv);
void	ft_sa(t_stack **lst_a);
void	ft_sb(t_stack **lst_b);
void	ft_ss(t_stack **lst_a, t_stack **lst_b);
void	ft_pa(t_stack **lst_a, t_stack **lst_b);
void	ft_pb(t_stack **lst_a, t_stack **lst_b);
void	ft_ra(t_stack **lst_a);
void	ft_rb(t_stack **lst_b);
void	ft_rr(t_stack **lst_a, t_stack **lst_b);
void	ft_rra(t_stack **lst_a);
void	ft_rrb(t_stack **lst_b);
void	ft_rrr(t_stack **lst_a, t_stack **lst_b);
t_stack	*ft_stack_prev_last(t_stack *lst);
t_stack	*ft_stack_last(t_stack *lst);

#endif

/*int	tree_states[][4];
void	tree_alphabet(t_automata *a);*/