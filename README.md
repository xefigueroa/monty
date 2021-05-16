# Monty - Monty bytecode file interpreter.


## Description
The goal of this project is to create an interpreter for Monty ByteCodes files.

## Requirements
### General

   * Allowed editors: `vi`, `vim`, `emacs`
   * All your files will be compiled on Ubuntu 14.04 LTS
   * Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` `and` `-pedantic`
   * All your files should end with a new line
   * A `README.md` file, at the root of the folder of the project is mandatory
   * Your code should use the `Betty` style. It will be checked using betty-style.pl and betty-doc.pl
   * You allowed to use a maximum of one global variable
   * No more than 5 functions per file
   * You are allowed to use the C standard library
   * The prototypes of all your functions should be included in your header file called `monty.h`
   * Don’t forget to push your header file
   * All your header files should be include guarded
   * You are expected to do the tasks in the order shown in the project

### The Monty program

   * Usage: `monty file`
        * where `file` is the path to the file containing Monty byte code
   * If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
   * If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
        * where `<file>` is the name of the file
   * If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
        * where is the line number where the instruction appears.
        * Line numbers always start at 1
   * The monty program runs the bytecodes line by line and stop if either:
        * it executed properly every line of the file
        * it finds an error in the file
        * an error occured
    * If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
   * You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)


## Formatting and Examples


---

---

---



## File List

| File Name | Description |
| --- | --- |
| README.md | Provides details regarding functionality and creation of a monty bytecode interpreter (present file) |
| monty.h | Header file containing libraries, prototypes and structures pertaining monty interpreter. |
| montySource.c | Main file that runs the monty interpreter program.  |
| checkbuffer.c |  |
| linkFun.c |  |
| getopfun.c | |
| auxFun.c | |
| moreAuxFun.c |  |
| calculate.c | File containing the add, sub, div, mul and mod opcode functions. |
| text.m | Test file used to verify test cases. |
| AUTHORS | File containing AUTHORS information. |

## Compilation
All files where compiled on Ubuntu 14.04 LTS.

* Programs and functions were compiled with:
```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
* Any output must be printed on stdout
* Any error message must be printed on stderr

## Monty Opcodes

* **push**
  * Usage: `push <int>`
  * Pushes an element to the stack.
  * The parameter `<int>` must be an integer.

* **pall**
  * Prints all values in the stack/queue, starting from the top.

* **pint**
  * Prints the top value of the stack/queue.

* **pop**
  * Removes the top element of the stack/queue.

* **swap**
  * Swaps the top two elements of the stack/queue.

* **nop**
  * Does not do anything.

* **add**
  * Adds the top two elements of the stack/queue.
  * The result is stored in the second element from the top and the top element is popped.

* **sub**
  * Subtracts the top element of the stack/queue from the second element from the top.
  * The result is stored in the second element from the top and the top element is removed.

* **mul**
  * Multiplies the top two eleents of the stack/queue.
  * The result is stored in the second element from the top and the top element is removed.

* **div**
  * Divides the second element from the top of the stack/queue by the top element.
  * The result is stored in the second element from the top and the top element is removed.

* **mod**
  * Computes the modulus of the second element from the top of the stack/queue divided by the top element.
  * The result is stored in the second element from the top and the top element is removed.


* Opcodes preceeded by a `#` are treated as comments and the corresponding line is ignored.

* Lines can be empty and can contain any number of spaces before or after an opcode and its argument (only the first opcode and/or argument is taken into account).


## Styling
All files have been verified with Betty Style format.

## Authors
* **Kevin Ramos Lozano** | https://github.com/xefigueroa | 2361@holbertonschool.com
* **Xavier Figueroa Muniz** | https://github.com/KevinTMO | 2377@holbertonschool.com
m
