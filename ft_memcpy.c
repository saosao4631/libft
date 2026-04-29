/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:33:00 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 16:29:56 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	src1[13] = "Hello, World";
// 	char	dst1[13] = "XXXXXXXXXXXX";
// 	char	dst2[13] = "XXXXXXXXXXXX";

// 	printf("src: %s\n", src1);
// 	printf("dst: %s\n\n", dst1);

// 	ft_memcpy(dst1, src1, 5);
// 	memcpy(dst2, src1, 5);

// 	printf("ft_memcpy の結果: %s\n", dst1);
// 	printf("memcpy の結果: %s\n", dst2);

// 	printf("---\n途中に '\\0' を含む文字列をコピーする場合\n\n");
// 	// 見た目は止まるがコピーはできてる
// 	char	src3[13] = "Hel\0lo, Worl";
// 	char	dst3[13] = "XXXXXXXXXXXX";
// 	char	dst4[13] = "XXXXXXXXXXXX";

// 	printf("src: %s\n", src3);

// 	ft_memcpy(dst3, src3, 8);
// 	memcpy(dst4, src3, 8);

// 	printf("ft_memcpy の結果: %s\n", dst3);
// 	printf("memcpy の結果: %s\n", dst4);

// 	printf("---\n指定文字数が0の場合\n\n");
// 	char	src5[13] = "Hello, World";
// 	char	dst5[13] = "XXXXXXXXXXXX";
// 	char	dst6[13] = "XXXXXXXXXXXX";

// 	ft_memcpy(dst5, src5, 0);
// 	memcpy(dst6, src5, 0);

// 	printf("ft_memcpy の結果: %s\n", dst5);
// 	printf("memcpy の結果: %s\n", dst6);

// 	// nullを渡すとセグフォ落ち
// 	return (0);
// }