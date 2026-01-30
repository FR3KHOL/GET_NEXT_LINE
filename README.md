# **get_next_line - 42 Network** <div align="center">
<img src="get_next_line.png" alt="Get Next Line Banner" width="100%"/>
</div>

## [cite_start]**Overview** **Get Next Line** is a project at 42 that requires programming a function that returns a line read from a file descriptor[cite: 4]. [cite_start]This project introduces static variables in C [cite: 10] and focuses on memory management and file manipulation.

## **Features**

### **Mandatory Part**
- **Function Name:** `get_next_line`
- **Prototype:** `char *get_next_line(int fd);`
- **Behavior:** Reads a file descriptor line by line until the end of the file.
- [cite_start]**Return Value:** The line read (including the `\n` character), or `NULL` if there is nothing else to read or an error occurred.

### [cite_start]**Bonus Part** [cite: 73]
- [cite_start]**Multiple File Descriptors:** Can read from different file descriptors per call without losing the reading thread of each[cite: 78].
- [cite_start]**Single Static Variable:** The entire bonus logic is implemented using only **one** static variable.

## **Technical Requirements**

- [cite_start]**Language:** C (Norminette compliant)[cite: 14, 15].
- [cite_start]**External Functions Allowed:** `read`, `malloc`, `free`.
- [cite_start]**Forbidden:** `lseek`, global variables, and standard `libft` usage (helper functions must be included in utils)[cite: 68, 69, 70].
- [cite_start]**Buffer Size:** Must compile with a defined `BUFFER_SIZE` flag[cite: 52].

## **Usage**

### **1. Compilation**
To compile the project, you must define the `BUFFER_SIZE` macro and include a `main` function (not provided in the core files).

**Mandatory:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <your_main.c> get_next_line.c get_next_line_utils.c
```

### 2. Execution

After compiling, run the executable with a file as an argument (if your main supports it):

```bash
./a.out text.txt

```

### 3. Testing Buffer Sizes

The project relies on the `-D BUFFER_SIZE=n` flag. You should test with various buffer sizes (e.g., 1, 42, 9999, 10000000) to ensure the function behaves correctly regardless of how many bytes are read at once.

## Limitations & Undefined Behaviors

According to the subject guidelines:

* 
**Binary Files:** The behavior is undefined when reading binary files.


* 
**FD Changes:** The behavior is undefined if the file pointed to by the file descriptor changes since the last call while `read()` hasn't reached the end of the file.



## Project Structure

* 
`get_next_line.c`: Main logic for reading and processing lines.


* 
`get_next_line_utils.c`: Helper functions (re-implementation of necessary string manipulation tools).


* 
`get_next_line.h`: Header file containing prototypes and includes.