/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:03:07 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 18:46:29 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (1)
	{
		if (*s == (char)c)
			last = (char *)s;
		if (*s == '\0')
			return (last);
		s++;
	}
}

// int	main(void)
// {
// 	char	c[20] = "42tokyo";

// 	printf("t: %s\n", ft_strrchr(c, 't'));
// 	printf("t: %s\n", strrchr(c, 't'));
// 	printf("a: %s\n", ft_strrchr(c, 'a'));
// 	printf("a: %s\n", strrchr(c, 'a'));
// 	printf(" : %s\n", ft_strrchr(c, ' '));
// 	printf(" : %s\n", strrchr(c, ' '));
// 	printf("null: %s\n", ft_strrchr(c, '\0'));
// 	printf("null: %s\n", strrchr(c, '\0'));

// 	char	d[20] = "42ttttttottttokyo";

// 	printf("t: %s\n", ft_strrchr(d, 't'));
// 	printf("t: %s\n", strrchr(d, 't'));

// 	return 0;
// }