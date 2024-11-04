#include <iostream>
#include <stdexcept>
#include <type_traits>


void validate_format(const char* fmt) 
{
    // Validate the format string
    while (*fmt != '\0') 
    {
        if (*fmt == '%') 
        {
            fmt++;
            if (*fmt != 'd' && *fmt != 'f' && *fmt != 's') 
            {
                throw std::runtime_error("Error: Invalid format specifier: " + std::string(1, *fmt));
            }
        }
        fmt++;
    }
}

template<typename T, typename... Args>
void validate_format(const char* fmt, T value, Args... args) 
{
    // Validate the format string and arguments
    bool found_specifier = false;
    while (*fmt != '\0') 
    {
        if (*fmt == '%') 
        {
            found_specifier = true;
            fmt++;
            if (*fmt == 'd') 
            {
                if (!std::is_same_v<T, int>) 
                {
                    throw std::runtime_error("Error: Expected an integer for %d format specifier!\n");
                }
            } 
            else if (*fmt == 'f') 
            {
                if (!std::is_same_v<T, double>) 
                {
                    throw std::runtime_error("Error: Expected a float for %f format specifier!\n");
                }
            } 
            else if (*fmt == 's') 
            {
                if (!std::is_same_v<T, const char*>) 
                {
                    throw std::runtime_error("Error: Expected a string for %s format specifier!\n");
                }
            } 
            else 
            {
                throw std::runtime_error(std::string("Error: Invalid format specifier: ") + *fmt);
            }
            validate_format(fmt + 1, args...);
            return;
        }
        fmt++;
    }
    if (!found_specifier || sizeof...(args) > 0) 
    {
        throw std::runtime_error("Too many arguments");
    }
}

void print_arg(const char* fmt) 
{
    // Print the arguments based on the format string
    while (*fmt != '\0') 
    {
        if (*fmt == '%') 
        {
            fmt++;
            throw std::runtime_error("Error: Missing argument for format specifier: " + std::string(1, *fmt));
        }
        std::cout << *fmt;
        fmt++;
    }
}

template<typename T, typename... Args>
void print_arg(const char* fmt, T value, Args... args) 
{
    // Print the arguments based on the format string
    while (*fmt != '\0') 
    {
        if (*fmt == '%') 
        {
            fmt++;
            if (*fmt == 'd') 
                std::cout << value;
            else if (*fmt == 'f') 
                std::cout << value;
            else if (*fmt == 's') 
                std::cout << value;
            print_arg(fmt + 1, args...);
            return;
        } 
        else 
            std::cout << *fmt;
        fmt++;
    }
}

template<typename... Args>
void myprintf(const char* fmt, Args... args) 
{
    // Main function to validate the format string and arguments
    try 
    {
        validate_format(fmt, args...);
        print_arg(fmt, args...);
    } 
    catch (const std::runtime_error& e) 
    {
        std::cerr << e.what() << "\n";
    }
}

int main() {
    try 
    {
		myprintf("Hello from string only\n");
		myprintf("int value: %d\n", 123);
		myprintf("float value: %f\n", 1.23);	
		myprintf("const char *value: %s\n", "123456789");	
		myprintf("int value: %d, float value: %f, const char *value: %s\n", 123, 1.23, "123456789");

		std::cout << "Error cases:\n";
		myprintf("int value: %d\n", "123456789"); // Error
		myprintf("const char *value: %s\n", 123456789);	// Error
		myprintf("int value: %d\n", 12345, 6789); // Error
    } 
    catch (const std::runtime_error& e) 
    {
        std::cerr << e.what() << "\n";
    }

    return 0;
}