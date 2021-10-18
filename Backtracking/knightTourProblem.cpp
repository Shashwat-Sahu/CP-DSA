// KNIGHT TOUR PROBLEM

#include<bits/stdc++.h>
using namespace std;
#define n 8

void printSol(int sol[n][n]);

bool isSafe(int x, int y, int sol[n][n])
{
    // if the next move is inside the block and the block is unvisited, return true
    return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
}
 
bool helper(int x, int y, int move, int sol[n][n], int xMove[n], int yMove[n]){

    int next_x, next_y;
    
    if(move == n*n)   // if all moves are completed
        return true;
 
    // Try all the next 8 moves from the current block
    for (int i = 0; i < 8; i++)
    {
        next_x = x + xMove[i];
        next_y = y + yMove[i];

        if(isSafe(next_x, next_y, sol)){

            sol[next_x][next_y] = move;

            if(helper(next_x, next_y, move+1, sol, xMove, yMove) == true)
                return true;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return false;
}

int solveKT(){

    int sol[n][n];

    // Initializing solution matrix to -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sol[i][j] = -1;

    // From a particular block, the knight can move in atmost 8 ways
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2}; 
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1}; 
    sol[0][0] = 0;  // Knight starts from first block

    if(helper(0, 0, 1, sol, xMove, yMove) == false){
        cout<<"No solution";
        return 0;
    }
    else 
        printSol(sol); 

    return 1;
}

// Print Solution
void printSol(int sol[n][n]){
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }    
}

int main(){
 
    solveKT();
 
    return 0;
}