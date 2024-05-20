/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:50:18 by fsantill          #+#    #+#             */
/*   Updated: 2024/05/20 17:01:36 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int i = 0;

	while(src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int j = 0;
	int srclen = ft_strlen(src);
	char *s2 = malloc(srclen * sizeof(char *));

	while (src[j] != '\0')
	{
		s2[j] = src[j];
		j++;
	}
	return (&(*s2));
}

//int	main()

//strdup devuelve un puntero al nuevo string que es un duplicado del que recibió.//
//Hay que hacer malloc y free//
