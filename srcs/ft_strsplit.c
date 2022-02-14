/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:57:51 by parkharo          #+#    #+#             */
/*   Updated: 2022/01/17 16:19:13 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_count(const char *s, char del)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == del && *s)
			++s;
		if (*s)
			++i;
		while (*s != del && *s)
			++s;
		while (*s == del && *s)
			++s;
	}
	return (i);
}

static	char	*populate_array(const char *s, size_t *index, char del)
{
	size_t	i;
	size_t	word_len;
	size_t	j;
	char	*word;

	while (s[*index] == del)
		++(*index);
	j = *index;
	i = 0;
	word_len = 0;
	while (s[*index] != del && s[*index] != '\0')
	{
		++word_len;
		++(*index);
	}
	word = ft_strnew(word_len);
	if (!word)
		return (NULL);
	while (i < word_len)
	{
		word[i] = s[j + i];
		++i;
	}
	return (word);
}

static	char**	free_arr(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
	return (NULL);
}

char	**ft_strsplit(const char *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = get_count(s, c);
	split = (char **)malloc(sizeof(char *) * (len + 1));
	if (!split)
		return (NULL);
	while (i < len)
	{
		split[i] = populate_array(s, &j, c);
		if (!split[i])
			return (free_arr(split, (int)i - 1));
		++i;
	}
	split[i] = 0;
	return (split);
}
