#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    int counter = 0, num, num_char;
    char current_char, c, *str, buffer[12];

    va_list list;
    va_start(list, format);

    while ((current_char = *format) != '\0')
    {
        if (current_char == '%')
        {
            format++;
            current_char = *format;

            if (current_char == '\0')
            {
                putchar('%');
                counter++;
                break;
            }

            if (current_char == 'c')
            {
                c = va_arg(list, int);
                putchar(c);
                counter++;
            }
            else if (current_char == 's')
            {
                str = va_arg(list, char *);
                while (*str != '\0')
                {
                    putchar(*str);
                    str++;
                    counter++;
                }
            }
            else if (current_char == 'd' || current_char == 'i')
            {
                num = va_arg(list, int);
                num_char = sprintf(buffer, "%d", num);
                printf("%s", buffer);
                counter += num_char;
            }

            else if (current_char == '%')
            {
                putchar('%');
                counter++;
            }
            else
            {
                putchar('%');
                putchar(current_char);
                counter += 2;
            }
        }
        else
        {
            putchar(current_char);
            counter++;
        }
        format++;
    }

    va_end(list);
    return counter;
}
