/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:15:58 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/26 15:03:47 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	long	final_cheak;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	final_cheak = sign * result;
	if (final_cheak > INT_MAX || final_cheak < INT_MIN)
		return (0);
	return (sign * result);
}

// int	main(void)
// {
// 	const char *tests[] = {
// 		"12345",
// 		"-42",
// 		"   +84",
// 		" \t\n\v\f\r 404",
// 		"2147483647",
// 		"-2147483648",
// 		"0000042",
// 		"42Tokyo",
// 		"42 24",
// 		"++42",
// 		"+-42",
// 		"-",
// 		"",
// 		"a42",
// 		NULL
// 	};
// 	int	i = 0;

// 	while (tests[i] != NULL)
// 	{
// 		printf("テスト: %s\n", tests[i]);
// 		printf("自作: %d\n", ft_atoi(tests[i]));
// 		printf("本家: %d\n\n", atoi(tests[i]));
// 		i++;
// 	}

// 	return (0);
// }