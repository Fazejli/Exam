/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:02:03 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/13 15:09:40 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	int				data;
	struct s_list 	*next;
}	t_list;


t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*temp;
	int		tmp_data;

	if (!lst)
		return (0);
	temp = lst;
	while (lst && lst->next)
	{
		if (!(*cmp)(lst->data, lst->next->data))
		{
			tmp_data = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp_data;
			lst = temp;
		}
		else
			lst = lst->next;
	}
	return (temp);
}
