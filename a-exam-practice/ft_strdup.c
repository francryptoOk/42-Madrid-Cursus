/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:43:51 by fsantill          #+#    #+#             */
/*   Updated: 2023/11/27 11:43:58 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	j = 0;

	while (str[j] != '\0')
		j++;
	return (j);
}

char	*ft_strdup(char *src)
{
	int len = 0;
	int i = 0;
	char *dest;

	len = ft_strlen(src);
	dest = malloc (len + 1);
	if (!dest)
		return(NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{	
	char *src = "hola";

	char *dest = ft_strdup(src);
	printf("StrDup: %s", dest);
	return (0);
}*/
