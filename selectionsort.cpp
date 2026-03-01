
#include <iostream>
#include <raylib.h>
#include <utility>
#include <algorithm>
#include <vector>


int main()
{
  
    const int width = 1200;
    const int height = 800;
    InitWindow(width, height, "selecton sort");
    std::vector<int> values(100);
    SetTargetFPS(165);
    for (int i = 0; i <100; i++)
    {
        values[i] = GetRandomValue(50, 600);
        
    }
    
   

   
    int i = 0;
    int j = 1;
    int min_index = 0;
    bool sorted = false;
    while (WindowShouldClose() == false)
    {
        if (!sorted)
        {
            if (values[j] < values[min_index])
            {
                min_index = j;
            }
            j++;

            if (j >= 100)
            {
                std::swap(values[i], values[min_index]);

                i++;
                min_index = i;
                j = i + 1;
            }


            if (i > 99)
            {
                sorted = true;
            }
        }








        BeginDrawing();
        ClearBackground(BLACK);
        for (int k = 0; k < 100; k++)
        {
            Color color = WHITE;
            if (k == min_index)
            {
                color = RED;
            }
            else if (k == j)
            {
                color = GREEN;
            }
            else if (k < i)
            {
                color = DARKGRAY;

            }
            DrawRectangle(12 * k, 800 - values[k], 10, values[k], color);
      }
        
        EndDrawing();
    }
    
}
