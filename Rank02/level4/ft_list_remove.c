typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;

	if (!begin_list || !(*begin_list))
		return ;
	if (!cmp((*begin_list)->data, data_ref))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
}
