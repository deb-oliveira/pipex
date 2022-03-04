/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:15:52 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/04 16:53:42 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void	get_last_word(int i, char *str, char **split)
{
	if (str && *str != '\0')
	{
		split[i] = ft_strdup(str);
		i++;
	}
	split[i] = NULL;
}

static void	update_common_and_str(char **common, char **str, char c)
{
	while (**common == c)
		*common += 1;
	*str = *common;
}

static void	ft_build_words2(char **split, char *str, char c, char s)
{
	char	*common;
	int		i;

	i = 0;
	common = ft_strchr(str, c);
	while (common)
	{
		split[i] = ft_substr(str, 0, common - str);
		update_common_and_str(&common, &str, c);
		if (*common == s)
		{
			common = ft_strchr(common + 1, s);
			if (common)
			{
				i++;
				split[i] = ft_substr(str + 1, 0, common - (str + 1));
				common = common + 1;
				update_common_and_str(&common, &str, c);
			}
		}
		common = ft_strchr(common, c);
		i++;
	}
	get_last_word(i, str, split);
}

static int	ft_count_words2(char *str, char c, char s)
{
	int		words_count;
	char	*common;

	words_count = 1;
	common = ft_strchr(str, c);
	while (common)
	{
		while (*common == c)
			common++;
		if (*common == s)
		{
			common = ft_strchr(common + 1, s);
			if (common && *(common + 1) != '\0' && *(common + 1) != c)
				words_count++;
		}
		common = ft_strchr(common, c);
		words_count++;
	}
	return (words_count);
}

char	**ft_split2(char const *str, char *c, char *s)
{
	int		words_count;
	char	*scpy;
	char	**split;

	if (!str)
		return (NULL);
	scpy = ft_strtrim(str, c);
	if (!scpy)
		return (NULL);
	words_count = ft_count_words2(scpy, *c, *s);
	split = malloc(sizeof(char *) * (words_count + 1));
	if (split)
		ft_build_words2(split, scpy, *c, *s);
	free(scpy);
	return (split);
}
