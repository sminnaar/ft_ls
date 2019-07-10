/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:11:12 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/09 13:17:32 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>

int main () {
   FILE *fp;

   // first rename if there is any file
   rename("file.txt", "newfile.txt");

   // now let's try to open same file
   fp = fopen("file.txt", "r");
   if( fp == NULL ) {
      perror("Error: ");
      return(-1);
   }
   fclose(fp);
      
   return(0);
}*/
#include <stdio.h>
#include <errno.h>

extern int errno ;

int main ()
{
  FILE * pFile;
  pFile = fopen ("file.txt","rb");
  if (pFile == NULL)
  {
    perror ("The following error occurred");
    printf( "Value of errno: %d\n", errno );
  }
  else
    fclose (pFile);
  return 0;
}
