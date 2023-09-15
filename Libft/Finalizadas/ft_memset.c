/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:37:27 by fsantill          #+#    #+#             */
/*   Updated: 2023/09/15 15:46:32 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *dest, int c, size_t count)
{
	int	i;

	i = 0;
	while (dest[i] < count)
	{
		dest[i] = c;
		i++;
	}
	return (dest);
}
