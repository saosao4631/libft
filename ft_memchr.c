/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:10:03 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 19:03:27 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = (const unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

// int main(void)
// {
//     char s[20] = "abc\0defg";
//     char *ans_ft;
//     char *ans_std;

//     ans_ft = (char *)ft_memchr(s, 'b', 5);
//     ans_std = (char *)memchr(s, 'b', 5);
//     printf("ft_memchr: %s\n", ans_ft ? ans_ft : "NULL");
//     printf("本家     : %s\n\n", ans_std ? ans_std : "NULL");

//     ans_ft = (char *)ft_memchr(s, 'z', 5);
//     ans_std = (char *)memchr(s, 'z', 5);
//     printf("ft_memchr: %s\n", ans_ft ? ans_ft : "NULL");
//     printf("本家     : %s\n\n", ans_std ? ans_std : "NULL");

//     ans_ft = (char *)ft_memchr(s, 'a', 0);
//     ans_std = (char *)memchr(s, 'a', 0);
//     printf("ft_memchr: %s\n", ans_ft ? ans_ft : "NULL");
//     printf("本家     : %s\n\n", ans_std ? ans_std : "NULL");

//     ans_ft = (char *)ft_memchr(s, 'e', 8);
//     ans_std = (char *)memchr(s, 'e', 8);
//     printf("ft_memchr: %s\n", ans_ft ? ans_ft : "NULL");
//     printf("本家     : %s\n\n", ans_std ? ans_std : "NULL");

//     return 0;
// }