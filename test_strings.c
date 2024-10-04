/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:50:36 by wchoe             #+#    #+#             */
/*   Updated: 2024/10/01 21:58:59 by wchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <assert.h>

int	main(void)
{
	char	s1[100];
	char	s2[100];

	fputs("test strings\n", stdout);
	for (int i = 0; i <= 100; ++i)
	{
		memset(s1, 1, 100);
		memset(s2, 1, 100);
		bzero(s1, i);
		ft_bzero(s2, i);
		assert(memcmp(s1, s2, 100) == 0);
	}
	fputs("OK :)\n", stdout);
	return (0);
}
