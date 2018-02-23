/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:36:57 by amacieje          #+#    #+#             */
/*   Updated: 2016/12/01 17:10:43 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		m;
	int		count;

	m = 0;
	count = 0;
	if (!s)
		return (0);
	if (s[m])
		count++;
	while (s[m] && s[m + 1])
	{
		if (s[m] == c && s[m + 1] != c)
			count++;
		m++;
	}
	return (count);
}

static char	*ft_fill_split(char const *s, char c, int *i)
{
	char	*word;
	int		k;

	if (!(word = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	k = 0;
	while (s[*i] != c && s[*i])
	{
		word[k] = s[*i];
		k++;
		*i = *(i) + 1;
	}
	word[k] = '\0';
	while (s[*i] == c && s[*i])
		*i = *(i) + 1;
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(str) * (ft_word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	j = 0;
	while (j < ft_word_count(s, c) && s[i])
	{
		str[j] = ft_fill_split(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
