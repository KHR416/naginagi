/* **************normalize************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:48:16 by wchoe             #+#    #+#             */
/*   Updated: 2024/10/02 13:10:15 by wchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int	main(void)
{
	char	*strs[] = {
						"", "a", "z", "A", "Z",
						"aa", "ab", "az", "bb", "bz", "zz", "AA", "AZ", "ZA", "ZZ",
						"aaa", "a+a", "a-a", "a*a", "a/a", "zza", "zzz",
						"\t", "\r", "\a", "aaaaaa", "bbbbbbbbbbbbbbbbb", "cccccccccccccccc",
						"\001", "\002", "\003", "\004", "\005", "\007",
						"aa\001bb\\\007\n!@#$^&*()|%%", "NAGINAGI", "Hello World!",
						"aspoidf7vw597300mj-d08rc92rn7918r39f8ba-9ef8 yayf78d6-v8a98dfujqk23r 89d7as-d8 audsf23 r",
						"000", "1234x1234", "\t\r   ---\a", "\t\r -1234", "-12340++a77", "2147483647", "2147483648", "-2147483647", "-2147483648",
						NULL
						};
	char	s1[100];
	char	s2[100];

	fputs("test string\n", stdout);
	// ft_strlen
	for (int i = 0; strs[i] != NULL; ++i)
		assert(strlen(strs[i]) == ft_strlen(strs[i]));
	// ft_memset
	for (int i = -512; i <= 512; ++i)
	{
		assert(s1 == memset(s1, i, 100));
		assert(s2 == ft_memset(s2, i, 100));
		assert(memcmp(s1, s2, 100) == 0);
	}
	// ft_memcpy
	for (int i = 0; strs[i] != NULL; ++i)
		for (int j = 0; j <= 100; ++j)
		{
			assert(s1 == memcpy(s1, strs[i], j));
			assert(s2 == ft_memcpy(s2, strs[i], j));
			assert(memcmp(s1, s2, j) == 0);
		}
	// ft_memmove
	for (int i = 0; i < 50; ++i)
		for (int j = 0; i + j < 100; ++j)
		{
			assert(s1 == memmove(s1, s1 + i, j));
			assert(s2 == ft_memmove(s2, s2 + i, j));
			assert(memcmp(s1, s2, j) == 0);
		}
	// ft_strchr
	for (int i = 0; i <= 50000; ++i)
		for (int j = 0; strs[j] != NULL; ++j)
			assert(strchr(strs[j], i) == ft_strchr(strs[j], i));
	// ft_strrchr
	for (int i = 0; i <= 50000; ++i)
		for (int j = 0; strs[j] != NULL; ++j)
			assert(strrchr(strs[j], i) == ft_strrchr(strs[j], i));
	// ft_strncmp
	for (int i = 0; strs[i] != NULL; ++i)
		for (int j = 0; strs[j] != NULL; ++j)
			for (int k = 0; k <= 100; ++k)
				assert(sign(strncmp(strs[i], strs[j], k)) == sign(ft_strncmp(strs[i], strs[j], k)));
	// ft_memchr
	for (int i = -512; i <= 512; ++i)
		for (int j = 0; strs[j] != NULL; ++j)
			for (int k = 0; k <= 100; ++k)
				assert(memchr(strs[j], i, k) == ft_memchr(strs[j], i, k));
	// ft_memcmp
	for (int i = 0; strs[i] != NULL; ++i)
		for (int j = 0; strs[j] != NULL; ++j)
			for (int k = 0; k <= 100; ++k)
				assert(sign(memcmp(strs[i], strs[j], k)) == sign(ft_memcmp(strs[i], strs[j], k)));
	// ft_strdup
	for (int i = 0; strs[i] != NULL; ++i)
	{
		char	*dup1 = strdup(strs[i]);
		char	*dup2 = ft_strdup(strs[i]);
		assert(strcmp(dup1, dup2) == 0);
		free(dup1);
		free(dup2);
	}
	fputs("OK :)\n", stdout);
	return (0);
}
