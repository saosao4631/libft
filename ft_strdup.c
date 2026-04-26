/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:58:09 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/26 19:14:06 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dup = (char *)malloc(len);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, len);
	return (dup);
}

// int	main(void)
// {
// 	const char *tests[] = {
// 		"Hello World",
// 		"",
// 		" ",
// 		"1234567890",
// 		"!@#$%^&*()",
// 		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
// 		"Line\nBreak",
// 		NULL
// 	};
// 	int i = 0;

// 	while (tests[i] != NULL)
// 	{
// 		char *my_res = ft_strdup(tests[i]);
// 		char *origin_res = strdup(tests[i]);

// 		printf("%s\n", tests[i]);
// 		printf("自作: [%s] (address: %p)\n", my_res, (void *)my_res);
// 		printf("本家: [%s] (address: %p)\n", origin_res, (void *)origin_res);

// 		free(my_res);
// 		free(origin_res);
// 		printf("\n");
// 		i++;
// 	}

// 	return (0);
// }