/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:49:22 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/03 12:49:32 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len_str = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (i + j < len_str)
	{
		str[i + j] = s2[j];
		j++;
	}	
	str[i + j] = '\0';
	return (str);
}
