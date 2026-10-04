# sorting-algorithim-visualiser-
Animated quick sort visualiser in C++ using SplashKit, showing each swap as a live bar chart.
[program.cpp](https://github.com/user-attachments/files/33026515/program.cpp)
#include "splashkit.h"
#include "splashkit-arrays.h"
#include "utiliteis.h"


int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
int bar_wiedth;
int bar_height;
const double MAX_VALUE = 100;



void visualise_array(dynamic_array<int> data)
{
    int size = data.length();
    
    
    clear_screen(COLOR_WHITE);
    for (int i = 0; i < size; i++)
    {
        bar_height = data[i] / MAX_VALUE * SCREEN_HEIGHT;
        bar_wiedth = SCREEN_WIDTH / size;
        fill_rectangle(COLOR_RED, i*bar_wiedth , SCREEN_HEIGHT - bar_height, bar_wiedth, bar_height);
        draw_rectangle(COLOR_BLACK, i*bar_wiedth , SCREEN_HEIGHT - bar_height, bar_wiedth, bar_height);
    }
    refresh_screen(60);
    
}

int partition(dynamic_array<int> &data, int low, int high)
{
    int pivot = data[high];
    int position = low -1;
    for (int i = low; i < high; i++)
    {
        if (data[i] <= pivot)
        {
            position++;
            swap(data[i], data[position]);
            process_events();
            visualise_array(data);
            delay(50);
            
        }
        
    }
    swap(data[high],data[position+1]);
    process_events();
    visualise_array(data);
    delay(50);

    return position + 1;

}
void quick_sort(dynamic_array<int> &data, int low, int high)
{
    if (low < high)
    {
        int pivot_pos = partition(data, low, high);
        
        quick_sort(data,low , pivot_pos -1 );
        quick_sort(data, pivot_pos +1, high);
        

    }
    

}

int main()
{
    int data_size = read_integer("How big is your list of data: ");

    dynamic_array<int> data;
    for (int i = 0; i < data_size ; i++)
    {
        data.add(read_integer("Enter a number: "));
    }
     
    write(data_size);
    open_window("Quick sort", SCREEN_WIDTH, SCREEN_HEIGHT );
    quick_sort(data, 0, data.length() - 1);
    while(!quit_requested())
    {
        process_events();
        visualise_array(data);
        
    }
    

}
