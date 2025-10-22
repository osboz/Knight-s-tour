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
    if (Move_is_possible(i, x, y, chessboard))
      count++;

  return count;
}

int Possible_moves_recursive(size_t x, size_t y, board_t chessboard, size_t depth)
{
  if (depth <= 0)
    return 0;

  int max_count = 0;
  for (int i = 0; i < MOVE_COUNT; ++i)
  {
    if (!Move_is_possible(i, x, y, chessboard))
      continue;

    int new_x = x + MOVES[i][0];
    int new_y = y + MOVES[i][1];

    chessboard[new_x][new_y] = VISITED;
    int child_count = 1 + Possible_moves_recursive(new_x, new_y, chessboard, depth - 1);
    chessboard[new_x][new_y] = 0; /* backtrack */

    if (child_count > max_count)
      max_count = child_count;
  }
  return max_count;
}

void Tour_from_each_square(unsigned int (*Tour)(size_t, size_t))
{
  /* column labels */
  printf("    "); /* left margin for row labels */
  for (int col = 0; col < SIZE; ++col)
    printf("%2c ", 'A' + col);

  printf("\n    ");
  for (int col = 0; col < SIZE; ++col)
    printf("---");

  printf("\n");

  for (int y = 0; y < SIZE; ++y)
  {
    /* row label (1-based) */
    printf("%2d | ", y + 1);

    for (int x = 0; x < SIZE; ++x)
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
    if (!Move_is_possible(move_id, x, y, chessboard))
      continue;

    count++;
    x += MOVES[move_id][0];
    y += MOVES[move_id][1];
    chessboard[x][y] = VISITED;
    goto Start;
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
    if (!Move_is_possible(move_id, x, y, chessboard))
      continue;

    count++;
    chessboard[x][y] = VISITED;
    x += MOVES[move_id][0];
    y += MOVES[move_id][1];
    goto Start;
  }

  return count;
}

unsigned int Tour_brute_force(size_t x, size_t y)
{
  board_t chessboard = {0};
  chessboard[x][y] = VISITED;
  unsigned int count = 0;

Start:
  int best_move_id = -1;
  int best_score = -1; /* sentinel: lower than any possible score */

  for (int i = 0; i < MOVE_COUNT; ++i)
  {
    if (!Move_is_possible(i, x, y, chessboard))
      continue;

    int new_x = x + MOVES[i][0];
    int new_y = y + MOVES[i][1];

    /* copy board for simulation */
    board_t tempboard;
    for (int r = 0; r < SIZE; ++r)
      for (int c = 0; c < SIZE; ++c)
        tempboard[r][c] = chessboard[r][c];

    tempboard[new_x][new_y] = VISITED;
    int score = Possible_moves_recursive(new_x, new_y, tempboard, DEPTH - 1);

    if (score <= best_score)
      continue;

    best_score = score;
    best_move_id = i;
  }

  if (best_move_id == -1)
    return count; /* no legal moves */

  /* apply best move */
  x += MOVES[best_move_id][0];
  y += MOVES[best_move_id][1];
  ++count;
  chessboard[x][y] = count + VISITED;
  goto Start;
}

unsigned int Tour_warnsdorff(size_t x, size_t y)
{
  board_t chessboard = {0};
  chessboard[x][y] = VISITED;
  unsigned int count = 1;

  int move_ids[MOVE_COUNT];
  for (int i = 0; i < MOVE_COUNT; i++)
    move_ids[i] = i;

Start:
  Shuffle(move_ids, MOVE_COUNT);
  int best_move_id = -1;
  int best_score = INT_MAX;

  for (int i = 0; i < MOVE_COUNT; ++i)
  {
    if (!Move_is_possible(i, x, y, chessboard))
      continue;

    int score = Possible_moves(x + MOVES[i][0], y + MOVES[i][1], chessboard);

    if (score > best_score)
    {
      continue;
    }

    best_score = score;
    best_move_id = i;
  }

  if (best_move_id == -1)
  {
    // printf("\n");
    // for (int y = 0; y < SIZE; ++y)
    // {
    //   /* row label (1-based) */
    //   printf("%2d | ", y + 1);
    //   for (int x = 0; x < SIZE; ++x)
    //   {
    //     printf("%2u ", chessboard[x][y]);
    //   }
    //   printf("\n");
    // }
    // printf("\n");

    return count;
  }

  /* apply best move */
  x += MOVES[best_move_id][0];
  y += MOVES[best_move_id][1];
  ++count;
  chessboard[x][y] = count;
  goto Start;
}

// https://stackoverflow.com/questions/6127503/shuffle-array-in-c
void Shuffle(int *array, size_t n)
{
  if (n < 2)
    return;

  size_t i;
  for (i = 0; i < n - 1; i++)
  {
    size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
    int t = array[j];
    array[j] = array[i];
    array[i] = t;
  }
}
