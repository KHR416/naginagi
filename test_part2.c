/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoe <wchoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:37:58 by wchoe             #+#    #+#             */
/*   Updated: 2024/10/06 16:00:11 by wchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*strs[] = {
						"", "a", "z", "A", "Z",
						"aa", "ab", "az", "bb", "bz", "zz", "AA", "AZ", "ZA", "ZZ",
						"aaa", "a+a", "a-a", "a*a", "a/a", "zza", "zzz",
						"\t", "\r", "\a", "aaaaaa", "bbbbbbbbbbbbbbbbb", "cccccccccccccccc",
						"\1", "\x7F", "\x80", "\xFF", "abcdef", "naginaig",
						"aa\001bb\\\007\n!@#$^&*()|%%", "NAGINAGI", "Hello World!",
						"aspoidf7vw597300mj-d08rc92rn7918r39f8ba-9ef8 yayf78d6-v8a98dfujqk23r 89d7as-d8 audsf23 r",
						"000", "1234x1234", "\t\r   ---\a", "\t\r -1234", "-12340++a77", "2147483647", "2147483648", "-2147483647", "-2147483648",
						NULL
						};

	fputs("test part2\n", stdout);
	for (int i = 0; strs[i] != NULL; ++i)
		for (unsigned int start = 0; start < 100; ++start)
			for (size_t	len = 0; len < 100; ++len)
			{
				char	*substr = ft_substr(strs[i], start, len);
				size_t	s_len = strlen(strs[i]);
				if (len == 0 || start >= strlen(strs[i]))
					assert(*substr == 0);
				else
				{
					size_t	expected_len = s_len - start < len ? s_len - start : len;
					assert(memcmp(substr, strs[i] + start, expected_len) == 0);
					assert(substr[expected_len] == '\0');
				}
				free(substr);
			}
	for (int i = 0; strs[i] != NULL; ++i)
		for (int j = 0; strs[j] != NULL; ++j)
		{
			char	*joined = ft_strjoin(strs[i], strs[j]);
			size_t	s1_len = strlen(strs[i]);
			size_t	s2_len = strlen(strs[j]);
			assert(memcmp(joined, strs[i], s1_len) == 0);
			assert(memcmp(joined + s1_len, strs[j], s2_len) == 0);
			assert(joined[s1_len + s2_len] == '\0');
			free(joined);
		}
	for (int i = 0; strs[i] != NULL; ++i)
		for (int j = 0; strs[j] != NULL; ++j)
		{
			char	*trimmed = ft_strtrim(strs[i], strs[j]);
			size_t	str_len = strlen(strs[i]);
			if (str_len == 0)
				assert(*trimmed == '\0');
			else if (strlen(strs[j]) == 0)
				assert(strcmp(trimmed, strs[i]) == 0);
			else
			{			
				size_t	start = -1;
				while (++start < str_len)
					if (strchr(strs[j], strs[i][start]) == NULL)
						break;
				size_t	end = str_len;
				while (--end > 0)
					if (strrchr(strs[j], strs[i][end]) == NULL)
						break;
				size_t	nbytes = end >= start ? end - start + 1 : 0;
				assert(trimmed[nbytes] == '\0');
				assert(memcmp(trimmed, strs[i] + start, nbytes) == 0);
			}
			free(trimmed);
		}
	for (size_t i = 0; strs[i] != NULL; ++i)
		for (unsigned char c = 0; c <= 0x7F; ++c)
		{
			char	**splitted = ft_split(strs[i], c);
			size_t	str_idx = 0;
			size_t str_len = strlen(strs[i]);
			for (; strs[i][str_idx] == c && str_idx < str_len; ++str_idx);
			for (size_t sp_idx = 0; splitted[sp_idx] != NULL; ++sp_idx)
			{
				if (c)
					assert(strchr(splitted[sp_idx], c) == NULL);
				for (size_t k = 0, len = strlen(splitted[sp_idx]); k < len; ++k)
					assert(splitted[sp_idx][k] == strs[i][str_idx++]);
				for (; strs[i][str_idx] == c && str_idx < str_len; ++str_idx);
			}
			for (size_t sp_idx = 0; splitted[sp_idx] != NULL; ++sp_idx)
				free(splitted[sp_idx]);
			free(splitted);
		}
	char	*nptrs[] = {
		"-2147483648", "-214748364", "-21474836", "-2147483", "-214748", "-12345", "-4321", "-333", "-77", "-1",
		"0", "1", "12", "33", "456", "4567", "45678", "987654", "1234567", "21474836", "2147483647",
		NULL
		};
	for (int i = 0; nptrs[i] != NULL; ++i)
	{
		int		intger = atoi(nptrs[i]);
		char	*nptr = ft_itoa(intger);
		assert(strcmp(nptrs[i], nptr) == 0);
		free(nptr);
	}
	fputs("OK :)\n", stdout);
}
