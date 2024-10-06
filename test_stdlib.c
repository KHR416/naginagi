/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdlib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoe <wchoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:49:09 by wchoe             #+#    #+#             */
/*   Updated: 2024/10/06 16:08:24 by wchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int	main(void)
{
	char	*nptrs[] = {
						"", "a", "z", "A", "Z",
						"aa", "ab", "az", "bb", "bz", "zz", "AA", "AZ", "ZA", "ZZ",
						"aaa", "a+a", "a-a", "a*a", "a/a", "zza", "zzz", "AAA", "ZZZ",
						"\t", "\r", "\a", "aaaaaa", "bbbbbbbbbbbbbbbbb", "cccccccccccccccc",
						"naginagi", "\x7F", "\x80", "\xFF", "yeah", "123456asdfb",
						"aa\001bb\\\007\n!@#$^&*()|%%", "NAGINAGI", "Hello World!",
						"aspoidf7vw597300mj-d08rc92rn7918r39f8ba-9ef8 yayf78d6-v8a98dfujqk23r 89d7as-d8 audsf23 r",
						"000", "1234x1234", "\t\r   ---\a", "\t\r -1234", "-12340++a77", "2147483647", "2147483648", "-2147483647", "-2147483648",
						NULL
						};

	fputs("test stdlib\n", stdout);
	for (int i = 0; nptrs[i] != NULL; ++i)
		assert(atoi(nptrs[i]) == ft_atoi(nptrs[i]));
	for (size_t j = 1; j <= 16; ++j)
		for (size_t i = 0; i < 1000; ++i)
		{
			void	*mem1 = calloc(i, j);
			void	*mem2 = ft_calloc(i, j);
			assert(memcmp(mem1, mem2, i * j) == 0);
			free(mem1);
			free(mem2);
		}
	for (size_t i = 1; i <= 1000; ++i)
		assert(ft_calloc(-1, i) == NULL);
	for (size_t i = 1; i <= 1000; ++i)
		assert(ft_calloc(i, -1) == NULL);
	assert(ft_calloc(0x40000000, 0x40000000) == NULL);
	fputs("OK :)\n", stdout);
	return (0);
}
