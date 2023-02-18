# LibFT - plain C standard library implementation

A library of useful C functions, created as a project for Hive Helsinki School 42.

## Table of Contents

-   [Introduction](#Introduction)
-   [Getting Started](#GettingStarted)
-   [Functions](#Functions)
-   [Building the Library](#BuildingtheLibrary)
-   [Usage](#Usage)
-   [Contributing](#Contributing)
-   [License](#License)

## Introduction 

`Libft` is a project that requires you to re-implement some standard C library functions, as well as create some additional functions that can be useful in future projects. By doing this project, you will learn more about how these functions work under the hood and how to write efficient, reusable code.

## Getting Started

To get started with this project, you will need to clone the repository onto your local machine:

```
git clone https://github.com/YOUR-USERNAME/libft.git

```

Once you have cloned the repository, you can start exploring the source code and building the library.

## Functions

The `libft` library includes several different types of functions, including:

-   Memory manipulation functions (`ft_memcpy`, `ft_memccpy`, `ft_memset`, `ft_memmove`, `ft_memchr`, `ft_memcmp`)
-   String manipulation functions (`ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strnstr`, `ft_strncmp`, `ft_strcmp`, `ft_strdup`)
-   Character manipulation functions (`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`)
-   Printing functions (`ft_printf`, `ft_fprintf`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`)
-	File reading functions (`get_next_line`)
-   List manipulation functions (`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`)

For a full list of functions and their descriptions, see the `libft.h` header file.

## Building the Library

To build the `libft` library, simply run the `make` command in the root directory of the repository:

```
make
``` 

This will compile all of the source code and create a `libft.a` file in the root directory of the repository.

## Usage

To use the `libft` library in your own projects, simply include the `libft.h` header file in your source code and link against the `libft.a` library.

For example, to use the `ft_strlen` function in your code, you would include the `libft.h` header file and call the function like this:

```
#include "libft.h"

int main()
{
    char *str = "Hello, world!";
    int len = ft_strlen(str);
    ft_printf("Length of string: %d\n", len);
    return 0;
}
```

## Contributing

If you find a bug or would like to contribute to this project, please feel free to submit a pull request or open an issue on the GitHub repository.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more information.