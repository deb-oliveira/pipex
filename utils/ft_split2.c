/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:15:52 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/06 17:45:09 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

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
	ft_count_words2(scpy, *c, *s, &words_count);
	split = malloc(sizeof(char *) * (words_count + 1));
	if (split)
		ft_build_words2(split, scpy, *c, *s);
	free(scpy);
	return (split);
}
