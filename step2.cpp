#include <iostream>
using namespace std;
#define COLUMN 3
#define ROW 3

void RightB(char (*words)[ROW])
{
    char temp;
    int i;

    temp = words[2][2];
    for (i = 2; i >= 0; i--)
    {
        words[2][i] = words[2][i - 1];
    }
    words[2][0] = temp;
}

void LeftU(char (*words)[ROW])
{

    char temp;
    int i;

    temp = words[0][0];
    for (i = 0; i < 3; i++)
    {
        words[0][i] = words[0][i + 1];
    }
    words[0][2] = temp;
}

void UpR(char (*words)[ROW])
{
    char temp;
    int i;

    temp = words[0][2];
    for (i = 0; i < 3; i++)
    {
        words[i][2] = words[i + 1][2];
    }
    words[2][2] = temp;
}

void DownL(char (*words)[ROW])
{
    char temp;
    int i;

    temp = words[2][0];
    for (i = 2; i >= 0; i--)
    {
        words[i][0] = words[i - 1][0];
    }
    words[0][0] = temp;
}

void Output(char (*words)[ROW])
{
    int i;
    int j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << words[i][j];
        }
        cout << endl;
    }
}

void Length(char *word, int *length)
{

    *length = 0;
    int i = 0;
    while (word[i] != '\0')
    {
        (*length)++;
        i++;
    }
}

int main()
{

    int length;
    bool isEnd = true;
    char words[ROW][COLUMN] =
        {'R', 'R', 'W',
         'G', 'C', 'W',
         'G', 'B', 'B'};

    char word[2];

    Output(words);
    cout << endl;

    while (isEnd)
    {
        cout << "CUBE> ";

        cin >> word;
        Length(word, &length);
        int i = 0;

        while (i < length)
        {

            if (word[i] == 'U')
            {
                LeftU(words);
                cout << 'U' << endl;
                Output(words);
            }

            if (word[i] == 'R')
            {
                UpR(words);
                cout << 'R' << endl;
                Output(words);
            }

            if (word[i] == 'L')
            {
                DownL(words);
                cout << 'L' << endl;
                Output(words);
            }

            if (word[i] == 'B')
            {
                RightB(words);
                cout << 'B' << endl;
                Output(words);
            }
            if (word[i] == 'Q')
            {
                cout << "Bye~";
                isEnd = false;
            }
            i++;
        }
    }

    return 0;
}
