#include <iostream>
#include <ctime>
using namespace std;

//function prototypes listed
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    //initializes spaces array for each space on the board along with variables to keep track of player/computer choices
    //and the state of the game
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char playerChoice = 'X';
    char computerChoice = 'O';
    bool inGame = true;

    //draws the board
    drawBoard(spaces);

    while(inGame){
        //playerMove() is called to allow the player to make the first move
        playerMove(spaces, playerChoice);
        //drawBoard() is called to update the board when the player makes a move
        drawBoard(spaces);
        //checkWinner() is called after a move has been played
        if(checkWinner(spaces, playerChoice, computerChoice)){
            //if there is a winner, inGame is set to false and the while loop quits via the break statement 
            inGame = false;
            break;
        }
        //other case after a move is made is to check if it is a tie
        else if(checkTie(spaces)){
            //if a tie is made, then inGame is set to false and the while loop quits vai break statement
            inGame = false;
            break;
        }
        //after the player makes a move and the conditionals are checked, the computer gets to make a move
        computerMove(spaces, computerChoice);
        //board is updated after the computer makes a move
        drawBoard(spaces);
        //conditionals are checked again to see if the game results in a tie, winner, or neither in which the game continues with the player making the next move
        if(checkWinner(spaces, playerChoice, computerChoice)){
            inGame = false;
            break;
        }
        else if(checkTie(spaces)){
            inGame = false;
            break;
        }
    }
    return 0;
}

void drawBoard(char *spaces){
    //cout statements to print all the spaces on the board with the value in the spaces array
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____ " << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____ " << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
}
void playerMove(char *spaces, char player){
    int number;
    do{
        //prints prompt for the user to enter a number between 1 and 9 and takes user input
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        //number-- since number should technically a valid index in the spaces array which ranges from 0-8 inclusive
        number--;
        if(spaces[number] == ' '){
            //updates the spaces array with the character that the user is assigned to if the element of the array 
            //at the specified index is currently filled with an empty space
            spaces[number] = player;
            break;
        }
        //do while loop is used to continue asking for a valid number from the user until it is a value between 1-9
    }while(number < 0 || number > 8);
}
void computerMove(char *spaces, char computer){
    int number;
    //srand is used to seed the random number generator with current time
    srand(time(0));
    while(true){
        //random number is generated between 0 and 8 inclusive to access the array of 9 chars with and index ranging from 0-8
        number = rand() % 9;
        if(spaces[number] == ' '){
            //updates the spaces array with the character of the computer if the element in the array is an empty space
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer){
    //checks all possible combinations of wins including straights and diagonals
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        //ternary operator is used to reduce the number of lines and to check if the chars in the spaces array all belong to the user or not
        //if all characters match that of the user, the user wins. If not, the computer wins
        spaces[0] == player ? cout << "You Win!\n" : cout << "Computer Wins.\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? cout << "You Win!\n" : cout << "Computer Wins.\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? cout << "You Win!\n" : cout << "Computer Wins.\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? cout << "You Win!\n" : cout << "Computer Wins.\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? cout << "You Win!\n" : cout << "Computer Wins.\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? cout << "You Win!\n" : cout << "Computer Wins.\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? cout << "You Win!\n" : cout << "Computer Wins.\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? cout << "You Win!\n" : cout << "Computer Wins.\n";
    }
    else{
        //returns false if there is no winner. There should be no winner until at least the third round of the game where the player makes the third move
        return false;
    }
    //returns true if there is a winner
    return true;
}
bool checkTie(char *spaces){
    //for loop checks if there are any empty spaces and returns false
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    //if all the spaces are filled, the message is printed and true is returned
    cout << "It's a Tie." << endl;
    return true;
}