/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:45:51 by annstepa          #+#    #+#             */
/*   Updated: 2022/07/20 20:15:43 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

size_t	word_length(char const *s, char c)
{
	size_t	j;

	j = 0;
	while (s[j] && s[j] != c && s[j] != '\0')
		j++;
	return (j);
}

char	**f(char **arr, char const *s, char c, size_t wc)
{
	size_t	i;
	size_t	j;
	size_t	wl;

	i = -1;
	while (*s == c)
		s++;
	while (++i < wc)
	{
		while (*s == c)
			s++;
		wl = word_length(s, c);
		arr[i] = (char *)malloc(sizeof(char) * (wl + 1));
		if (!arr[i])
			return (NULL);
		j = 0;
		while (j < wl)
			arr[i][j++] = *s++;
		arr[i][j] = '\0';
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	arr = f(arr, s, c, wc);
	arr[wc] = NULL;
	return (arr);
}
