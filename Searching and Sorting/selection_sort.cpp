#include <iostream>
using namespace std;
// first do for just the 1st iteration:
//  void selectionSort(int input[], int n)
//  {
//      int min = input[0], minIndex = 0;
//      // finding Minimum in the array
//      for (int i = 0; i < n; i++)
//      {
//          if (min > input[i])
//          {
//              min = input[i];
//              minIndex = i;
//          }
//      }
//      // swapping
//      int temp = input[0];
//      input[0] = min;
//      input[minIndex] = temp;
//  }

void selectionSort(int input[], int n)
{
    for (int j = 0; j < n; j++)
    {
        int min = input[j], minIndex = j;

        for (int i = j + 1; i < n; i++)
        {
            if (input[i] < min)
            {
                min = input[i];
                minIndex = i;
            }
        }

        // swapping
        int temp = input[j];
        input[j] = min;
        input[minIndex] = temp;
    }
}

int main()
{
    int input[] = {33, 1, 6, 9, 2, 8};
    selectionSort(input, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}