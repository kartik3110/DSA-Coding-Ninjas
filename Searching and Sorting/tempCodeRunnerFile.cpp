void rotate(int *input, int d, int size)
{
    for (int i = 1; i <= d; i++)
    {
        int temp = input[size - 1];
        for (int j = size - 1; j >= 1; j--)
        {
            input[j] = input[j - 1];
        }
        input[0] = temp;
    }
}