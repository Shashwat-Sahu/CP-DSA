#include <bits/stdc++.h>
using namespace std;
#define n 4
void printsol(int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}
bool isvalid(int board[n][n], int row, int col) //We just need to check for the upper rows which have been filled before this
{
    //To check vertically in a particular column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;
    //To check upper diagonal towards the right
    for (int i = row, j = col; i > 0 && j < n; i--, j++)
        if (board[i][j])
            return false;
    //To check upper diagonal towards the left
    for (int i = row, j = col; i > 0 && j > 0; i--, j--)
        if (board[i][j])
            return false;
    return true;
}
bool solverow(int board[n][n], int row)
{
    if (row == n)
        return true;
    for (int col = 0; col < n; col++)
        if (isvalid(board, row, col))
        {
            board[row][col] = 1;
            if (solverow(board, row + 1))
                return true;
            board[row][col] = 0; //Backtracking for a wrong ans
        }
    return false; //Backtracking
}
int main()
{
    int board[n][n] = {0};
    if (solverow(board, 0))
        printsol(board);
    else
        cout << "No Solution Exists";
    return 0;
}