#include <stdio.h>
#include <stdarg.h>

#define BUFF_SIZE 1024 

/**
 * _printf - Simplified printf function.
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int char_count = 0; 
    char buffer[BUFF_SIZE]; 
    int buff_ind = 0; 

    while (*format)
    {
        if (*format != '%')
        {
            buffer[buff_ind++] = *format;

            if (buff_ind == BUFF_SIZE)
            {
                write(1, buffer, buff_ind);
                char_count += buff_ind;
                buff_ind = 0;
            }
            else
            {
                char_count++;
            }
        }
        else
        {
            format++;

            if (*format == 'c')
            {
                char c = va_arg(args, int);
                buffer[buff_ind++] = c;
                char_count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    buffer[buff_ind++] = *str;
                    char_count++;
                    str++;
                    if (buff_ind == BUFF_SIZE)
                    {
                        write(1, buffer, buff_ind);
                        buff_ind = 0;
                    }
                }
            }

            format++;
        }
    }

    if (buff_ind > 0)
    {
        write(1, buffer, buff_ind);
        char_count += buff_ind;
    }

    va_end(args);
    return char_count;
}
