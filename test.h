/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoe <wchoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:06:10 by wchoe             #+#    #+#             */
/*   Updated: 2024/10/03 20:50:09 by wchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# define FALSE 0
# define TRUE 1
# include "libft.h"

int	my_bool(int value);
int	sign(int value);
char	add1(unsigned int i, char c);
char	sub1(unsigned int i, char c);
char	addi(unsigned int i, char c);
char	subi(unsigned int i, char c);
char	mul1(unsigned int i, char c);
char	muli(unsigned int i, char c);
void	add1_v(unsigned int i, char* c);
void	sub1_v(unsigned int i, char* c);
void	addi_v(unsigned int i, char* c);
void	subi_v(unsigned int i, char* c);
void	mul1_v(unsigned int i, char* c);
void	muli_v(unsigned int i, char* c);
void	print_lst(t_list *lst);
void	del_str(void *str);
#endif
