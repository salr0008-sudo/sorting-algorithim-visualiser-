#include "splashkit.h"

string read_string(string prompt);

bool read_boolean(string prompt);

double read_double(string prompt);
double read_double(string prompt, double min, double max);

int read_integer(string prompt);
int read_integer(string prompt, int min, int max);
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}