/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ctype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoe <wchoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:48:16 by wchoe             #+#    #+#             */
/*   Updated: 2024/10/03 15:55:07 by wchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <ctype.h>
#include <stdio.h>
#include <assert.h>

int	main(void)
{
	fputs("test ctype\n", stdout);
	for (unsigned char c = 0; c <= 0x7F; ++c)
	{
		assert(my_bool(isalpha(c)) == my_bool(ft_isalpha(c)));
		assert(my_bool(isdigit(c)) == my_bool(ft_isdigit(c)));
		assert(my_bool(isalnum(c)) == my_bool(ft_isalnum(c)));
		assert(my_bool(isascii(c)) == my_bool(ft_isascii(c)));
		assert(my_bool(isprint(c)) == my_bool(ft_isprint(c)));
		assert(toupper(c) == ft_toupper(c));
		assert(tolower(c) == ft_tolower(c));
	}
	fputs("OK :)\n", stdout);
	return (0);
}
