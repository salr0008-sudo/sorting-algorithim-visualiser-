#include "splashkit.h"

string read_string(string prompt)
{
    write(prompt);
    return read_line();
}

int read_integer(string prompt)
{
    string line;
    
    line = read_string(prompt);
    while (!is_integer(line))
    {
        write_line("Write a valid number");
        line = read_string(prompt);
    }
    return to_integer(line);
}

double read_double(string prompt)
{
    string line;
    
    line = read_string(prompt);
    while (!is_double(line))
    {
        write_line("Write a valid number");
        line = read_string(prompt);
    }
    return to_double(line);
}

int read_integer    (string prompt, int min, int max)
{
    int input;
    input = read_integer(prompt);
    while( input < min || input > max)
    {
        input = read_integer("Enter a value between "+ to_string(min) + " and "+ to_string(max) +": ");
    }
    return input;
}

bool read_boolean(string prompt, string usertrue, string userfalse)
{
    string input;

    while (true)
    {
        input = to_lowercase(read_string(prompt));

        if (input == to_lowercase(usertrue))
        {
            return true;
        }
        if (input == to_lowercase(userfalse))
        {
            return false;
        }
    write_line("please enter "+ usertrue +" or "+ userfalse);
    }
}
