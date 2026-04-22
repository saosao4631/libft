/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:28:10 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/22 12:36:27 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	return (res);
}