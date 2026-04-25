/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 22:54:20 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 18:08:45 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char	src[6] = " world";

// 	char	dst1[8] = "Hello,";
// 	printf("結果: %zu\n%s\n", ft_strlcat(dst1, src, 13), dst1);

// 	char	dst2[8] = "Hello,";
// 	printf("結果: %zu\n%s\n", ft_strlcat(dst2, src, 8), dst2);

// 	char	dst3[8] = "Hello,";
// 	printf("結果: %zu\n%s\n", ft_strlcat(dst3, src, 0), dst3);

// 	char	dst4[8] = "Hello,";
// 	printf("結果: %zu\n%s\n", ft_strlcat(dst4, src, 3), dst4);

// 	return 0;
// }