# Knight’s tour

You will implement two cryptosystems:
    [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher)
    [Vigenère cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
    

Draw a flowchart for this [problem](#problem).
> Flowchart : ![Flowchart](Crytography_flowchart.png)

Make code to solve the [problem](#problem)
> Da code : [code](.src/main.c)

Changes made to the problem
> Da [Changes](#Changes)

Explain where i used modularization
> [here|•◡•|](#Modularization)
---

# Problem 

Implement the cryptosystem in section Cryptography. 

## Requirements:
- Flowchart
- Has a command-line interface
- Use modularization as much as possible, i.e., header files, functions for repetitive code.
- What was your [modularization](#Modularization) approach to each part you have implemented, i.e., CLI, Caesar, Vigenere? 1-3 sentences per part are enough. Include this test in your README.
- For your header files you use include folder.
- Your header file is documented using Doxygen syntax.


## Caesar
You have to implement two functions:
```
> char *caesar_encrypt(char *plaintext);
> char *caesar_decrypt(char *ciphertext);
```
These functions work in-place, in other words, you don’t have to create a new string for the encrypted/decrypted text.

## Vigenère
Similar to Caesar, however every character in the plaintext can be shifted by a variable amount. The amount to shift is determined by the key of alphabetic characters, where A corresponds to 0, B 1, etc. There is a wrap-around if necessary like in Caesar.

Implement the functions:
```
> char *vigenere_encrypt(char *plaintext, char *key);
> char *vigenere_decrypt(char *ciphertext, char *key);
```
## Asumptions
You can assume that plaintext:
    is uppercase
    contains no spaces, numbers or punctuation

# Modularization
I made the function ***talCirkulærRundingMinMax()***, so i could easily get a int that fit in the alphabet mulitple times. 
caesar is a function that can en/decrypt text based on an int
Vigenère is a function that can en/decrypt text based on a char

# Changes
1. Made *vigenere_encrypt* and *vigenere_decrypt* into a single function with a parameter to change modes instead
2. Same for the Caesar functions

(knights-tour)=
# Knight's tour

:::{commons-figure} https://commons.wikimedia.org/wiki/File:Knight%27s_tour.svg
:name: knights-tour-open
:figwidth: 35%
:align: right
A possible knight's tour on a chessboard.
:::

:::{commons-figure} https://commons.wikimedia.org/wiki/File:Turk-knights-tour.svg
:name: knights-tour-closed
:figwidth: 35%
:align: right
A closed-loop solution performed [by the Turk](https://en.wikipedia.org/wiki/Mechanical_Turk) in 1780s. A closed loop solution implies that we can start from every square and find a solution.
:::


:::{wpd} Knight's tour
A sequence of moves of a knight on a chessboard such that the knight visits every square once.
:::

We will implement a program that tries to solve the Knight's tour problem. The problem can be solved with an open or closed loop like in {numref}`knights-tour-open` and {numref}`knights-tour-closed`, respectively. It does not matter which solution your program finds.

:::{activity} A shorter tour on a 4x4 board
:label: knights-tour-4x4
1. Draw a 4x4 board and write `1` to one field that you choose. Move the knight and write the incremented number to the new field. Play as long the knight can make moves. How many squares could you visit?
1. Try the tour by beginning on other squares. Do you think that beginning from a corner or middle square is better?
:::

:::{activity} Computational solution flowchart
:label: knights-tour-4x4
You tried to solve the problem manually in {numref}`knights-tour-4x4`. Draw a flowchart that describes your process.

Pay attention to when the process ends.
<!-- probably the students will think about a `move_is_possible` function-->
:::

Implement a program that begins on a square and makes the first move that is possible and continues moving in the same manner until it is not possible anymore. This is a *greedy algorithm*.

:::{wpd} Greedy algorithm
An algorithm that makes the locally optimal choice at each stage.
:::

Requirements:
1. Your documentation includes flowchart/s.
1. Your program outputs the maximum number of squares toured for each square as follows:

   ```text
   Greedy:
   36 37 43 49 36 35 48 42 
   54 43 35 36 42 48 35 34 
   36 29 54 42 34 35 41 47 
   42 28 35 28 54 41 33 34 
   45 35 41 27 26 27 46 40 
   40  8 44 44 40 26 33 32 
   10 54 46 54 55 31 39 54 
   42 37 35 55 36 32 35 32
   ```
1. Your program uses the following compile-time constants and functions.

   ```c
   #define SIZE 8       /**< Board size. */
   

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
   const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
   const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

   /** Determines whether a move is possible from a starting position.
    *
    * @param move_id One of the 8 moves that the knight wants to make [0, 7]
    * @param x Current horizontal position
    * @param y Current vertical position
    * @param visited A two-dimensional array that represents the squares. If a
    * value is positive, then the corresponding field was visited before.
    * @return True if the move is possible, else false.
    */
   bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited);
   
   /** Attempts a tour by picking the first accessible square.
    *
    * @param start_x Horizontal starting position on the board
    * @param start_y Vertical starting position on the board
    * @return The number of visited squares
    * @note An array is created for the attempt
    */
   unsigned int tour_greedy(size_t start_x, size_t start_y);
   
   /** Attempts tours beginning from each square available on the board
    * and annotates the number of visited squares like this:
    *
    * 15  8 15 15 
    * 10  6  4 15 
    *  8 10 14 14 
    * 14 14 14 11 
    */
   void greedy_tour_from_each_square();
   ```
1. Even `SIZE` is 8 as default, your program should also work with `SIZE`s other than 8.
1. Organize your project into the files `knights_tour.{h,c}` and `main.c`.
1. Optional: Implement a non-greedy approach that prioritizes squares that are more difficult to access compared to others. For example the following table shows for each destination square, from how many departure squares the destination square is accessible on a 8x8 board.

   ``` 
   2  3  4  4  4  4  3  2 
   3  4  6  6  6  6  4  3 
   4  6  8  8  8  8  6  4 
   4  6  8  8  8  8  6  4 
   4  6  8  8  8  8  6  4 
   4  6  8  8  8  8  6  4 
   3  4  6  6  6  6  4  3 
   2  3  4  4  4  4  3  2
   ```
   
:::{video} ../img/knights-tour-board-visualization-during-debugging.webm
:name: test
:figwidth: 35%
:align: right
:caption: Tour visualization using the variables window in debugger. The knight jumps first to [6][4] (value `1`) and then to `2` and `3`.
:::

::::{tip}
If you view the array that represents the tour in the debugger, then you can track where the knight goes after each breakpoint as shown in the video on the right.
::::