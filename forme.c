#include <stdio.h>

int go_right(char **chaine, int l, int c, int count);
int go_down(char **chaine, int l, int c, int count);
int go_up(char **chaine, int l, int c, int count);
int go_left(char **chaine, int l, int c, int count);


int go_right(char **chaine, int l, int c, int count)
{
  if(count < 4)
    {
      c = c + 1;
      count++;
      chaine[l][c] = 'x';
      if(chaine[l][c + 1] == '#')
	{
	  count = go_right(chaine , i, count);
	}
      if(chaine[l + 1][c] == '#')
	{
	  count = go_down(chaine, i, count);
	}
      if(chaine[l - 1][c] == '#')
	{
	  count = go_up(chaine, i, count);
	}
      if(chaine[l][c - 1] == '#')
	{
	  count = go_left(chaine, i, count);
	}
    }
  return (count);
}

int go_down(char **chaine, int l, int c, int count)
{
  if(count < 4)
    {
      l = l + 1;
      count++;
      chaine[l][c] = 'x';
      if(chaine[l][c + 1] == '#')
	{
	  count = go_right(chaine , i, count);
	}
      if(chaine[l + 1][c] == '#')
	{
	  count = go_down(chaine, i, count);
	}
      if(chaine[l - 1][c] == '#')
	{
	  count = go_up(chaine, i, count);
	}
      if(chaine[l][c - 1] == '#')
	{
	  count = go_left(chaine, i, count);
	}
    }
  return (count);
}

int go_up(char **chaine, int l, int c, int count)
{
  if(count < 4)
    {
      l = l - 1;
      count++;
      chaine[l][c] = 'x';
      if(chaine[l][c + 1] == '#')
	{
	  count = go_right(chaine , i, count);
	}
      if(chaine[l + 1][c] == '#')
	{
	  count = go_down(chaine, i, count);
	}
      if(chaine[l - 1][c] == '#')
	{
	  count = go_up(chaine, i, count);
	}
      if(chaine[l][c - 1] == '#')
	{
	  count = go_left(chaine, i, count);
	}
    }
  return (count);
}

int go_left(char **chaine, int l, int c, int count)
{
  if(count < 4)
    {
      c = c - 1;
      count++;
      chaine[l][c] = 'x';
      if(chaine[l][c + 1] == '#')
	{
	  count = go_right(chaine , i, count);
	}
      if(chaine[l + 1][c] == '#')
	{
	  count = go_down(chaine, i, count);
	}
      if(chaine[l - 1][c] == '#')
	{
	  count = go_up(chaine, i, count);
	}
      if(chaine[l][c - 1] == '#')
	{
	  count = go_left(chaine, i, count);
	}
    }
  return (count);
}
