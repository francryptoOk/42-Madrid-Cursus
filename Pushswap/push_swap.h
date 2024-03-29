/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:06:05 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/12 17:10:55 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct t_stack
{
	int				number;
	int				id;
	struct t_stack	*next;
}					t_stack;

int			ft_algorithm(t_stack **lst_a, t_stack **lst_b);
int			sorting_five_numbers(t_stack **lst_a, t_stack **lst_b);
int			sorting_five_numbers_bis(t_stack **lst_a, t_stack **lst_b, int min);
int			sorting_four_numbers(t_stack **lst_a, t_stack **lst_b);
int			sorting_four_numbers_bis(t_stack **lst_a, t_stack **lst_b, int min);
int			sorting_three_numbers(t_stack **lst_a);
void		leaks(void);
int			ft_error(int e);
void		*ft_arr_free(char **splt);
void		ft_stk_free(t_stack **stack);
int			args_sign_numbers_or_spaces(int argc, char **argv);
t_stack		*args_to_integer_and_add(int argc, char **argv);
int			not_repeated_numbers(t_stack *begin);
int			numbers_in_order(t_stack *lst);
long long	ft_atoll_int(char *str);
void		ft_stack_add_back(t_stack **lst, t_stack *new);
void		ft_stack_add(int nb, t_stack **new);
int			stack_length(t_stack *stack);
int			ft_min_node(t_stack *node);
int			ft_max_node(t_stack *node);
t_stack		*ft_stack_second_last(t_stack *node);
t_stack		*ft_stack_last(t_stack *node);
void		ft_sa(t_stack **lst_a, char *str);
void		ft_sb(t_stack **lst_b, char *str);
void		ft_ss(t_stack **lst_a, t_stack **lst_b, char *str);
void		ft_pa(t_stack **lst_a, t_stack **lst_b, char *str);
void		ft_pb(t_stack **lst_a, t_stack **lst_b, char *str);
void		ft_ra(t_stack **lst_a, char *str);
void		ft_rb(t_stack **lst_b, char *str);
void		ft_rr(t_stack **lst_a, t_stack **lst_b, char *str);
void		ft_rra(t_stack **lst_a, char *str);
void		ft_rrb(t_stack **lst_b, char *str);
void		ft_rrr(t_stack **lst_a, t_stack **lst_b, char *str);
int			ft_stacksize(t_stack *lst);
void		ft_node_id_assignment(t_stack **stack);
int			ft_bits(int lst_size);
void		ft_radix(t_stack **lst_a, t_stack **lst_b);

#endif
