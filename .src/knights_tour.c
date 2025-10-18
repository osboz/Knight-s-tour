#include <ctype.h>
#include <stdio.h>
#include "knights_tour.h"
#include <stdlib.h>

/**
 * Knight move offsets
 *
 * Moves that a knight can make relative to the current position.
 * For example,
 * x += MOVES_X[0]; y += MOVES_Y[0]
 * corresponds to one of the eight moves that a knight can make, where `x` and
 * `y` represent the current position.
 */
#define MOVE_COUNT 8 /**< Number of moves that a knight can make */
const size_t MOVES[MOVE_COUNT][2] = {
    {2, 1},
    {1, 2},
    {-1, 2},
    {-2, 1},
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1}};

/**
 * @brief retruns 1 of move is possible
 *
 * @param move_id
 * @param x
 * @param y
 * @param visited
 * @return int
 */
int move_is_possible(size_t move_id, size_t x, size_t y, board_t chessboard)
{
  x += MOVES[move_id][0];
  y += MOVES[move_id][1];

  // is move within board
  if (x < 0)
    return 0;
  if (x > SIZE)
    return 0;
  if (y < 0)
    return 0;
  if (y > SIZE)
    return 0;

  // is spot already visited
  if (chessboard[x][y])
    return 0;

  return 1;
}

void greedy_tour_from_each_square()
{
  for (size_t start_x = 0; start_x < SIZE; ++start_x)
  {
    for (size_t start_y = 0; start_y < SIZE; ++start_y)
    {
      //printf_s("Starting from (%zu, %zu)\n", start_x, start_y);
      unsigned int count = tour_greedy(start_x, start_y);
      printf_s("%u ", count);
    }
    printf_s("\n");
  }
}

unsigned int tour_greedy(size_t start_x, size_t start_y)
{
  board_t chessboard = {0};
  chessboard[start_x][start_y] = 1;

  int pos_x = start_x;
  int pos_y = start_y;
  unsigned int count = 0;
start:
  for (size_t move_id = 0; move_id < MOVE_COUNT; ++move_id)
  {
    if (move_is_possible(move_id, pos_x, pos_y, chessboard))
    {
      count++;
      chessboard[pos_x][pos_y] = VISITED;
      pos_x += MOVES[move_id][0];
      pos_y += MOVES[move_id][1];
      goto start;
    }
  }

  return count;
}



