/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 02:04:59 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 16:03:00 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int main(void)
// {
// 	char	str1[13] = "Hello, World";
//     char	str2[13] = "Hello, World";

//     printf("str: %s\n", str1);

//     ft_memset(str1, '0', 5);
//     memset(str2, '0', 5);

//     printf("ft_memset の結果: %s\n", str1);
//     printf("memset の結果: %s\n", str2);

// 	printf("---\n指定文字が空白の場合\n\n");
// 	char	str3[13] = "Hello, World";
//     char	str4[13] = "Hello, World";

//     printf("str: %s\n", str3);

//     ft_memset(str1, '\0', 5);
//     memset(str2, '\0', 5);

//     printf("ft_memset の結果: %s\n", str1);
//     printf("memset の結果: %s\n", str2);

// 	printf("---\nunsigned char (255) を超える値が渡された場合\n\n");
// 	char	str5[13] = "Hello, World";
//     char	str6[13] = "Hello, World";

//     ft_memset(str5, 256 + 'a', 5);
//     memset(str6, 256 + 'a', 5);

//     printf("ft_memset の結果: %s\n", str5);
//     printf("memset の結果: %s\n", str6);

// 	printf("ft_memset の結果: %s\n", str5);
//     printf("memset の結果: %s\n", str6);

// 	printf("---\n指定文字数が0の場合\n\n");
// 	char	str7[13] = "Hello, World";
//     char	str8[13] = "Hello, World";

//     ft_memset(str7, '\0', (0));
//     memset(str8, '\0', (0));

// 	printf("ft_memset の結果: %s\n", str7);
//     printf("memset の結果: %s\n", str8);

//     return 0;
// }