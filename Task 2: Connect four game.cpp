/** The Code Goes Here, Please Add some Documentations and comments to make the code more readable **/
#include <iostream>
#include <string>
using namespace std;
char board[6][7];
char player;
void Print(char board[6][7])
{

    cout<<" 1   2   3   4   5   6   7\n";
	for(int a = 0; a<= 5; a++)
	{
		for(int b =0; b <= 6; b++) cout<<char(218)<<char(196)<<char(191)<<" ";
		cout<<'\n';
		for(int b =0; b <= 6; b++) cout<<char(179)<<board[a][b]<<char(179)<<" ";
		cout<<'\n';
		for(int b =0; b <= 6; b++) cout<<char(192)<<char(196)<<char(217)<<" ";
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
        for(i = 0;board[i][column]==' ';i++)
            {
                if(i == 5)
                  {
                    board[i][column]=player;
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
    return true;

}

int main()
{
    bool win=true;
    int cond1=0;
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
        cin>> cond1;
        int column;
        cin>>column;
        insert_(board,'x',column);
        if (cond1==1)
        {
            win=true;
        }
        else
        {
            win=false;
        }

    }while(!win);


    return 0;
}
