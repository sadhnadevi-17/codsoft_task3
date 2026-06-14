#include<iostream>
using namespace std;

char board[3][3];

void initializeBoard(){
    char c = '1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=c++;
        }
    }
}

void displayBoard(){
    for(int i=0;i<3;i++){
        cout<<" "<<board[i][0]<<"  | "<<board[i][1]<<" | "<<board[i][2]<<endl;

        if(i<2)
        cout<<" ---|---|---"<<endl;
    }
    cout<<"\n"; 
}

bool checkWin(char player){
    for(int i=0;i<3;i++){
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player )
        return true;
    }
    for(int i=0;i<3;i++){
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
        return true;
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
       return true;

    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
       return true;
    
    return false;
}

bool checkDraw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;i++){
            if(board[i][j] != 'X' && board[i][j] != '0')
            return false;
        }
    }
    return true;
}
int main(){
    char playAgain;
    do{
        initializeBoard();
        char currentPlayer = 'X';
        int choice;

        while(true){
            displayBoard();
            cout<<"Player "<<currentPlayer<<",enter position(1-9): ";
            cin>>choice;

            bool validMove = false;

            for (int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[i][j] == choice+'0'){
                        board[i][j] = currentPlayer;
                        validMove = true;
                    }
                }
            }
            if(!validMove){
                cout<<"Invalid Move! Try Again.\n";
                continue;
            }
            if(checkWin(currentPlayer)){
                displayBoard();
                cout<<"Player"<<currentPlayer<<" Wins!\n";
                break;
            }
            if(checkDraw()) {
                displayBoard();
                cout << "Game Draw!\n";
                break;
            }

            // Switch Player
            if(currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for Playing!\n";

    return 0;
}