*This project has been created as part of the 42 curriculum by hilyas.*

# Get Next Line

## Description
**Get Next Line** is a project at 42 that requires programming a function that returns a line read from a file descriptor.This project introduces static variables in C and focuses on memory management and file manipulation.

## Instructions

### Compilation
To compile the project, you must define the `BUFFER_SIZE` macro. You can use the following command (ensure you provide a `main.c`):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

### Execution
After compiling, run the executable with a file as an argument:

```bash
./a.out text.txt
```

### Algorithm
The get_next_line function relies on a static variable to store data between function calls.

Reading: The function reads from the file descriptor into a temporary buffer and appends it to the static variable. This repeats until a newline character is found or the end of the file is reached.

Extraction: Once a newline is found, the line (including the \n) is extracted and allocated to be returned.

Storage: The remaining characters after the newline are saved in the static variable for the next call. If the file ends, the memory is freed.

### Resources
Manuals: man 2 read, man 3 malloc, man 3 free.


### AI Usage:
 AI tools were used in this project for understanding the concepts (specifically static variables and file descriptors) and for testing the function's behavior against edge cases.