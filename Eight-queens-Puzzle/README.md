<p align="center">
  <a href="https://syalux.com" target="_blank">
    <img src="../md/favicon.ico" width="80" alt="Project Logo">
  </a>
</p>

<p align="center">
  <a href="https://github.com/Al-rimi/Algorithm-design/releases">
    <img src="https://img.shields.io/github/v/release/Al-rimi/Algorithm-design" alt="Latest Stable Version">
  </a>
  <a href="https://github.com/Al-rimi/Algorithm-design/issues">
    <img src="https://img.shields.io/github/issues/Al-rimi/Algorithm-design" alt="Open Issues">
  </a>
  <a href="https://opensource.org/licenses/MIT">
    <img src="https://img.shields.io/badge/license-MIT-blue.svg" alt="License">
  </a>
</p>

# Eight Queens Puzzle

The **Eight Queens Puzzle** is a classical algorithm problem that involves placing `n` queens on an `n x n` chessboard such that no two queens threaten each other. This project provides a solution for the puzzle using a backtracking algorithm and supports a dynamic board size.

## Key Features

- **Backtracking Algorithm**: A recursive approach that efficiently solves the N-Queens problem.
- **Dynamic Input**: Allows users to input any size `n` for the chessboard (default: 8x8).
- **Formatted Output**: Displays all solutions in a clear and concise manner with the coordinates of the placed queens.
- **Color-enhanced Output**: The terminal output includes color formatting for better readability and presentation.
- **Developer Signature**: A personalized ASCII signature that displays the developer's name and ID in the terminal.

## Algorithm Specification

### Problem

The goal is to place `n` queens on an `n x n` chessboard so that no two queens are in the same row, column, or diagonal. The solution uses **backtracking** to explore all possible placements of queens.

### Steps of the Algorithm:

1. **Initialization**: Represent the chessboard using an array `q[]`, where `q[i]` holds the column position of the queen in row `i`.
2. **Backtracking**:
    - Start with the first row and attempt to place a queen in each column.
    - Use the `canPlace()` function to check if the queen is safe in the current position.
    - If safe, move to the next row. If not, try the next column.
    - Backtrack to the previous row when no safe position is found.
3. **Solution Detection**: When all queens are successfully placed, the solution is displayed.
4. **Termination**: The algorithm stops when all possible solutions are found.

### Functions:
- **`solveQueens(int n)`**: Solves the N-Queens problem using backtracking.
- **`canPlace(int i)`**: Checks if a queen can be placed in the current row without conflicts.
- **`displaySolution(int n)`**: Displays the current solution as a series of coordinates `(row, column)`.
- **`displaySignature()`**: Outputs a personalized ASCII signature with color formatting.

## Screenshot

Here’s a preview of the terminal output:

![Terminal screenshot](Screenshot.png)

## Learning Resources

- [Backtracking Algorithm](https://en.wikipedia.org/wiki/Backtracking)
- [N-Queens Problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle)

## Security Vulnerabilities

If you discover a security vulnerability, please email Abdullah Al Raimi at [abdullah@syalux.com](mailto:abdullah@syalux.com). All security vulnerabilities will be promptly addressed.

## License

This project is licensed under the [MIT license](../LICENSE).
