#include <ctype.h>
#include <stdio.h>
#include "knights_tour.h"
#include <stdlib.h>
#include <time.h>

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

int move_is_possible(size_t move_id, size_t x, size_t y, board_t chessboard)
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

void tour_from_each_square(size_t strategy)
{
  if (strategy == RANDOM)
    goto Random;

  for (size_t start_x = 0; start_x < SIZE; ++start_x)
  {
    for (size_t start_y = 0; start_y < SIZE; ++start_y)
    {
      // printf_s("Starting from (%zu, %zu)\n", start_x, start_y);
      unsigned int count = tour_first(start_x, start_y);
      printf_s("%2u ", count);
    }
    printf_s("\n");
  }
  return;

Random:
  for (size_t start_y = 0; start_y < SIZE; ++start_y)
  {
    for (size_t start_x = 0; start_x < SIZE; ++start_x)
    {
      // printf_s("Starting from (%zu, %zu)\n", start_x, start_y);
      unsigned int count = tour_random(start_x, start_y);
      printf_s("%2d ", count);
    }
    printf_s("\n");
  }
  return;
}

unsigned int tour_first(size_t start_x, size_t start_y)
{
  board_t chessboard = {0};
  chessboard[start_x][start_y] = 1;

  int pos_x = start_x;
  int pos_y = start_y;
  unsigned int count = 0;
start:
  // printf_s("\n\nmove %i : position -> %i, %i\n", count, pos_x, pos_y);
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

unsigned int tour_random(size_t start_x, size_t start_y)
{
  board_t chessboard = {0};
  chessboard[start_x][start_y] = 1;

  int pos_x = start_x;
  int pos_y = start_y;
  unsigned int count = 0;

  int move_ids[SIZE];
  for (int i = 0; i < SIZE; i++)
    move_ids[i] = i;

Start:
  shuffle(move_ids, SIZE);

  for (int i = 0; i < SIZE; i++)
  {
    size_t move_id = move_ids[i];
    if (move_is_possible(move_id, pos_x, pos_y, chessboard))
    {
      count++;
      chessboard[pos_x][pos_y] = VISITED;
      pos_x += MOVES[move_id][0];
      pos_y += MOVES[move_id][1];
      goto Start;
    }
  }

  return count;
}

// https://stackoverflow.com/questions/6127503/shuffle-array-in-c
void shuffle(int *array, size_t n)
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