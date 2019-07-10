/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:22:07 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/09 12:22:43 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main( void )
  {
    struct stat buf;

    if( stat( "file", &buf ) != -1 ) {
      printf( "File size = %lld\n", buf.st_size );
    }
    return EXIT_SUCCESS;
  }
