#include <iostream>
using namespace std;
#define MAX 10

//입력 함수
void Input(char *words, int *number, char *direction)
{

    cin >> words;
    cin >> *number;
    cin >> *direction;
}

//배열 길이 함수
void Index(char *words, int *index)
{

    *index = 0;
    while (words[*index] != '\0')
    {
        (*index)++;
    }
}

//왼쪽 이동 함수
void Left(char *words, int index)
{

    char temp;
    int i;

    temp = words[0];
    for (i = 0; i < index - 1; i++)
    {
        words[i] = words[i + 1];
    }
    words[index - 1] = temp;
}

// 오른쪽 이동 함수
void Right(char *words, int index)
{

    char temp;
    int i;

    temp = words[index - 1];
    for (i = index - 1; i >= 0; i--)
    {
        words[i] = words[i - 1];
    }
    words[0] = temp;
}

//
void Push(char *words, int number, char direction, int index)
{

    int i;
    int j;
    char temp;

    //정방향 일때
    if (number > 0)
    {
        if (direction == 'L' || direction == 'l')
        {
            for (j = 0; j < number; j++)
            {
                Left(words, index);
            }
        }

        else
        {

            for (j = 0; j < number; j++)
            {
                Right(words, index);
            }
        }
    }

    //역방향 일때
    else if (number < 0)
    {
        if (direction == 'L' || direction == 'l')
        {
            Right(words, index);
        }
        else
        {
            Left(words, index);
        }
    }
}

//출력 함수
void Output(char *words)
{
    cout << words;
}

int main()
{

    char words[MAX];
    int number;
    char direction;
    int index;

    Input(words, &number, &direction);
    Index(words, &index);
    Push(words, number, direction, index);
    Output(words);

    return 0;
}
