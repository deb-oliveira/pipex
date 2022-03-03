/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:24:04 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/03/03 12:40:59 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	n;
	size_t	count;

	n = ft_strlen((char *)str) + 1;
	count = 0;
	while (count < n && *((unsigned char *)str + count) != (unsigned char) c)
		count++;
	if (count == n)
		return (0);
	else
		return ((char *)(str + count));
}
