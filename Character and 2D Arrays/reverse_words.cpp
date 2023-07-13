#include <iostream>
using namespace std;
// first reverse the whole string, then reverse the individual words.
int length(char input[])
{
    int count = 0;
    for (int x = 0; input[x] != '\0'; x++)
    {
        count++;
    }
    return count;
}
void reverse(char input[], int start, int end)
{
    int i = start;
    int j = end;
    while (i <= j)
    {
        int temp = input[i]; // swapping
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
}
void reverseStringWordWise(char input[])
{
    // Write your code here
    int size = length(input);

    reverse(input, 0, size - 1);

    int start = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            reverse(input, start, i - 1);
            start = i + 1;
        }
        else if (i == size - 1)
        {
            reverse(input, start, i);
        }
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
