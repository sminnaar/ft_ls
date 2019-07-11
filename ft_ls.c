/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:22:20 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/11 14:57:57 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

int main( void )
{
    DIR				*temp;
    DIR				*temp2;
    struct dirent	*source;
    struct dirent	*soup;

    temp = opendir( "./Test" );
    if( temp == NULL )
    {
        perror( "can't open Root ");
    }
    else
    {
        while (temp != NULL)
        {
        	ft_putendl("First while loop");
            source = readdir( temp );
            if( source == NULL )
            	break;
            if (ft_strcmp(source->d_name, ".") || ft_strcmp(source->d_name, ".."))
            	source = readdir(temp);
            ft_putendl(source->d_name);
            if ((temp2 = opendir(source->d_name)) != NULL)
			{
				while (temp2 != NULL)
				{
					ft_putendl("Second while loop");
					soup = readdir(temp2);
					if (soup == NULL)
						break ;
					ft_putendl(soup->d_name);
				}
				closedir(temp2);
			}
        }
        closedir( temp );
    }
    return EXIT_SUCCESS;
}
