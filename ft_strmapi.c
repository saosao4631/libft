/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:12:53 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 21:28:32 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// static char	to_upper(unsigned int i, char c)
// {
// 	(void)i;
// 	return (ft_toupper(c));
// }

// static char	to_lower(unsigned int i, char c)
// {
// 	(void)i;
// 	return (ft_tolower(c));
// }

// int	main(void)
// {
// 	char	*result;

// 	result = ft_strmapi("hello", to_upper);
// 	printf("大文字変換 => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strmapi("HELLO", to_lower);
// 	printf("小文字変換 => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strmapi("", to_upper);
// 	printf("空文字列   => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strmapi("a", to_upper);
// 	printf("1文字      => \"%s\"\n", result);
// 	free(result);

// 	result = ft_strmapi(NULL, to_upper);
// 	printf("sがNULL    => %s\n", result == NULL ? "NULL" : result);

// 	result = ft_strmapi("hello", NULL);
// 	printf("fがNULL    => %s\n", result == NULL ? "NULL" : result);

// 	return (0);
// }