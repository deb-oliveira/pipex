/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:23:25 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/03 12:39:28 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	len_s;
	unsigned int	count;
	unsigned int	size;

	if (!s)
		return (NULL);
	len_s = ft_strlen((char *)s);
	size = 0;
	while (start < len_s && size < len && s[start + size] != '\0')
		size++;
	substr = malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	count = 0;
	while (count < size)
	{
		substr[count] = s[start + count];
		count++;
	}
	substr[count] = '\0';
	return (substr);
}
