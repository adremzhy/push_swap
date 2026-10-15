_This project has been created as part of the 42 curriculum by adremzhy._

# libft

## Description

`libft` is a C standard library that we build by ourselves and it is the very first project of the core curriculum. The main goal is to reproduce standard functions from standard C library. In order to build strong foundation and to truly understand how it works under the hood, we reinvent or reproduce the behavior of those functions.
During this project we manipulate with strings, numbers and pointers, and also we use linked lists as per it is no longer a bonus part.

These library can be used across other C project as tested personal functions.
## Instructions

### Compilation

```
make            # builds libft.a (mandatory part)
make all        # same as make
make clean      # removes object files
make fclean     # removes object files and libft.a
make re         # fclean + full rebuild
```

### Usage

Link the library to your project:

```
cc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
```

Include the header in your source files:

```
#include "libft.h"
```

## Library Overview

The library is split into three parts, following the 42 subject structure.

### Part 1 — Libc function re-implementations

|Function|Purpose|
|---|---|
|`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`|Character classification|
|`ft_toupper`, `ft_tolower`|Character case conversion|
|`ft_strlen`|String length|
|`ft_memset`, `ft_bzero`|Memory initialization|
|`ft_memcpy`, `ft_memmove`|Memory copying|
|`ft_strlcpy`, `ft_strlcat`|Safe string copy/concatenation|
|`ft_strchr`, `ft_strrchr`|Character search in a string|
|`ft_strncmp`, `ft_memcmp`|Comparison|
|`ft_memchr`, `ft_strnstr`|Search within bounded memory/strings|
|`ft_atoi`|String-to-integer conversion|
|`ft_calloc`, `ft_strdup`|Allocation helpers|

### Part 2 — Additional functions

|Function|Purpose|
|---|---|
|`ft_substr`|Allocates and returns a substring|
|`ft_strjoin`|Concatenates two strings into a newly allocated one|
|`ft_strtrim`|Trims leading/trailing characters from a set|
|`ft_split`|Splits a string into an array of strings by a delimiter|
|`ft_itoa`|Converts an integer to a newly allocated string|
|`ft_strmapi`|Applies a function to each character, building a new string|
|`ft_striteri`|Applies a function to each character in place, passing its address|
|`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`|Output helpers writing to a given file descriptor|

To maintain 25 lines per function, some of the files contain static functions to reduce the number of lines in main functions.

### Linked lists

Implements a singly linked list (`t_list`) and its operations:

|Function|Purpose|
|---|---|
|`ft_lstnew`|Creates a new list node|
|`ft_lstadd_front`, `ft_lstadd_back`|Insertion at the front/back|
|`ft_lstsize`, `ft_lstlast`|List traversal helpers|
|`ft_lstdelone`, `ft_lstclear`|Node/list deletion with a custom destructor|
|`ft_lstiter`|Applies a function to each node's content|
|`ft_lstmap`|Builds a new list by applying a function to each node's content, with cleanup on allocation failure|

## Resources

- The C Programming Language, Kernighan & Ritchie — reference for C fundamentals
- cppreference — C standard library — behavior reference for the original functions being reimplemented
- Linux man pages  for the original libc functions being reimplemented
- 42 Norm documentation — coding standard enforced on the project

### How AI was used

Gemini was used mostly as a search tool for references in books.
No function was copy-pasted from any AI tool.
Also AI was used with this README file as a checker, for grammatical and syntax mistakes. 