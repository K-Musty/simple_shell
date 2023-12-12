#include <unistd.h>
#include <stdarg.h> // Include for variable arguments

#define STDOUT_FILENO 1 // File descriptor for standard output

void cool_putchar(char c) {
    write(STDOUT_FILENO, &c, 1);
}

void cool_puts(const char *str) {
    while (*str != '\0') {
        cool_putchar(*str++);
    }
}

void cool_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                int num = va_arg(args, int);
                // Convert integer to string before printing
                char buffer[20]; // Adjust buffer size as needed
                int length = sprintf(buffer, "%d", num);
                cool_puts(buffer);
            } else if (*format == 's') {
                char *str = va_arg(args, char *);
                cool_puts(str);
            } else {
                // Handle other format specifiers if needed
                // For simplicity, just print the '%'
                cool_putchar('%');
            }
        } else {
            cool_putchar(*format);
        }
        format++;
    }

    va_end(args);
}

