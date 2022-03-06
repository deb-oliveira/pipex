/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2_get_words.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:43:20 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/06 17:44:51 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void	update_common_and_str(char **common, char **str, char c)
{
	while (**common == c)
		*common += 1;
	*str = *common;
}

static void	get_first_word(int *i, char **str, char **split, char s)
{
	char	*common;

	if (*i == 0 && **str == s)
	{
		common = ft_strchr(*str + 1, s);
		if (common)
		{
			split[0] = ft_substr(*str, 1, common - (*str + 1));
			*str = *str + (common - (*str)) + 1;
		}
		else
		{
			split[0] = ft_substr(*str, 1, ft_strlen(*str));
			**str = '\0';
		}
		*i += 1;
	}
}

static void	get_last_word(int *i, char **str, char **split)
{
	if (*str && **str != '\0')
	{
		split[*i] = ft_strdup(*str);
		**str = '\0';
		*i += 1;
	}
	split[*i] = NULL;
}

void	ft_build_words2(char **split, char *str, char c, char s)
{
	char	*common;
	int		i;

	i = 0;
	get_first_word(&i, &str, split, s);
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
				split[++i] = ft_substr(str + 1, 0, common - (str + 1));
				common = common + 1;
				update_common_and_str(&common, &str, c);
			}
		}
		if (common)
			common = ft_strchr(common, c);
		i++;
	}
	get_last_word(&i, &str, split);
}

void	ft_count_words2(char *str, char c, char s, int *words_count)
{
	char	*common;

	*words_count = 1;
	if (*str == s)
	{
		common = ft_strchr(str + 1, s);
		if (common && *(common + 1) != '\0')
				*words_count += 1;
		update_common_and_str(&common, &str, c);
	}
	common = ft_strchr(str, c);
	while (common)
	{
		while (*common == c)
			common++;
		if (*common == s)
		{
			common = ft_strchr(common + 1, s);
			if (common && *(common + 1) != '\0' && *(common + 1) != c)
				*words_count += 1;
		}
		if (common)
			common = ft_strchr(common, c);
		*words_count += 1;
	}
}
