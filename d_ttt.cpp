#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

void displayBoard() {
    cout << "\nTic-Tac-Toe Board:\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool checkWin() {
    for(int i=0;i<3;i++)
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return true;
    for(int i=0;i<3;i++)
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return true;
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return true;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return true;
    return false;
}

int main() {
    int choice; char turn='X';
    for(int i=0;i<9;i++) {
        displayBoard();
        cout << "Player " << turn << ", enter position: ";
        cin >> choice;
        int row=(choice-1)/3, col=(choice-1)%3;
        if(board[row][col]=='X' || board[row][col]=='O') {
            cout << "Invalid move! Try again.\n"; i--; continue;
        }
        board[row][col]=turn;
        if(checkWin()) { displayBoard(); cout<<"Player "<<turn<<" wins!\n"; return 0; }
        turn = (turn=='X')?'O':'X';
    }
    displayBoard();
    cout<<"It's a draw!\n";
    return 0;
}
