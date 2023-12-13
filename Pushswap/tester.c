/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:31:36 by fsantill          #+#    #+#             */
/*   Updated: 2023/12/13 12:41:06 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack **lst)
{
	t_stack	*start;

	start = *lst;
	while (start != NULL)
	{
		printf("%d\n", start->number);
		start = start->next;
	}
}

int	main(void)
{
	t_stack node_a1, node_a2, node_a3;
	t_stack node_b1, node_b2, node_b3;
	t_stack *start_a, *start_b;

	start_a = &node_a1;
	start_b = &node_b1;
	node_a1.number = 1;
	node_a1.next = &node_a2;
	node_a2.number = 2;
	node_a2.next = &node_a3;
	node_a3.number = 3;
	node_a3.next = NULL;
	node_b1.number = 4;
	node_b1.next = &node_b2;
	node_b2.number = 5;
	node_b2.next = &node_b3;
	node_b3.number = 6;
	node_b3.next = NULL;
	print_list(&start_a);
	//printf("------\n");
	//print_list(&start_b);
	ft_ra(&start_a);
	print_list(&start_a);
	//printf("------\n");
	//print_list(&start_b);
	// ft_pa(&start_a, &start_b);
	// print_list(&start_a);
	// printf("------\n");
	// print_list(&start_b);
	return (0);
}
