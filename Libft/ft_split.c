/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:43 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/09 16:32:12 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substr_in_str(const char *s, char c)
{
	int		i;
	size_t	countsubstr;

	i = 0;
	countsubstr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			countsubstr++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (countsubstr);
}

static void	*arrays_freedom(char **ptr, int m)
{
	while (m > 0)
	{
		m--;
		free (ptr[m]);
	}
	free (ptr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t	len;
	int		x;
	int		j;
	size_t	numofsubstr;
	char	**strslip;

	x = 0;
	j = 0;
	numofsubstr = count_substr_in_str(s, c);
	strslip = (char **)malloc((numofsubstr + 1) * sizeof(char *));
	if (!strslip)
		return (NULL);
	while (j < (int)numofsubstr)
	{
		len = 0;
		while (s[x] == c)
			x++;
		while (s[x + len] != '\0' && s[x + len] != c)
			len++;
		strslip[j] = ft_substr(&s[x], 0, len);
		if (!strslip[j])
			return (arrays_freedom(strslip, j));
		x = x + len;
		j++;
	}
	strslip[j] = NULL;
	return (strslip);
}
/**
 * The static function `count_substr_in_str` counts the number of substrings
 * in a given string that are separated by a specified character.
 * 
 * @param s The parameter `s` is a pointer to a character array (string)
 * that represents the input string.
 * @param c The parameter `c` is a character that we want to count the
 * occurrences of in the string `s`.
 * 
 * @return the number of occurrences of a character 'c' in a given string 's'.
 */

/**
 * Static function `arrays_freedom` frees the memory allocated for a 2D array
 * of characters.
 * 
 * @param ptr ptr is a pointer to a pointer to a character. It represents a
 * dynamically allocated 2D array of characters.
 * @param m The parameter `m` represents the number of elements in the
 * array `ptr`.
 * 
 * @return 0.
 */

/**
 * The function `ft_split` takes a string `s` and a character `c` as input, and
 * splits the string into an array of substrings based on the delimiter `c`.
 * 
 * @param s The parameter `s` is a pointer to a constant character string.
 * It represents the input string that needs to be split into substrings.
 * @param c The parameter `c` is a character that is used as a delimiter to
 * split the string `s` into substrings.
 * 
 * @return The function `ft_split` is returning a pointer to a pointer of
 * characters (`char **`).
 */