#include <string.h>
#include <stdio.h>
#include <stdlib.h>
     #include <sys/types.h>
     #include <sys/uio.h>
     #include <unistd.h>
# define BUF_SIZE 1
char    *ft_strdup(const char *s1);

int go_right(char *chaine, char *piece, int chainei, int piecei, int count, int length);
int go_down(char *chaine, char *piece, int chainei, int piecei, int count, int length);
int go_up(char *chaine, char *piece, int chainei, int piecei, int count, int length);
int go_left(char *chaine, char *piece, int chainei, int piecei, int count, int length);
int *go_rightz(char *chaine, char *piece, int chainei, int piecei, int *count, int length);
int *go_downz(char *chaine, char *piece, int chainei, int piecei, int *count, int length);
int *go_upz(char *chaine, char *piece, int chainei, int piecei, int *count, int lengt);
int *go_leftz(char *chaine, char *piece, int chainei, int piecei, int *count, int length);
int *zone(char *chaine, int chainei, int *count, int length);

int first_di(char *piece)
{
  int i;

  i = 0;
  while(piece[i] != '\0' && piece[i] != '#')
    i++;
  return (i);
}

int try(char *chaine, char *piece, int chainei, int piecei, int length)
{
  int count;

  count = 0;
  if(chaine[chainei] == '.' && piece[piecei] == '#')
    count++;
  else
    return (0);
  chaine[chainei] = 'x';
  piece[piecei] = 'x';
  if(piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
    {
      count = go_right(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei + 5] == '#' && chaine[chainei + length] == '.')
    {
      count = go_down(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 5] == '#' && chaine[chainei - length] == '.')
    {
      count = go_up(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
    {
      count = go_left(chaine, piece, chainei, piecei, count, length);
    }
   if(count == 4)
    return (1);
  return (0);
}

int stock_max(char *chaine, char *piece, int chainei, int piecei, int length)
{
  int *count;

  count = (int *)malloc(sizeof(int)  * 2);
  count[0] = 0;
  count[1] = 0;
  piece[piecei] = 'x';
  count = zone(chaine, chainei, count, length);
  if(piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
    {
      count = go_rightz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei + 5] == '#' && chaine[chainei + length] == '.')
  {
    count = go_downz(chaine, piece, chainei, piecei, count, length);
  }
  if(piece[piecei - 5] == '#' && chaine[chainei - length] == '.')
    {
      count = go_upz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
    {
      count = go_leftz(chaine, piece, chainei, piecei, count, length);
    }
  return (count[0]);
}

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

char **all_tetri(char *chaine)
{
  char **tab;
  int i;
  int nb;
  int index;
  int i2;
  
  i2 = 0;
  index = 0;
  nb = nb_tetri(chaine);
  i = 0;
  tab = (char **)malloc(sizeof(char *) * nb + 1);
  while(i < nb + 1)
    {
      tab[i] = (char *)malloc(sizeof(char) * 20);
      i++;
    }
  i = 0;
  while(i < nb)
    {
      while(i2 < 20 && chaine[index] != '\0')
	{
      	  tab[i][i2] = chaine[index];
      	  i2++;
	  index++;
	}
      tab[i][i2] = '\0';
      i2 = 0;
      index++;
      i++;
    }
  return (tab);
}

char *trans_di(char *chaine, char c)
{
  int i;

  i = 0;
  while(chaine[i] != '\0')
    {
      if(chaine[i] == 'x')
	chaine[i] = c;
      i++;
    }
  return (chaine);
}

char *malloc_chaine(char *chaine, int length)
{
  int i;
  int j;
  int index;
  
  index = 0;
  i = 0;
  j = 0;
  chaine = (char*)malloc(sizeof(char) * (length * (length + 1)) + 1);
  while(i < length)
    {
      while(j < length)
	{
	  chaine[index] = '.';
	  j++;
	  index++;
	}
       chaine[index] = '\n';
       index++;
      j = 0;
      i++;
    } 
    chaine[index] = '\0';
    return (chaine);
}



char  *ft_erase(char *chaine, char carac)
{
  int i;

  i = 0;
  printf("carac del : %c  |", carac);
  while(chaine[i] != '\0')
    {
      if(chaine[i] == carac)
	chaine[i] = '.';
      i++;
    }
  return (chaine);
}

//indexactuel en tab dimension 
char *backtrack(int *iactuel, char *chaine, int tetri, char carac, int length, int chainei, char **tab)
{
  int piecei;
  int i;

  i = 0;
  printf("%s \n",chaine);
  piecei = first_di(tab[tetri]);    
  while(!try(ft_strdup(chaine), ft_strdup(tab[tetri]), chainei, piecei,length) && chaine[chainei] != '\0')
    {
      chainei++;
    }
    if(try(chaine, ft_strdup(tab[tetri]), chainei, piecei,length))
    {
	chaine = trans_di(chaine, carac);
	iactuel[tetri] = chainei;
	tetri++;
	carac++;
	iactuel[tetri] = 0;
	if(tetri  < 8)
	  {
	    chaine = backtrack(iactuel, chaine, tetri, carac,length,0, tab);   
	  }
    }
    else
      {
	if(carac != 'A')
	 {
	    carac--;
	    tetri--;
	    iactuel[tetri]++;
	    while(chaine[i] != '\0')
	      {
		if(chaine[i] == carac)
		  chaine[i] = '.';
		i++;
	      }
	    chaine = backtrack(iactuel, chaine, tetri, carac,length, iactuel[tetri], tab);
	 }
	else
	  {
	    printf("augmente");
	    chaine = malloc_chaine(chaine, ++length);
	    length++;
	    printf("%d", length);
	    chaine = backtrack(iactuel,chaine, 0, 'A',length,0, tab);
	    }

      }
    return (chaine);
}

void ft_all(char *piece)
{
  int chainei;
  int piecei;
  int zone_contact;
  char *chaine;
  int max;
  int f;
  int reali;
  char **tab;
  int tetri;
  int length;
  char carac;
  int i;
  int j;
  int index;
  int *iactuel;
  

  iactuel = (int *)malloc(sizeof(int) * 10);
  tab = all_tetri(ft_strdup(piece));
  i = 0;
  j = 0;
  index = 0;
  carac = 'A';
  length = 2;
  chaine = malloc_chaine(chaine, length);
  tetri = 0;
  reali = 0;
  max = -10;
  zone_contact = 0;
  chainei = 0;
  length++;
chaine = backtrack(iactuel, chaine, tetri, carac, length, chainei, tab);
  printf("\n");
 printf("\033[31m%s", chaine);
  printf("\n");

}
