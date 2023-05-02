# Get_Next_Line

A function that reads from a file descriptor, returning the next line on each call. Used in a loop to iterate on each line.

## How to use it

To use this function, first place a readable file of your own choosing in the directory you are currently in. Then, run the following command:
```
gcc get_next_line.c get_next_line_utils.c
```

This command will compile the source files into an executable program. Once the program is compiled, you can execute it by running the following command:
```
./a.out
```
Here, The program will read the file line by line, printing each line to the standard output. If there are no more lines to read, the program will exit.

## Implementation Details

The get_next_line function reads a file descriptor one buffer at a time, and returns the next line that it finds. The function uses dynamic memory allocation to manage the buffer and return the line to the calling function.(Bonus part)

The function is designed to be able to handle multiple file descriptors at once, and the program is designed to handle memory leaks and other issues that might arise during execution.
