/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoe <wchoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:07:30 by wchoe             #+#    #+#             */
/*   Updated: 2024/10/03 20:53:43 by wchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	my_bool(int value)
{
	if (value == 0)
		return (FALSE);
	else
		return (TRUE);
}

int	sign(int value)
{
	if (value > 0)
		return (1);
	else if (value < 0)
		return (-1);
	else
		return (0);
}
char	add1(unsigned int i, char c)
{
	++i;
	return (c + 1);
}
char	sub1(unsigned int i, char c)
{
	++i;
	return (c - 1);
}
char	addi(unsigned int i, char c)
{
	++i;
	return (c + i);
}
char	subi(unsigned int i, char c)
{
	++i;
	return (c - i);
}
char	mul1(unsigned int i, char c)
{
	++i;
	return (c);
}
char	muli(unsigned int i, char c)
{
	++i;
	return (c * i);
}

void	add1_v(unsigned int i, char* c)
{
	++i;
	*c += 1;
}
void	sub1_v(unsigned int i, char* c)
{
	++i;
	*c -= 1;
}
void	addi_v(unsigned int i, char* c)
{
	*c += i;
}
void	subi_v(unsigned int i, char* c)
{
	*c -= i;
}
void	mul1_v(unsigned int i, char* c)
{
	++i;
	++c;
}
void	muli_v(unsigned int i, char* c)
{
	*c *= i;
}
void	print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

void	del_str(void *str)
{
	free(str);
}