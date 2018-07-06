#include "grid.h"

int main()
{
  Grid plot(50, 50);
  // Note: cursor coordinates should not be greater than the size of the grid
  Cursor c[plot.getWidth() / 2];
  for(int i = 1; i < plot.getWidth() / 2; i+=2)
  {
    c[i - 1].setCursor("\033[1;31mX\033[0m", i - 1, i - 1);
    c[i].setCursor("\033[1;31mX\033[0m", plot.getWidth() - i, plot.getHeight() - i);
    plot.insert(c[i - 1]);
    plot.insert(c[i]);
  }
  while(1 == 1)
  {
    if(c[0].y_coord == 0 && c[0].x_coord != plot.getWidth() - 1)
    {
      plot.remove(c[0]);
      plot.remove(c[1]);
      c[0].x_coord++;
      c[1].x_coord--;
      plot.insert(c[0]);
      plot.insert(c[1]);
    }
    else if(c[0].y_coord != plot.getHeight() - 1 && c[0].x_coord == plot.getWidth() - 1)
    {
      plot.remove(c[0]);
      plot.remove(c[1]);
      c[0].y_coord++;
      c[1].y_coord--;
      plot.insert(c[0]);
      plot.insert(c[1]);
    }
    else if(c[0].y_coord == plot.getHeight() - 1 && c[0].x_coord != 0)
    {
      plot.remove(c[0]);
      plot.remove(c[1]);
      c[0].x_coord--;
      c[1].x_coord++;
      plot.insert(c[0]);
      plot.insert(c[1]);
    }
    else
    {
      plot.remove(c[0]);
      plot.remove(c[1]);
      c[0].y_coord--;
      c[1].y_coord++;
      plot.insert(c[0]);
      plot.insert(c[1]);
    }
    plot.print(true, false);

    usleep(50000);
  }

  return 0;
}
