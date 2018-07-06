#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

const unsigned int GRID_MAX = 50;

class Cursor
{
public:
  string symbol;
  unsigned int x_coord;
  unsigned int y_coord;

  Cursor() {};
  Cursor(string sym, unsigned int y, unsigned int x);
  void setCursor(string sym, unsigned int y, unsigned int x);
};

class Grid
{
  string m_grid[GRID_MAX][GRID_MAX];
  unsigned int m_width, m_height;

public:
  Grid();
  Grid(const unsigned int width, const unsigned int height);
  unsigned int getWidth() {return m_width;};
  unsigned int getHeight() {return m_height;};
  void insert(const unsigned int y, const unsigned int x, const string sym);
  void insert(Cursor c);
  void remove(const unsigned int y, const unsigned int x, const string sym);
  void remove(Cursor c);
  void print(bool border = false, bool buffer = false);
};

#endif
