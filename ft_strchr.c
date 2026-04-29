/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 22:58:04 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 19:29:30 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

// int	main(void)
// {
// 	char	c[8] = "42tokyo";

// 	printf("t: %s\n", ft_strchr(c, 't'));
// 	printf("t: %s\n", strchr(c, 't'));
// 	printf("a: %s\n", ft_strchr(c, 'a'));
// 	printf("a: %s\n", strchr(c, 'a'));
// 	printf(" : %s\n", ft_strchr(c, ' '));
// 	printf(" : %s\n", strchr(c, ' '));
// 	printf("null: %s\n", ft_strchr(c, '\0'));
// 	printf("null: %s\n", strchr(c, '\0'));

// 	char	d[9] = "42ttokyo";

// 	printf("t: %s\n", ft_strchr(d, 't'));
// 	printf("t: %s\n", strchr(d, 't'));
// 	return (0);
// }