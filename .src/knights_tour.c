#include <ctype.h>
#include <stdio.h>
#include "knights_tour.h"
#include <stdlib.h>
#include <time.h>

const size_t MOVES[MOVE_COUNT][2] = {
    {2, 1},
    {1, 2},
    {-1, 2},
    {-2, 1},
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1}};

int Move_is_possible(size_t move_id, size_t x, size_t y, board_t chessboard)
{
  x += MOVES[move_id][0];
  y += MOVES[move_id][1];

  // printf_s("position after choice %d(%d,%d): %d, %d :: ", move_id, MOVES[move_id][0], MOVES[move_id][1], x, y);

  // is move within board

  if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
    return 0;

  // is spot already visited
  if (chessboard[x][y])
    return 0;

  // printf_s("succes\n");
  return 1;
}

int Possible_moves(size_t x, size_t y, board_t chessboard)
{
  int count = 0;
  for (int i = 0; i < MOVE_COUNT; i++)
  {
    if (Move_is_possible(i, x + MOVES[i][0], y + MOVES[i][1], chessboard))
      count++;
  }
  return count;
}

void Tour_from_each_square(unsigned int (*Tour)(size_t, size_t))
{
  for (size_t x = 0; x < SIZE; ++x)
  {
    for (size_t y = 0; y < SIZE; ++y)
    {
      unsigned int count = Tour(x, y);
      printf("%2u ", count);
    }
    printf("\n");
  }
  return;
}

unsigned int Tour_first(size_t x, size_t y)
{
  board_t chessboard = {0};
  chessboard[x][y] = 1;
  unsigned int count = 0;
Start:
  // printf_s("\n\nmove %i : position -> %i, %i\n", count, pos_x, pos_y);
  for (size_t move_id = 0; move_id < MOVE_COUNT; ++move_id)
  {
    if (Move_is_possible(move_id, x, y, chessboard))
    {
      count++;
      chessboard[x][y] = VISITED;
      x += MOVES[move_id][0];
      y += MOVES[move_id][1];
      goto Start;
    }
  }

  return count;
}

unsigned int Tour_random(size_t x, size_t y)
{
  board_t chessboard = {0};
  chessboard[x][y] = 1;
  unsigned int count = 0;

  int move_ids[MOVE_COUNT];
  for (int i = 0; i < MOVE_COUNT; i++)
    move_ids[i] = i;

Start:
  Shuffle(move_ids, MOVE_COUNT);

  for (int i = 0; i < MOVE_COUNT; i++)
  {
    size_t move_id = move_ids[i];
    if (Move_is_possible(move_id, x, y, chessboard))
    {
      count++;
      chessboard[x][y] = VISITED;
      x += MOVES[move_id][0];
      y += MOVES[move_id][1];
      goto Start;
    }
  }

  return count;
}

unsigned int Tour_greedy(size_t x, size_t y)
{
  //   board_t chessboard = {0};
  //   chessboard[x][y] = 1;

  // Start:
  //   for (int i = 0; i < MOVE_COUNT; i++)
  //     if (!Move_is_possible(i, x, y, chessboard))
  //       continue;

  //   int best_move[2] = {-1};
  //   for (int i = 0; i < MOVE_COUNT; i++)
  //   {
  //     int temp_moves = Possible_moves(x, y, 0, 0, chessboard);

  //     if (temp_moves > best_move[1])
  //     {
  //       best_move[0] = i;
  //       best_move[1] = temp_moves;
  //     }
  //   }

  //   // count++;
  //   // chessboard[x][y] = VISITED;
  //   // x += MOVES[best_move[0]][0];
  //   // y += MOVES[best_move[0]][1];
  //   // goto Start;
  //   return best_move[1];

  return 1;
}

unsigned int Tour_recursive(size_t x, size_t y, size_t depth)
{
  // Start:
  board_t chessboard = {0};
  chessboard[x][y] = 1;
  unsigned int count = 0;

  return 1;
}

// https://stackoverflow.com/questions/6127503/shuffle-array-in-c
void Shuffle(int *array, size_t n)
{
  if (n > 1)
  {
    size_t i;
    for (i = 0; i < n - 1; i++)
    {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}