/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:10:28 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/26 20:48:28 by ksaotome         ###   ########.fr       */
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

// int main(void)
// {
//     char *result;

//     result = ft_substr("Hello, World!", 0, 5);
//     printf("[%s] 通常 => \"%s\"\n", strcmp(result, "Hello") == 0 ? "OK" : "NG", result);
//     free(result);

//     result = ft_substr("Hello, World!", 7, 5);
//     printf("[%s] 途中から => \"%s\"\n", strcmp(result, "World") == 0 ? "OK" : "NG", result);
//     free(result);

//     result = ft_substr("Hello", 1, 1);
//     printf("[%s] 1文字 => \"%s\"\n", strcmp(result, "e") == 0 ? "OK" : "NG", result);
//     free(result);

//     result = ft_substr("Hello", 0, 100);
//     printf("[%s] lenが長すぎる => \"%s\"\n", strcmp(result, "Hello") == 0 ? "OK" : "NG", result);
//     free(result);

//     result = ft_substr("Hello", 3, 100);
//     printf("[%s] startからlenが超過 => \"%s\"\n", strcmp(result, "lo") == 0 ? "OK" : "NG", result);
//     free(result);

//     result = ft_substr("Hello", 5, 3);
//     printf("[%s] startが末尾 => \"%s\"\n", strcmp(result, "") == 0 ? "OK" : "NG", result);
//     free(result);

//     result = ft_substr("Hello", 99, 3);
//     printf("[%s] startが範囲外 => \"%s\"\n", strcmp(result, "") == 0 ? "OK" : "NG", result);
//     free(result);

//     result = ft_substr("Hello", 0, 0);
//     printf("[%s] len=0 => \"%s\"\n", strcmp(result, "") == 0 ? "OK" : "NG", result);
//     free(result);

//     result = ft_substr(NULL, 0, 5);
//     printf("[%s] s=NULL\n", result == NULL ? "OK" : "NG");

//     result = ft_substr("", 0, 5);
//     printf("[%s] s=空文字列 => \"%s\"\n", strcmp(result, "") == 0 ? "OK" : "NG", result);
//     free(result);

//     return (0);
// }