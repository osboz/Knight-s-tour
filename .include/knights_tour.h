#include <stddef.h>
#include <time.h>

#define SIZE 8    /**< Board size. */
#define VISITED 1 /**< Been there */
#define GREEDY 0 /**< Value for greedy strat */
#define RANDOM 1 /**< Value for random strat */
#define RECURSIVE 2 /**< Value for recursive strat */

typedef unsigned int board_t[SIZE][SIZE];

/** Determines whether a move is possible from a starting position.
 *
 * @param move_id One of the 8 moves that the knight wants to make [0, 7]
 * @param x Current horizontal position
 * @param y Current vertical position
 * @param visited A two-dimensional array that represents the squares.
 * If a value is positive, then the corresponding field was visited before.
 * @return True if the move is possible, else false.
 */
int move_is_possible(size_t move_id, size_t x, size_t y, board_t visited);

/** Attempts a tour by picking the first accessible square.
 *
 * @param start_x Horizontal starting position on the board
 * @param start_y Vertical starting position on the board
 * @return The number of visited squares
 * @note An array is created for the attempt
 */
unsigned int tour_first(size_t start_x, size_t start_y);

/**
 * @brief knights tour with random choices
 *
 * @param start_x
 * @param start_y
 * @return unsigned int
 */
unsigned int tour_random(size_t start_x, size_t start_y);

/**
 * @brief Attempts tours beginning from each square available on the board
 * and annotates the number of visited squares like this:
 *
 * 15  8 15 15
 * 10  6  4 15
 *  8 10 14 14
 * 14 14 14 11
 *
 *
 * @param strategy 0 for greedy, 1 for random, 2 for recursive
 */
void tour_from_each_square(size_t strategy);

// https://stackoverflow.com/questions/6127503/shuffle-array-in-c
void shuffle(int *array, size_t n);

//**
 * @brief 
 * 
 * @param start_x 
 * @param start_y 
 * @return unsigned int 
 */
unsigned int recursive_tour(size_t start_x, size_t start_y);