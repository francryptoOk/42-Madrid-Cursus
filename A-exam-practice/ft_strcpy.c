/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:15:34 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/29 15:36:54 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i = 0;

	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/*
int	main(void)
{
	char	s1[] = "Okey!";
	char	s2[] = "Error";
	ft_strcpy(s2, s1);
	printf("Dst: \n%s\n%s\n", s2, s1);
	return (0);
}*/
