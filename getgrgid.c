/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getgrgid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:20:51 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/09 13:21:07 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Print a list of all users in your group
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <grp.h>

int main( void )
  {
    struct group* g;
    char** p;

    if( ( g = getgrgid( getgid() ) ) == NULL ) {
      fprintf( stderr, "getgrgid: NULL pointer\n" );
      return( EXIT_FAILURE );
    }
    printf( "group name:%s\n", g->gr_name );
    for( p = g->gr_mem; *p != NULL; p++ ) {
      printf( "\t%s\n", *p );
    }
    return( EXIT_SUCCESS );
  }
