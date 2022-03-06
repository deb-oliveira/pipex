/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:26:51 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/06 17:43:52 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# include <stdlib.h>

void	ft_build_words2(char **split, char *str, char c, char s);

void	ft_count_words2(char *str, char c, char s, int *words_count);

char	**ft_split2(char const *str, char *c, char *s);

char	*ft_strchr(const char *str, int c);

char	*ft_strdup(char *src);

size_t	ft_strlen(const char *str);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

#endif