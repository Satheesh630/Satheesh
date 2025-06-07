#include <stdio.h>
#include <stdarg.h>

// User-defined printf function
void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);  // Initialize the va_list to handle variable arguments

    vprintf(format, args);   // Use vprintf to handle variable arguments

    va_end(args);            // Clean up the va_list when done
}

int main() {
    my_printf("Hello, World!\n");
    my_printf("Integer: %d, Float: %.2f, String: %s\n", 42, 3.14, "Hello");
    
    return 0;
}

