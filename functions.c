#include "main.h"

/* TO PRINT CHAR */

/**
 * print_char - prints a char
 * @types: list of arguments
 * va_list - initialises variables usings in va_args
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specification
 * Return: number of chars printed
 */

int print_char(va_list types, char buffer[], int flags, int width,
               int precision, int size)
{
    char c = va_arg(types, int);

    return (handle_write_char(c, buffer, flags, width, precision, size));
}

/* TO PRINT A STRING */
/**
 * print_string - prints a string
 * @types: list a of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specification
 * Return: number of chars printed
 */

int print_string(va_list types, char buffer[], int flags, int width,
                 int precision, int size)
{
    int length = 0, i;
    char *str = va_arg(types, char *);

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    if (str == NULL)
    {
        str = "null";
        if (precision >= 6)
            str = "     ";
    }
    while (str[length] != '\0')
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    if (width > length)
    {
        if (flags & F_MINUS)
        {
            write(1, &str[0], length);
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            return (width);
        }
        else
        {
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return (width);
        }
    }

    return (write(1, str, length));
}

/* TO PRINT PERCENT SIGN (%) */
/**
 * print_percent - prints percent sign
 * @types: list a of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specification
 * Return: number of chars printed
 */

int print_percent(va_list types, char buffer[], int flags, int width int precision, int size)
{
    UNUSED(types);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return (write(1, "%%", 1));
}