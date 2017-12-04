/** The Code Goes Here, Please Add some Documentations and comments to make the code more readable **/
#include <iostream>
#include <string>
using namespace std;
char board[6][7];
char player='X';
int draw_test=0;
void Print(char board[6][7])
{

    cout<<" 1   2   3   4   5   6   7\n";
	for(int a = 0; a<= 5; a++)
	{
		for(int b =0; b <= 6; b++)
            cout<<char(218)<<char(196)<<char(191)<<" ";
            cout<<'\n';
		for(int b =0; b <= 6; b++)
            cout<<char(179)<<board[a][b]<<char(179)<<" ";
            cout<<'\n';
		for(int b =0; b <= 6; b++)
            cout<<char(192)<<char(196)<<char(217)<<" ";
            cout<<'\n';
	}
}
bool insert_(char board[6][7],char player,int column)
{
 if(column>=0 && column<=6)
 {
     if(board[0][column]==' ')
     {
        int i;
        for(i = 0 ; board[i][column]==' ' ; i++)
            {
                if(i == 5)
                  {
                    board[i][column] = player;
                  }
            }
        board[i-1][column]=player;
     }
     else
     {
         cout<<"column is full"<<endl;
         return false;
     }

 }
 else
 {
     cout<<"value error"<<endl;

     return false;
 }
    Print(board);
    draw_test++;
    return true;

}


void switchPlayer(char &player)
{
    if(player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }


}
char Iswinning(char board[6][7])
{
    draw_test++;
    int horizontal_X=0;
    int horizontal_O=0;
    for(int i=5;i>=0;i--)
    {
        for(int j=0;j<=6;j++)
        {
            if(board[i][j]=='X')
            {
                horizontal_X++;
                horizontal_O=0;
                if(horizontal_X==4)
                {
                    cout<<"X horizontal"<<endl;
                    return 'X';
                    break;
                }
            }
            else if(board[i][j]=='O')
            {
                horizontal_O++;
                horizontal_X=0;
                if(horizontal_O==4)
                {
                    cout<<"O horizontal"<<endl;
                    return 'O';
                    break;
                }
            }
            else
            {
                horizontal_X=0;
                horizontal_O=0;
                break;
            }
        }
    }
    int vertical_X=0;
    int vertical_O=0;
    for(int i=0;i<=6;i++) //i==>column
    {
        for(int j=5;j>=0;j--) //j==>Row
        {
            if(board[j][i]=='X')
            {
                vertical_X++;
                vertical_O=0;
                if(vertical_X>=4)
                {
                    cout<<"X Vertical"<<endl;
                    return 'X';
                    break;
                }
            }
            else if(board[j][i]=='O')
            {
                vertical_O++;
                vertical_X=0;
                if(vertical_O>=4)
                {
                    cout<<"O Vertical"<<endl;
                    return 'O';
                    break;
                }
            }
            else
            {
                vertical_X=0;
                vertical_O=0;
                break;
            }
        }
    }
    int left_Diagonal_X=0;
    int left_Diagonal_O=0;
    for(int i=5;i>=0;i--)
    {
        for(int j=6;j>=0;j--)
        {
            for(int k=0;k<=5 && k<=6;k++)
            {
                if(board[i-k][j-k]=='X')
                {
                    left_Diagonal_X++;
                    left_Diagonal_O=0;
                    if(left_Diagonal_X>=4)
                    {
                        cout<<"X Left_diag"<<endl;
                        return 'X';
                    }
                }
                else if(board[i-k][j-k]=='O')
                {
                    left_Diagonal_O++;
                    left_Diagonal_X=0;
                    if(left_Diagonal_O>=4)
                    {
                        cout<<"O Left_diag"<<endl;
                        return 'O';
                    }
                }
                else
                {
                    left_Diagonal_X=0;
                    left_Diagonal_O=0;
                }

            }
        }
    }
    int Right_Diagonal_X=0;
    int Right_Diagonal_O=0;
    for(int i=5;i>=0;i--)
    {
        for(int j=0;j<=6;j++)
        {
            for(int k=0;k<=5 && k<=6;k++)
            {
                if(board[i-k][j+k]=='X')
                {
                    Right_Diagonal_X++;
                    Right_Diagonal_O=0;
                    if(Right_Diagonal_X>=4)
                    {
                        cout<<"X Right_diag"<<endl;
                        return 'X';
                    }
                }
                else if(board[i-k][j+k]=='O')
                {
                    Right_Diagonal_O++;
                    Right_Diagonal_X=0;
                    if(Right_Diagonal_O>=4)
                    {
                        cout<<"O Right_diag"<<endl;
                        return 'O';
                    }
                }
                else
                {
                    Right_Diagonal_X=0;
                    Right_Diagonal_O=0;
                }

            }
        }
    }

if(draw_test==42)
{
    return ' ';
}
}



int main()
{
    for(int a =0;a <= 5; a++)
    {
		for(int b = 0; b<=6; b++)
            {
                board[a][b]=' ';
            }
    }
    Print(board);
    do
    {
        char winner;
        winner=Iswinning(board);
        if(winner=='X')
        {
            cout<<"Winner is player 1!"<<endl;
            break;
        }
        else if(winner=='O')
        {
            cout<<"Winner is player 2!"<<endl;
            break;
        }
        else if(winner==' ')
        {
            cout<<"Game is draw!"<<endl;
            break;
        }
        if(player=='X')
        {
            cout<<"Player 1's turn"<<endl;
        }

        else
        {
            cout<<"Player 2's turn"<<endl;
        }

        int column;
        cin>>column;
        column--;

        if(insert_(board,player,column))
        {
            switchPlayer(player);
        }



    }while(true);


    return 0;
}
