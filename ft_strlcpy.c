/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:54:53 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 16:49:22 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	src[20] = "Hello, World";

// 	char	dst1[20] = "********************";
// 	ft_strlcpy(dst1, src, 13);
// 	printf("結果: %s\n", dst1);

// 	char	dst2[20] = "********************";
// 	ft_strlcpy(dst2, src, 0);
// 	printf("結果: %s\n", dst2);

// 	return 0;
// 	// strlcpyはBSD系（macOSなど）の拡張機能のため本家断念
// }