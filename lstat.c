/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:25:52 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/09 12:26:15 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Iterate through a list of files, and report 
 * for each if it is a symbolic link
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main( int argc, char **argv )
  {
    int ecode = 0;
    int n;
    struct stat sbuf;

    for( n = 1; n < argc; ++n ) {
      if( lstat( argv[n], &sbuf ) == -1 ) {
        perror( argv[n] );
        ecode++;

      } else if( S_ISLNK( sbuf.st_mode ) ) {
        printf( "%s is a symbolic link\n", argv[n] );

      } else {
        printf( "%s is not a symbolic link\n", argv[n] );
      }
    }
    return( ecode );
  }
