/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:59:26 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/25 13:44:56 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// int	main(void)
// {
// 	char	str[12] = "Hello, World";

// 	printf("文字列の長さは：%zu\n", ft_strlen(str));
// 	// ld long  lu 符号なしlong z size_tサイズ合わせ u 符号なし
// 	return (0);
// }