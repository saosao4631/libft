/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:28:10 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 21:24:16 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	return (res);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_strjoin("Hello, ", "World!");
// 	printf("通常          => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strjoin("", "");
// 	printf("両方空文字列  => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strjoin("", "World!");
// 	printf("s1が空文字列  => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strjoin("Hello, ", "");
// 	printf("s2が空文字列  => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strjoin(NULL, "World!");
// 	printf("s1がNULL      => %s\n", result == NULL ? "NULL" : result);

// 	result = ft_strjoin("Hello, ", NULL);
// 	printf("s2がNULL      => %s\n", result == NULL ? "NULL" : result);

// 	result = ft_strjoin(NULL, NULL);
// 	printf("両方NULL      => %s\n", result == NULL ? "NULL" : result);

// 	result = ft_strjoin("abc", "123");
// 	printf("数字を含む    => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strjoin("a", "b");
// 	printf("1文字同士     => \"%s\"\n", result);
// 	free(result);

// 	return (0);
// }