/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:22:20 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/09 13:34:29 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <dirent.h>
//#include "ft_ls.h"

int main( void )
{
	/*typedef struct	s_direct
	{
		DIR*			dirp;
		char			*d_name;
	}					t_files;*/
    DIR* dirp;
    struct dirent* direntp;

    dirp = opendir( "/goinfre/sminnaar/Desktop/ft_ls" );
    if( dirp == NULL ) {
        perror( "can't open ~/sminnaar/Desktop" );
    } else {
        for(;;) {
            direntp = readdir( dirp );
            if( direntp == NULL )
            	break;
            ft_putendl(direntp->d_name);
        }
        closedir( dirp );
    }
    dirp = opendir(".");
    if (dirp == NULL)
    	return (ERROR);
    len = strlen(libft);
    while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->dnamelen == len && strcmp(dp->d_name, libft) == 0)
		{
			(void)closedir(dirp);
			return (FOUND);
		}
	}
	(void)closedir(dirp);

    return EXIT_SUCCESS;
}
