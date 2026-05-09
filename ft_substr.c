/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:10:28 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 21:12:33 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_substr("Hello, World!", 0, 5);
// 	printf("通常            => \"%s\"\n", result);
// 	free(result);

// 	result = ft_substr("Hello, World!", 7, 5);
// 	printf("途中から        => \"%s\"\n", result);
// 	free(result);

// 	result = ft_substr("Hello", 1, 1);
// 	printf("1文字           => \"%s\"\n", result);
// 	free(result);

// 	result = ft_substr("Hello", 0, 100);
// 	printf("lenが長すぎる   => \"%s\"\n", result);
// 	free(result);

// 	result = ft_substr("Hello", 3, 100);
// 	printf("lenが超過       => \"%s\"\n", result);
// 	free(result);

// 	result = ft_substr("Hello", 5, 3);
// 	printf("startが末尾     => \"%s\"\n", result);
// 	free(result);

// 	result = ft_substr("Hello", 99, 3);
// 	printf("startが範囲外   => \"%s\"\n", result);
// 	free(result);

// 	result = ft_substr("Hello", 0, 0);
// 	printf("len=0           => \"%s\"\n", result);
// 	free(result);

// 	result = ft_substr(NULL, 0, 5);
// 	printf("s=NULL          => %s\n", result == NULL ? "NULL" : result);

// 	result = ft_substr("", 0, 5);
// 	printf("s=空文字列      => \"%s\"\n", result);
// 	free(result);

// 	return (0);
// }