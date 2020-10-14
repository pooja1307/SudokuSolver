#include<iostream>
using namespace std;

void printsudoku(int board[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool isRowsafe(int row,int num,int board[][9])
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==num)
            return false;
    }
    return true;
}
bool isColsafe(int col,int num,int board[][9])
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==num)
            return false;
    }
    return true;
}
bool isBoxsafe(int row,int col,int board[][9], int num)
{
    int rowstart=row-row%3;
    int colstart=col-col%3;
    for(int i=rowstart;i<rowstart+3;i++)
    {
        for(int j=colstart;j<colstart+3;j++)
        {
            if(board[i][j]==num)
                return false;
        }
    }
    return true;
}
bool canPlace(int row,int col,int num,int board[][9])
{
    if(isRowsafe(row,num,board)==false)
        return false;
    if(isColsafe(col,num,board)==false)
        return false;
    if(isBoxsafe(row,col,board,num)==false)
        return false;
    return true;
}
bool sudokuSolver(int board[][9])
{
    int row=-1;
    int col=-1;
    bool isEmpty=false;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                row=i;
                col=j;
                isEmpty=true;
                break;
            }
        }
        if(isEmpty==true)
            break;
    }
    //if every cell if filled
    if(isEmpty==false)
    {
     	return true;
    }
    //if not filled
    for(int k=1;k<=9;k++)
    {
        if(canPlace(row,col,k,board)==true)
        {
            board[row][col]=k;
            if(sudokuSolver(board))
                return true;
        }
     	 board[row][col]=0;
    }
    return false;
}
int main()
{
    int n = 9;
    int board[9][9];
    cout<<"Enter the elements of Sudoku, enter 0 in place of dash: "<<endl;
    for(int i = 0; i < n ;i++)
    {
	for(int j = 0; j < n; j++)
        {
        cin >> board[i][j];
        }
    }
    if(sudokuSolver(board))
    {
        cout << "The entered Sudoku can be solved as "<<endl;
        printsudoku(board);
    }
    else
    {
        cout << "The entered Sudoku cannot be solved, kindly recheck the numbers. "<<endl;
    }
}
