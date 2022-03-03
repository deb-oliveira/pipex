/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:26:51 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/03 12:40:22 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# include <stdlib.h>

char	**ft_split(char const *s, char *c);

char	*ft_strchr(const char *str, int c);

char	*ft_strdup(char *src);

size_t	ft_strlen(const char *str);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif