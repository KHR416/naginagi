/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoe <wchoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:48:26 by wchoe             #+#    #+#             */
/*   Updated: 2024/10/03 20:57:14 by wchoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
#include <string.h>
#include <stdio.h>

void	*my_strdup(void *str)
{
	return (strdup((char *)str));
}

int main() {
	t_list  *list;

	list = ft_lstnew(strdup("Hello World!"));
	print_lst(list);
	ft_lstadd_front(&list, ft_lstnew(strdup("YAY")));
	print_lst(list);
	ft_lstadd_back(&list, ft_lstnew(strdup("NO")));
	print_lst(list);
	t_list *new_list = ft_lstmap(list, &my_strdup, del_str);
	ft_lstclear(&list, &del_str);
	print_lst(list);
	print_lst(new_list);
	ft_lstclear(&new_list, &del_str);

	return 0;
}