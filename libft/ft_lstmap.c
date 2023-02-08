/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:10:02 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/10 10:10:04 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;

	if (!lst || !f)
		return (0);
	head = ft_lstnew(f(lst->content));
	current = head;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew((*f)(lst->content));
		if (!current->next)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		current = current->next;
		lst = lst->next;
	}
	return (head);
}

// void	*change(void *data)
// {
// 	int	*newData = malloc(sizeof(*newData));
// 	*newData = *(int*)data * -1;
// 	return newData;
// }

// void	stuff(void* data)
// {
// 	return ;
// }

// int main()
// {
// 	int data = 0;
// 	t_list *head;
// 	t_list *curr;

// 	head = ft_lstnew((void *)&data);
// 	curr = head;

// 	for(int i = 1; i < 9; i++)
// 	{
// 		int	*n = malloc(sizeof(*n));
// 		*n = i;
// 		curr->next = ft_lstnew((void *)n);
// 		curr = curr->next;
// 	}

// 	t_list *newlist = ft_lstmap(head, &change, &stuff);

// 	while (head)
// 	{
// 		printf("%d\n", *((int *)(head->content)));
// 		head = head->next;
// 	}

// 	while (newlist)
// 	{
// 		printf("%d\n", *((int *)(newlist->content)));
// 		newlist = newlist->next;
// 	}
// }