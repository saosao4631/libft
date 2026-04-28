/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:24:52 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/28 21:19:41 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	to_upper(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = ft_toupper(*c);
// }

// static void	to_lower(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = ft_tolower(*c);
// }

// int	main(void)
// {
// 	char	s1[] = "hello";
// 	char	s2[] = "HELLO";
// 	char	s3[] = "";
// 	char	s4[] = "a";

// 	ft_striteri(s1, to_upper);
// 	printf("大文字変換 => \"%s\"\n", s1);

// 	ft_striteri(s2, to_lower);
// 	printf("小文字変換 => \"%s\"\n", s2);

// 	ft_striteri(s3, to_upper);
// 	printf("空文字列   => \"%s\"\n", s3);

// 	ft_striteri(s4, to_upper);
// 	printf("1文字      => \"%s\"\n", s4);

// 	ft_striteri(NULL, to_upper);
// 	printf("sがNULL    => OK\n");

// 	ft_striteri(s1, NULL);
// 	printf("fがNULL    => OK\n");

// 	return (0);
// }