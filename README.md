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

## Built-Ins
The following built-ins are supported by the Turf-$ shell:

+ ```env``` - Print the current environment
+ ```setenv VARIABLE VALUE``` - Initialize  a new environment VARIABLE  with VALUE, or modify an existing VARIABLE with VALUE  
+ ```unsetenv VARIABLE``` - Remove an environment VARIABLE

## Return Value
Turf-$ shell will exit with status 0 unless status is specified with syntax ```exit VALUE```

## List of functions.

| Function Name | Description |
|---------------- | -----------|
|[parse_line](https://github.com/stvngrcia/simple_shell/blob/master/parsing_functions.c)    | Parses the command line looking for commands and arguments.|
|[create_Child](https://github.com/stvngrcia/simple_shell/blob/master/parsing_functions.c) | Forks the current process in order to execute another program.|
|[tokenize](https://github.com/stvngrcia/simple_shell/blob/master/parsing_functions.c) | Separates a string into an array of tokens based on a delimiter passed to the function. |
|[count_token](https://github.com/stvngrcia/simple_shell/blob/master/parsing_functions.c) | Counts how many tokens are on a given string that is separated by a delimiter. |
|[find_path](https://github.com/stvngrcia/simple_shell/blob/master/find_path.c)|Looks through the environmental variables until it finds the PATH variable, It then returns the index of its position.|
|[tokenize_path](https://github.com/stvngrcia/simple_shell/blob/master/find_path.c) | Separates the PATH variable into separate strings each containing a directory in the PATH. |
|[search_directories](https://github.com/stvngrcia/simple_shell/blob/master/find_path.c) | Look through directories stored in path_tokens for a specific file name which represents a command. |
|[build_path](https://github.com/stvngrcia/simple_shell/blob/master/find_path.c) | Combines two strings, one representing the path directory and the other representing the command file. |
|[_strcmp](https://github.com/stvngrcia/simple_shell/blob/master/hbtlib.c) | Compare two strings and if they match the function returns 0.|
|[_strdup](https://github.com/stvngrcia/simple_shell/blob/master/hbtlib.c) | Duplicates a string.|
|[print_str](https://github.com/stvngrcia/simple_shell/blob/master/hbtlib.c)| Prints a string character by character.|
|[cd_b](https://github.com/stvngrcia/simple_shell/blob/master/builtins.c) | Changes the current working directory to the parameter passed to the command cd. |
|[env_b](https://github.com/stvngrcia/simple_shell/blob/master/builtins.c) | Prints all environmental variables available in the current shell.
|[check_built_ins](https://github.com/stvngrcia/simple_shell/blob/master/builtins.c) | Checks if a command exist as a builtin function and then it returns a pointer to the right function.|
