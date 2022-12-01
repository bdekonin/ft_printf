# ft_printf

This project is a re-writing of the standard C printf function, with all the same specifiers and flags. It is intended to be used to understand how variadic arguments work. 

## Specifiers 

The following specifiers are supported by this project: 
- `c`: Character
- `s`: String
- `p`: Pointer address
- `d`: Signed decimal integer
- `i`: Signed decimal integer
- `u`: Unsigned decimal integer
- `x`: Unsigned hexadecimal integer
- `X`: Unsigned hexadecimal integer (uppercase)
- `%`: A % followed by another % will write a single % to the stream

## Flags

The following flags are supported:
- `-`: Left-justify within the given field width
- `0`: Left-pads the number with zeroes (only when padding with zeroes is specified)
- `.*`: Precision
- `#`: Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero
- `+`: Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.

## Usage

The printf function can be used in the following way: 

`int printf(const char *format, ...);`

Where `format` is a string that contains one or more of the specifiers and flags mentioned above.

For more information on usage and examples, please consult the project documentation. 

Enjoy!
