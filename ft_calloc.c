/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 23:21:20 by ksaotome          #+#    #+#             */
/*   Updated: 2026/04/26 18:57:05 by ksaotome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	t;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	t = count * size;
	if (t == 0)
		t = 1;
	ptr = malloc(t);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, t);
	return (ptr);
}

// int main(void)
// {
// 	// count*sizeした際にオーバーフローすることを防ぐ

//     int *arr_ft = (int *)ft_calloc(5, sizeof(int));
//     int *arr_std = (int *)calloc(5, sizeof(int));

//     int is_zero = 1;
// 	int i = 0;
//     while(i < 5)
// 	{
//         if (arr_ft[i] != 0) 
// 			is_zero = 0;
// 		i++;
//     }
//     printf("自作: %p (0埋め: %s)\n", (void *)arr_ft, is_zero ? "OK" : "NG");
//     printf("本家: %p\n\n", (void *)arr_std);

//     void *zero_ft = ft_calloc(0, 5);
//     void *zero_std = calloc(0, 5);
//     printf("自作: %p \n", zero_ft);
//     printf("本家: %p\n\n", zero_std);

//     void *over_ft = ft_calloc(SIZE_MAX, SIZE_MAX);
//     printf("自作: %s\n", over_ft == NULL ? "NULL" : "NOT NULL");

//     free(arr_ft);
//     free(arr_std);
//     free(zero_ft);
//     free(zero_std);

// 	// 最適化とフラグ: 一部のライブラリ実装では、あまりに巨大すぎる値が渡された際、
// 	// 内部的なチェックの前に「現実的に確保不可能なサイズ」として特殊な扱いをしたり、
// 	// 環境依存の挙動（malloc(0)に近い挙動など）に陥ることがあります。

// 	// 実装の差異: calloc の仕様（C99/C11）では「オーバーフロー時はエラー（NULL）」を推奨していますが、
// 	// OSやコンパイラのバージョンによっては、オーバーフロー後の計算結果（非常に小さな値）で malloc 
// 	// を通してしまう「古い挙動」が残っている場合もあります。

//     return 0;
// }