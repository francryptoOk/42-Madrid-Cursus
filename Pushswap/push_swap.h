/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:15:49 by fsantill          #+#    #+#             */
/*   Updated: 2023/12/04 17:55:44 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "Libft/libft.h"

int		args_are_numbers_or_spaces(int argc, char **argv);
void	ft_sa(t_list *lst_a);
void	ft_sb(t_list *lst_b);
void	ft_ss(t_list *lst_a, t_list *lst_b);
void	ft_pa(t_list *lst_a, t_list *lst_b);
void	ft_pb(t_list *lst_a, t_list *lst_b);

#endif

/*int	tree_states[][4];
void	tree_alphabet(t_automata *a);*/