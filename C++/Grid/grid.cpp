
#include "grid.h"

// ====================================
// ---------------CURSOR---------------
// ====================================
// Parameterized Constructor
Cursor::Cursor(string sym, unsigned int y, unsigned int x)
{
  symbol = sym;
  x_coord = x;
  y_coord = y;
  return;
}

// sets Cursor values
void Cursor::setCursor(string sym, unsigned int y, unsigned int x)
{
  symbol = sym;
  x_coord = x;
  y_coord = y;
  return;
}

// ===================================
// ---------------GRID----------------
// ===================================
// Default Constructor
Grid::Grid()
{
  m_width = GRID_MAX;
  m_height = GRID_MAX;

  for(int y = 0; y < GRID_MAX; y++)
  {
    for(int x = 0; x < GRID_MAX; x++)
    {
      m_grid[y][x] = ' ';
    }
  }
  return;
}

// Parameterized Constructor
Grid::Grid(const unsigned int width, const unsigned int height)
{
  m_width = width;
  m_height = height;

  for(int y = 0; y < m_height; y++)
  {
    for(int x = 0; x < m_width; x++)
    {
      m_grid[y][x] = ' ';
    }
  }
  return;
}

// inserts passed character to passed coordinates on 2D array grid
void Grid::insert(const unsigned  int y, const unsigned int x, const string sym)
{
  m_grid[y][x] = sym;
  return;
}

// inserts cursor into grid
void Grid::insert(Cursor c)
{
  m_grid[c.y_coord][c.x_coord] = c.symbol;
  return;
}

// replaces character in passed coordinates with blank space
void Grid::remove(const unsigned int y, const unsigned int x, const string sym)
{
  m_grid[y][x] = ' ';
  return;
}

// removes cursor from grid
void Grid::remove(Cursor c)
{
  m_grid[c.y_coord][c.x_coord] = ' ';
  return;
}

// prints out grid
void Grid::print(bool border, bool buffer)
{
  if(border && buffer)
  {
    for(int x = 0; x < m_width * 2 + 3; x++)
      cout << "|";
    cout << endl;
    for(int y = 0; y < m_height; y++)
    {
      for(int x = 0; x < m_width; x++)
      {
        if(x == 0)
          cout << "||";
        cout << m_grid[y][x] << "|";
        if(x == m_width - 1)
          cout << "|" << endl;
      }
    }
    for(int x = 0; x < m_width * 2 + 3; x++)
      cout << "|";
    cout << endl;
  }

  else if(border && !buffer)
  {
    for(int x = 0; x < m_width * 2 + 3; x++)
      cout << "|";
    cout << endl;
    for(int y = 0; y < m_height; y++)
    {
      for(int x = 0; x < m_width; x++)
      {
        if(x == 0)
          cout << "||";
        cout << m_grid[y][x];
        if(x != m_width - 1)
          cout << " ";
        if(x == m_width - 1)
          cout << "||" << endl;
      }
    }
    for(int x = 0; x < m_width * 2+ 3; x++)
      cout << "|";
    cout << endl;
  }

  else if(!border && buffer)
  {
    for(int y = 0; y < m_height; y++)
    {
      for(int x = 0; x < m_width; x++)
      {
        if(x == 0)
          cout << "|";
        cout << m_grid[y][x] << "|";
        if(x == m_width - 1)
          cout << endl;
      }
    }
  }

  else
  {
    for(int y = 0; y < m_height; y++)
    {
      for(int x = 0; x < m_width; x++)
      {
        cout << m_grid[x][y];
        if(x == m_width - 1)
          cout << endl;
      }
    }
  }
  return;
}
