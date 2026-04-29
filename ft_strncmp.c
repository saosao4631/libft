/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:05:10 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 18:55:49 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	char	s1[20] = "abcde";
// 	char	s2[20] = "abcdz";

// 	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 5));
// 	printf("本家: %i\n\n", strncmp(s1, s2, 5));

// 	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 3));
// 	printf("本家: %i\n\n", strncmp(s1, s2, 3));

// 	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 99));
// 	printf("本家: %i\n\n", strncmp(s1, s2, 99));

// 	printf("ft_strncmp: %i\n", ft_strncmp(s1, s1, 6));
// 	printf("本家: %i\n\n", strncmp(s1, s1, 6));

// 	return (0);
// }