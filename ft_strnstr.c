/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:13:15 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 19:29:07 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j] && i
			+ j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	const char	*big = "Foo Bar Baz";
// 	char		*ans_ft;

// 	ans_ft = ft_strnstr(big, "Bar", 15);
// 	printf("ft_strnstr: %s\n", ans_ft);

// 	ans_ft = ft_strnstr(big, "", 15);
// 	printf("ft_strnstr: %s\n", ans_ft );

// 	ans_ft = ft_strnstr(big, "Bar", 6);
// 	printf("ft_strnstr: %s\n", ans_ft);

// 	ans_ft = ft_strnstr(big, "Foo", 0);
// 	printf("ft_strnstr: %s\n", ans_ft);

// 	const char *hay2 = "aaabcabcd";
// 	ans_ft = ft_strnstr(hay2, "aabc", 10);
// 	printf("ft_strnstr: %s\n", ans_ft);

// 	return 0;
// }