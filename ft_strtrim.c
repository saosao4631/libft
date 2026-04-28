/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:39:11 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 21:14:12 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	trim = (char *)malloc(j - i + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + i, j - i + 1);
	return (trim);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_strtrim("  Hello, World!  ", " ");
// 	printf("通常            => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strtrim("##  Hello  ##", "# ");
// 	printf("複数文字        => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strtrim("   Hello", " ");
// 	printf("先頭だけ        => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strtrim("Hello   ", " ");
// 	printf("末尾だけ        => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strtrim("aaaa", "a");
// 	printf("全部トリム      => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strtrim("  Hello  ", "");
// 	printf("setが空文字列   => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strtrim("", " ");
// 	printf("s1が空文字列    => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strtrim("Hello World", " ");
// 	printf("中間のみ        => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strtrim("a", "b");
// 	printf("対象外          => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strtrim(NULL, " ");
// 	printf("s1がNULL        => %s\n", result == NULL ? "NULL" : result);

// 	return (0);
// }