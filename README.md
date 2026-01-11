# Tic Tac Toe Game – C++

A **console-based two-player Tic Tac Toe game** implemented in **C++**, featuring turn-based gameplay, input validation, win detection, draw handling, and replay support.

---

## Overview
This project implements the classic Tic Tac Toe game for two human players in a terminal environment.  
Players enter positions using numeric input (1–9), with the game dynamically updating the board, validating moves, and evaluating game outcomes after each turn.

The program supports continuous gameplay through a replay mechanism without restarting the application.

---

## Core Features
- Two-player turn-based gameplay
- Dynamic console-rendered board
- Numeric position-based input (1–9)
- Input validation for invalid and occupied cells
- Win detection (rows, columns, diagonals)
- Draw detection
- Replay option after each match
- Automatic board reset between games

---

## Technology Stack
- **Language:** C++
- **Standard Library:** `<iostream>`, `<string>`
- **Compiler:** g++ (or any C++ compatible compiler)
- **Programming Style:** Procedural

---

## Game Mechanics
- The game board is represented using a 3×3 character array
- Players are assigned tokens:
  - Player 1 → `x`
  - Player 2 → `0`
- Turns alternate automatically after each valid move
- The game checks for:
  - Horizontal wins
  - Vertical wins
  - Diagonal wins
- A draw is declared when all cells are filled without a winner

---
│── .gitignore


## Project Structure
