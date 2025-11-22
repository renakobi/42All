/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:08:54 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/06/02 18:42:50 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*c;

	c = malloc(sizeof(t_list));
	if (!c)
		return (NULL);
	if (!c)
		return (NULL);
	c->content = content;
	c->next = NULL;
	return (c);
}
//so we set the list variable content to take 'content' from this 
//fucntion as the data of the node while we initialised the next 
//of the node to be null since the last node in a list is always 
//null just like how a null terminator works 
/*
#include <assert.h>
int main(){
	 t_list *node = ft_lstnew("Test Content");
    assert(node != NULL); 
    assert(node->content != NULL);
    assert(node->next == NULL); // Ensure the next pointer is NULL
    printf("ft_lstnew test passed!\n");
}*/