
# Monty Interpreter
![monty image](montypng.png)

Monty is an interpreter for Monty Bytecode files. Monty is a stack-based language that uses a stack to perform operations.

## Table of Contents
- [Introduction](#introduction)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [File Format](#file-format)
- [Supported Opcodes](#supported-opcodes)
- [Examples](#examples)
- [Contact](#contact)


## Introduction

Monty is a simple stack-based programming language. The Monty interpreter reads Monty Bytecode files and executes the specified operations. It supports various stack manipulation and arithmetic operations.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/Isaac-Ndirangu-Muturi-749/monty.git
   ```

2. Navigate to the project directory:

   ```bash
   cd monty
   ```

3. Compile the Monty interpreter:

   ```bash
   make
   ```

This will generate the `monty` executable.

## Usage

Run the Monty interpreter with a Monty Bytecode file:

```bash
./monty path/to/your/file.m
```

## File Format

A Monty Bytecode file is a text file containing Monty commands. Each command is written on a new line. 

## Supported Opcodes

- `push`: Pushes an element onto the stack.
- `pop`: Removes the top element of the stack.
- `pall`: Prints all the values on the stack.
- `pint`: Prints the value at the top of the stack.
- `swap`: Swaps the top two elements of the stack.
- `add`: Adds the top two elements of the stack.
- `nop`: No operation, does nothing.

## Examples

### Example 1

```text
push 5
push 10
add
pall
```

Output:

```text
15
```

### Example 2

```text
push 1
push 2
swap
pall
```

Output:

```text
2
1
```

## Contact
Follow me on Twitter 🐦, connect with me on LinkedIn 🔗, and check out my GitHub 🐙. You won't be disappointed!

👉 Twitter: https://twitter.com/NdiranguMuturi1  
👉 LinkedIn: https://www.linkedin.com/in/isaac-muturi-3b6b2b237  
👉 GitHub: https://github.com/Isaac-Ndirangu-Muturi-749   