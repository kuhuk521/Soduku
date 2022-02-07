#include <iostream>
#include <vector>
using namespace std;

void print(int input[9][9])
{   
    cout<<endl<<endl<<" --OUTPUT-- "<<endl<<endl;

    for (int row = 0; row < 9; row++){
      for (int col = 0; col < 9; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << input[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<9; i++)
            cout << "---";
      }
      cout << endl;
   }
}

bool isSafeGrid(int input[9][9], int row, int col, int num)
{
    int i, j;
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (input[i + rowFactor][j + colFactor] == num)
                return false;
        }
    }
    return true;
}

bool isSafeCol(int input[9][9], int col, int num)
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (input[i][col] == num)
            return false;
    }
    return true;
}

bool isSafeRow(int input[9][9], int row, int num)
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (input[row][i] == num)
            return false;
    }
    return true;
}

bool isSafe(int input[9][9], int row, int col, int num)
{

    if (isSafeRow(input, row, num) && isSafeCol(input, col, num) && isSafeGrid(input, row, col, num))
        return true;

    else
        return false;
}

bool isEmpty(int input[9][9], int &row, int &col)
{

    int i, j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (input[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool solveSoduku(int input[9][9])
{

    int row, col, i, j;

    if (!isEmpty(input, row, col))
    {
        return true;
    }

    for (i = 1; i <= 9; i++)
    {
        if (isSafe(input, row, col, i))
        {
            input[row][col] = i;
            if (solveSoduku(input))
            {
                return true;
            }
            input[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int input[9][9], i, j, k;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            cin >> input[i][j];
        }
    }

    if (solveSoduku(input))
    {
        print(input);
    }

    return 0;
}