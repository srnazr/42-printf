# ft_printf

**Author:** Serena Zaarour  
**Cohort:** 1.1  
**42 Campus:** Beirut  
**Milestone:** 1  

---

## Project Overview

`ft_printf` is a reimplementation of the standard C `printf` function.  
The goal of this project is to understand:

- Variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
- Format parsing
- Basically, how `printf` works behind the scenes!

This implementation follows the 42 subject requirements (norminette and format specifiers) and recreates the behavior of `printf` for the supported conversion specifiers.

---

## Project Structure & File Roles

### `ft_printf.c`
The core function of the project.

- Parses the format string character by character
- Detects `%` sequences
- Initializes and manages the variadic argument list
- Delegates conversions to the appropriate handler
- Returns the total number of printed characters

---

### `ft_convert.c`
- Uses `va_list` to access variable arguments
- Advances arguments using `va_arg`
- Passes each argument to the correct conversion handler
- Acts like a bridge between the format specifier and output functions

Responsible for **deciding which function to call** based on the format specifier.

For example:
- `%c` → character printer
- `%s` → string printer
- `%d` / `%i` → integer printer
- `%u` → unsigned integer printer
- `%x` / `%X` → hexadecimal printer
- `%p` → pointer printer
- `%%` → literal `%`

This file ensures separation of concerns by keeping format detection independent from output logic.

---

### `ft_putanything`
A folder containing custom recreation of the needed output functions inspired by `libft`, **without file descriptors**.

Key differences from `libft`:
- All functions return the **number of characters printed**
- No `fd` parameter
- Designed specifically for `ft_printf`

Includes:
- `ft_putchar.c`
- `ft_putstr.c`
- `ft_putnbr.c`
- `ft_putunbr.c` (for unsigned numbers)
- `ft_puthex.c` (for `%x` / `%X`)
- `ft_putptr.c` (for `%p`, with `0x` prefix)

This re-implementation allows character counting and cleaner integration with `ft_printf`.

---

### `ft_puthex.c`
Handles hexadecimal output.

- Supports lowercase (`%x`) and uppercase (`%X`)
- Uses recursion to print digits in correct order
- Returns the number of characters printed

---

### `ft_putptr.c`
Handles pointer conversion (`%p`).

- Prints the `0x` prefix
- Converts the address to hexadecimal
- Correctly handles `NULL` pointers
- Returns the total printed length

---

### `ft_printf.h`
Header file containing:
- Function prototypes
- Required includes

---

## How Variadic Arguments Work Here

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

## Makefile & Build System

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
```C
#include "ft_printf.h"
```
### Example Usage:
```C
ft_printf("Hello %s, number: %d, pointer: %p\n", "world", 42, &x);
```
---

#### This project was completed as part of 42 Beirut, Cohort 1.1, Milestone 1.