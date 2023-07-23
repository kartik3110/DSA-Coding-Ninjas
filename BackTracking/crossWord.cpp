#include <bits/stdc++.h>
#include <string>
using namespace std;
vector<string> crossword;
vector<string> words;
#define N 10

bool isValidHorizontal(int r, int c, string word)
{
    // check if appropriate size is available
    if (c - 1 >= 0 && crossword[r][c - 1] != '+')
        return false;
    if (c + word.length() < N && crossword[r][c + word.length()] != '+')
        return false;
    // check if word can be placed in the available row
    for (int i = 0; i < word.length(); i++)
    {
        if (c + i >= N) // need to check again as might have passed thru previous if statement
            return false;
        if (crossword[r][c + i] == '-' || crossword[r][c + i] == word[i])
            continue;
        else
            return false;
    }
    return true;
}

vector<bool> placeWordHorizontally(int r, int c, string word)
{
    vector<bool> wePlaced(word.length(), false);
    for (int i = 0; i < word.length(); i++)
    {
        if (crossword[r][c + i] == '-')
        {
            crossword[r][c + i] = word[i];
            wePlaced[i] = true;
        }
    }
    return wePlaced;
}

void removeWordHorizontally(int r, int c, string word, vector<bool> wePlaced)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (wePlaced[i] == true)
        {
            crossword[r][c + i] = '-';
        }
    }
}

bool isValidVertical(int r, int c, string word)
{
    // check if appropriate size is available
    if (r - 1 >= 0 && crossword[r - 1][c] != '+')
        return false;
    if (r + word.length() < N && crossword[r + word.length()][c] != '+')
        return false;
    // check if word can be placed in the available row
    for (int i = 0; i < word.length(); i++)
    {
        if (r + i >= N) // need to check again as might have passed thru previous if statement
            return false;
        if (crossword[r + i][c] == '-' || crossword[r + i][c] == word[i])
            continue;
        else
            return false;
    }
    return true;
}

vector<bool> placeWordVertically(int r, int c, string word)
{
    vector<bool> wePlaced(word.length(), false);
    for (int i = 0; i < word.length(); i++)
    {
        if (crossword[r + i][c] == '-')
        {
            crossword[r + i][c] = word[i];
            wePlaced[i] = true;
        }
    }
    return wePlaced;
}
void removeWordVertically(int r, int c, string word, vector<bool> wePlaced)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (wePlaced[i] == true)
        {
            crossword[r + i][c] = '-';
        }
    }
}

void solve(int wordIndex)
{
    if (wordIndex == words.size())
    {
        for (int i = 0; i < N; i++)
        {
            cout << crossword[i] << endl;
        }
        return;
    }
    string word = words[wordIndex];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (crossword[i][j] == '-' || crossword[i][j] == word[0])
            {
                if (isValidHorizontal(i, j, word))
                {
                    vector<bool> wePlaced = placeWordHorizontally(i, j, word);
                    solve(wordIndex + 1);
                    removeWordHorizontally(i, j, word, wePlaced);
                }
                if (isValidVertical(i, j, word))
                {
                    vector<bool> wePlaced = placeWordVertically(i, j, word);
                    solve(wordIndex + 1);
                    removeWordVertically(i, j, word, wePlaced);
                }
            }
        }
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        cout << "enter grid: ";
        string x;
        cin >> x;
        crossword.push_back(x);
    }
    cout << "enter word line: ";
    string wordInput;
    cin >> wordInput;
    string s = "";
    for (char c : wordInput)
    {
        if (c == ';')
        {
            words.push_back(s);
            s = "";
        }
        else
            s += c;
    }
    words.push_back(s);
    solve(0);

    return 0;
}
// +-++++++++
// +-++++++++
// +-++++++++
// +-----++++
// +-+++-++++
// +-+++-++++
// +++++-++++
// ++------++
// +++++-++++
// +++++-++++
// LONDON;DELHI;ICELAND;ANKARA
