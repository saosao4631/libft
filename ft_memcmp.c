/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:11:48 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 19:08:31 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s1[] = "abc\0def";
// 	char	s2[] = "abc\0xyz";

// 	printf("自作: %i\n", ft_memcmp("abc", "abd", 3));
// 	printf("本家: %i\n\n", memcmp("abc", "abd", 3));

// 	printf("自作: %i\n", ft_memcmp("hello", "hello", 5));
// 	printf("本家: %i\n\n", memcmp("hello", "hello", 5));

// 	printf("自作: %i\n", ft_memcmp(s1, s2, 7));
// 	printf("本家: %i\n\n", memcmp(s1, s2, 7));

// 	printf("自作: %i\n", ft_memcmp(s1, s2, 0));
// 	printf("本家: %i\n\n", memcmp(s1, s2, 0));

// 	return (0);
// }