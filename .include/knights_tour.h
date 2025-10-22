#include <stddef.h>
#include <time.h>

#define SIZE 8       /**< Board size. */
#define VISITED 1    /**< Been there */
#define MOVE_COUNT 8 /**< Number of moves that a knight can make */
#define DEPTH 8      /**< Depth of recursion. */


typedef unsigned int board_t[SIZE][SIZE];

/** Determines whether a move is possible from a starting position.
 *
 * @param move_id ID of one of the 8 moves that the knight can to make [0, 7]
 * @param x Current horizontal position
 * @param y Current vertical position
 * @param visited A two-dimensional array that represents the squares.
 * If a value is positive, then the corresponding field was visited before.
 * @return True if the move is possible, else false.
 */
int Move_is_possible(size_t move_id, size_t x, size_t y, board_t chessboard);

/**
 * @brief Determines how many moves are possible from a starting position.

 *
 * @param start_x
 * @param start_y
 * @return int
 */
int Possible_moves(size_t x, size_t y, board_t chessboard);

/** Attempts a tour by picking the first possible move.
 *
 * @param x Horizontal starting position on the board
 * @param y Vertical starting position on the board
 * @return The number of visited squares
 * @note An array is created for the attempt
 */
unsigned int Tour_first(size_t x, size_t y);


/**
 * @brief return the number of possible moves from this location
 * 
 * @param x x start position
 * @param y y start position
 * @param chessboard the current chessboard 
 * @param depth how deep to go in the steps
 * @note a depth is given to prevent infinite loops
 * @return int, the number of possible moves
 */
int Possible_moves_recursive(size_t x, size_t y, board_t chessboard, size_t depth);

/**
 * @brief knights tour with random choices
 *
 * @param x x start position
 * @param y y start position
 * @return The number of visited squares as an unsigned int
 */
unsigned int Tour_random(size_t x, size_t y);

/**
 * @brief runs the warnsdorff tour
 *
 * @param x x start position
 * @param y y start position
 * @return The number of visited squares as an unsigned int
 */
unsigned int Tour_warnsdorff(size_t x, size_t y);

/**
 * @brief Attempts tours beginning from each square available on the board
 * with the greedy algorithm
 *
 * @param x x start position
 * @param y y start position
 * @return The number of visited squares as an unsigned int
 */
unsigned int Tour_brute_force(size_t x, size_t y);

/**
 * @brief Attempts tours beginning from each square available on the board
 * and annotates the number of visited squares like this:
 *
 * 15  8 15 15
 * 10  6  4 15
 *  8 10 14 14
 * 14 14 14 11
 *
 * @param Tour passes what tour funtion to use, First, Random, Warnsdorff, Recursive
 */
void Tour_from_each_square(unsigned int (*Tour)(size_t, size_t));

// https://stackoverflow.com/questions/6127503/shuffle-array-in-c
void Shuffle(int *array, size_t n);
