# 0x16. C - Simple Shell

------------------------
## Description

This Projects mimics a shell program that takes certain commands from the keyboard to the operating system(OS) for execution

------------------------
#### Compilations

- All files would be compiled using: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

#### Testing
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2

-----------------------
### Authors &copy;

- Abdulrahaman Kalli Mustapha -- (https://www.github.com/K-Musty) | (https://twitter.com/KMusty_) @twitter
- Muhamed Adam -- (https://www.github.com/Adamzella) 
