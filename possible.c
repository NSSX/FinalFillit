int go_right(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count);
int go_down(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count);
  int go_up(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count);
  int go_left(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count);

int go_right(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count)
{
  count++;
  piece[piecel][piecec] = 'x';
  piecec = piecec + 1;
  platc = platc + 1;
  plat[platl][platc] = 'x';
  
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
  return (count);
}

int go_down(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count)
{
  count++;
  piece[piecel][piecec] = 'x';
  piecel = piecel + 1;
  platl = platl + 1;
  plat[platl][platc] = 'x';

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
  return (count);
}

int go_up(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count)
{
  count++;
  piece[piecel][piecec] = 'x';
  piecel = piecel - 1;
  platl = platl - 1;
  plat[platl][platc] = 'x';

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
  return (count);
}

int go_left(char **plat, char **piece, int platl, int platc, int piecel, int piecec, int count)
{
  count++;
  piece[piecel][piecec] = 'x';
  piecec = piecec - 1;
  platc = platc - 1;
  plat[platl][platc] = 'x';

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
  return (count);
}