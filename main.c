#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int go_right(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count);
int go_down(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count);
int go_up(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count);
int go_left(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count);

int nb_tetri(char *chaine)
{
  int count;
  int time;
  int i;

  i = 0;
  time = 0;
  count = 0;
  while(chaine[i] != '\0')
    {
      while(time < 4)
	{
	  while(chaine[i] != '\n')
	    {
	      i++;
	    }
	  i++;
	  time++;
	}
      count++;
      time = 0;
      if(chaine[i] == '\0')
	return (count);
      i++;
    }
  return (count);
}

char ***all_tetri(char *chaine)
{
  char ***tab;
  int i;
  int nb;
  int index;
  int l;
  int c;

  l = 0;
  c = 0;
  index = 0;
  nb = nb_tetri(chaine);
  i = 0;
  tab = (char ***)malloc(sizeof(char **) * nb + 1);
  while(i < nb + 1)
    {
      while(l < 4)
	{
	  tab[i] = (char **)malloc(sizeof(char *) * 5);      
	  l++;
	}
      l = 0;
      i++;
    }
  l = 0;
  i = 0;
  while(i < nb + 1)
    {
      while(l < 4)
	{
	  while(c < 6)
	    {
	      tab[i][l] = (char *)malloc(sizeof(char) * 6);
	      c++;
	    }
	  c = 0;
	  l++;
	}
      l = 0;
      i++;
    }
  l = 0;
  c = 0;
  i = 0;
  while(i < nb)
    {
      while(l < 4)
	{
	  while(chaine[index] != '\n')
	    {
	      tab[i][l][c] = chaine[index];
	      c++;
	      index++;
	    }
	  tab[i][l][c] = '\n';
	  if(l == 3)
	    tab[i][l][c + 1] = '\0';   
	  c = 0;
	  index++;
	  l++;
	}
      index++;
      l = 0;
      c = 0;
      i++;
      }
  return (tab);
}

int plat_width(char *chaine)
{
  int i;
  int count;

  count = 0;
  i = 0;
  while(chaine[i] != '\0')
    {
      if(chaine[i] == '\n')
	count++;
      i++;
    }
  return (count - 1);
}
int plat_length(char *chaine)
{
  int i;

  i = 0;
  while(chaine[i] != '\n')
    {
      i++;
    }
  return (i);
}

char **plateau(int g)
{
  char **tab;
  int i;
  int i2;
  
  i2 = 0;
  i = 0;
  tab = (char **)malloc(sizeof(char *) * g + 1);
  while (i < g + 1)
    {
      tab[i] = (char *)malloc(sizeof(char) * g + 1);
      i++;
    }
  i = 0;
  while (i < g)
    {
      while(i2 < g)
	{
	  tab[i][i2] = '.';
	  i2++;
	}
      i2 = 0;
      i++; 
    }
  return (tab);
}

void aff(char **plat, int g)
{
  int l;
  int c;

  l = 0;
  c = 0;
  while (l < g)
    {
      while(c < g)
	{
	  printf("%c",plat[l][c]);
	  c++;
	}
      printf("\n");
      c = 0;
      l++;
    }
}
     
char **trans_di(char **tab, char carac, int g)
{
  int l;
  int c;

  l = 0;
  c = 0;
  while (l < g)
    {
      while(c < g)
	{
	  if(tab[l][c] != '.')
	    tab[l][c] = carac;	 
	  c++;
	}
      c = 0;
      l++;
    }
  return (tab);
}

int try(char **plat, char **piece, int platl, int platc, int piecel, int piecec)
{
  int count;

  count = 0;
  if(plat[platl][platc] == '.' && piece[piecel][piecec] == '#')
    count++;
  else
    return (0);
  plat[platl][platc] = 'x';
  piece[piecel][piecec] = 'x';
   if(piece[piecel][piecec + 1] == '#' && plat[platl][platc + 1]== '.')
    {
      count = go_right(plat, piece, platl, platc, piecel, piecec, count);
    }
  if(piece[piecel + 1][piecec] == '#' && plat[platl + 1][platc]== '.')
    {
      count = go_down(plat, piece, platl, platc, piecel, piecec, count);
    }
  if(piecel > 0)
    if(piece[piecel - 1][piecec] == '#' && plat[platl - 1][platc]== '.')
      {
	count = go_up(plat, piece, platl, platc, piecel, piecec, count);
      }
  if(piecec > 0)
    if(piece[piecel][piecec - 1] == '#' && plat[platl][platc - 1]== '.')
      {
	count = go_left(plat, piece, platl, platc, piecel, piecec, count);
      }
  if(count == 4)
    return (1);
  return (0);
}
int *first_die(char **tab, int *coor)
{
  int l;
  int c;

  l = 0;
  c = 0;
      while(l < 4)
	{
	  while(c < 4)
	    {
	      if(tab[l][c] == '#')
		{
		  coor[0] = l;
		  coor[1] = c;
		  return (coor);
		}
	      c++;
	    }
	  c = 0;
	  l++;
	}
  return (coor);
}
int main()
{
  char *piece =  ft_strdup("....\n.##.\n..##\n....\n\n###.\n.#..\n....\n....\n\n####\n....\n....\n....\n");
  char ***tab = all_tetri(piece);
  char **plat;
  int *coor;

  coor = (int *)malloc(sizeof(int) * 3);
  coor = first_die(tab[0], coor);
  plat = plateau(10);
  printf("%d", try(plat, tab[0], 0, 0, coor[0], coor[1]));
  aff(plat, 10);
  return (0);
}
