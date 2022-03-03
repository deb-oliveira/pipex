/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:04:24 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/03 12:39:24 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	size_t	count;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen((char *)s1);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != 0)
		start++;
	while (len != 1 && start + 1 <= len && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	str = malloc (sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	count = 0;
	while (start + count + 1 <= len)
	{
		str[count] = s1[start + count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
