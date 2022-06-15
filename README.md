# 0x16. C - Simple Shell

## Background Context
A simple UNIX command interpreter.

![](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)
> ^ “The Gates of Shell”, by [Spencer Cheng](https://alx-intranet.hbtn.io/rltoken/AtYRSM03vJDrko9xHodxFQ), featuring [Julien Barbier](https://alx-intranet.hbtn.io/rltoken/-ezXgcyfhc8qU1DeUInLUA)

## Learning Objectives
*At the end of this project, we are expected to be able to explain to anyone, without the help of Google:*

### General
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?


# Turf-$

## Synopsis
This is a simple implementation of a UNIX command line interpreter for the ALX certification programme.

## Description
Turf-$ can interpret and execute command line arguments read from the standard input. It reads line by line from a file or the terminal line. It then interprets the lines and executes it if the line is a valid command.

## Usage
All the files are to be compiled on an Ubuntu 14.04 LTS machine with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

Once compiled, to start the program, run:
```./hsh```

To exit the program, run:
```Turf-$ exit```

The Turf-$ shell supports most shell commands, such as ```cat```, ```pwd```, ```ls -la``` and more.  
