*This project has been created as part of the 42 curriculum by szaarour.*

# ft_printf

## Description

The **ft_printf** project is a reimplementation of the standard C `printf` function.
The goal of this project is to understand how formatted output works internally in C,
by recreating the behavior of `printf` for a defined set of conversion specifiers.

This project focuses on:
- Variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
- Parsing and interpreting format strings
- Delegating format specifiers to the correct output handlers
- Accurately counting and returning the number of printed characters

---

## Algorithm & Design Choices

### High-level idea

The function processes the format string **character by character**:

1. Regular characters are printed directly
2. When a `%` is encountered:
   - The following character is interpreted as a format specifier
   - The variadic argument list is accessed using `va_arg`
3. The argument is passed to the appropriate output function
4. Each output function prints its content and returns the number of characters printed
5. `ft_printf` accumulates and returns the total character count

This design mirrors the behavior of the real `printf` while keeping responsibilities
clearly separated across files.

---

## Project Structure & File Roles

### `ft_printf.c`
The core function of the project.

- Parses the format string
- Detects `%` sequences
- Initializes and manages the `va_list`
- Delegates work to the conversion handler
- Returns the total number of characters printed

---

### `ft_convert.c`
Acts as a bridge between the format specifier and the output logic.

Responsibilities:
- Uses `va_arg` to retrieve the next argument
- Determines which output function to call based on the format specifier

Supported conversions:
- `%c` → character
- `%s` → string
- `%d` / `%i` → signed integer
- `%u` → unsigned integer
- `%x` / `%X` → hexadecimal
- `%p` → pointer
- `%%` → literal percent sign

This separation ensures clean and maintainable code.

---

### `ft_putanything/`
A directory containing custom output functions inspired by `libft`,
but redesigned specifically for `ft_printf`.

Key differences from `libft`:
- No file descriptor parameter
- Each function returns the number of characters printed
- Designed to integrate seamlessly with `ft_printf`

Includes:
- `ft_putchar.c`
- `ft_putstr.c`
- `ft_putnbr.c`
- `ft_putunbr.c`
- `ft_puthex.c`
- `ft_putptr.c`

---

### `ft_puthex.c`
Handles hexadecimal output.

- Supports lowercase (`%x`) and uppercase (`%X`)
- Uses recursion to print digits in the correct order
- Returns the number of characters printed

---

### `ft_putptr.c`
Handles pointer conversion (`%p`).

- Prints the `0x` prefix
- Converts addresses to hexadecimal
- Prints `(nil)` for `NULL` pointers (GNU libc behavior)
- Returns the total number of printed characters

---

### `ft_printf.h`
Header file containing:
- Function prototypes
- Required includes

---

## How Variadic Arguments Work Here
Varidadic functions can be created using the `<stdarg.h>` header file.

1. `ft_printf` initializes a `va_list`
2. Each `%` specifier triggers a call to the converter
3. The converter:
   - Uses `va_arg` to retrieve the next argument
   - Determines the correct output function
4. Each output function:
   - Prints its content
   - Returns the number of printed characters
5. All return values are returned by `ft_printf`

This mirrors the behavior of the real `printf`.

---

## Instructions

### Build the library:
```bash
make
```
### This outputs:
`ft_printf.a`
### Clean object (.o) files:
```bash
make clean
```
### Clean everything (objects + library):
```bash
make fclean
```
---

## How to Use ft_printf

### Include the Header:
```c
#include "ft_printf.h"
```
### Example `main.c`:
```c
#include "ft_printf.h"
#include <stdio.h>

int main()
{
 	int len;
 	int n;

 	len = ft_printf("Hello %s, your score is %d out of %i. Hex: %x, Char: %c, Pointer: %p, Percent: %%\n", "Alice", 95, 100, 255,'A', &len);
 	ft_printf("Total length printed: %d\n", len);

 	n = printf("Hello %s, your score is %d out of %i. Hex: %x, Char: %c, Pointer: %p, Percent: %%\n", "Alice", 95, 100, 255, 'A', &n);
 	printf("Total length printed: %d\n", n);

 	return (0);
}
```

---

## References
- man printf
- man stdarg
- https://en.cppreference.com/w/c/variadic.html
- https://www.tutorialspoint.com/cprogramming/c_variadic_functions.htm
- https://www.youtube.com/watch?v=Hb2m7htiKWM&t=60s

### AI Usage
AI was used as a teaching assistant.
It was used to:
- Answer my questions about variadic functions and how va_list works internally
- Clarify format parsing strategies
- Help reason about file organization and separation of concerns

---

**Author:** Serena Zaarour <br>
**Intra:** szaarour  
**Cohort:** 1.1  
**42 Campus:** Beirut  
**Milestone:** 1  

---
