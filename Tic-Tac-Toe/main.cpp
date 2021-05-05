//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Reed hunsaker on 4/28/21.
//

#include <iostream>
#include <charconv>
#include <fstream>


using namespace std;

//Global list to keep track of the values of each square

char square[10] = {'O','1','2','3','4','5','6','7','8','9'};

class Players{
    /*
    Class to make a player in the tic-tac-toe game

    Attributes:
        player_name (string): Name of player
        mark (char): Single character mark that will be displayed on board
    */
    string player_name;
    char mark;

public:
/*Public items of the Players class*/

    void set_names (string);
    void set_mark (char);
    string get_name() {return player_name;}
    char get_mark() {return mark;}
};

void Players::set_names(string name){
    /*
    Set the players name

    Arugments:
        name (string): name of player
    */

    player_name = name;
}
void Players::set_mark(char player_mark){
    /*
    Set the players mark (X or O)

    Arugments:
        player_mark (char): player mark (X or O)
    */

    mark = player_mark;
}


void print_board(string player1, string player2){
    /*
    Prints the board with the current state of each tile

    Arugments:
        player1 (string): Name of player 1
        player2 (string): Name of player 2
    */

    system("clear");
    
    cout << "\n\n\t\t Tic-Tac-Toe \n\n";
    
    cout << "Player 1: " << player1 << "(X)"<< "\tPlayer 2: " << player2 << "(O)" << endl;
    
    cout << "\n\n";

    // script to print out board with status of each square

    cout << "    |    |\n";
    cout << " " << square[1] << "  |  " << square[2] << " | " << square[3] << endl;
    cout << "____|____|____ \n";
    cout << "    |    |\n";
    cout << " " << square[4] << "  |  " << square[5] << " | " << square[6] << endl;
    cout << "____|____|____ \n";
    cout << "    |    |\n";
    cout << " " << square[7] << "  |  " << square[8] << " | " << square[9] << endl;
    cout << "    |    |\n";
    
}

void reset_board(){
    /*Resets the board when the user wants to play again by
    setting each square back to it's original value
    
    Arguments:
        None
    */

    char reset[10] = {'O', '1','2','3','4','5','6','7','8','9'};

    //Loops through each item in the reset list to reset the square list

    for (int i = 1; i <11; i++){
        square[i] = reset[i];
    }
}

int game_over_board(string winner, int code, string loser){
    /*
    Displays the outcome of the game as well as the outcome of past games

    Arugments:
        Winner (string): player that won the game
        code (int): tells program if win or tie (1 for win or 0 for tie)
        loser (string): Player that lost the game
    */

    string response;
    string text;

    ofstream File;

    //opens file where match history is kept

    File.open("Winners.txt", ios_base::app);

    //clears the screen from the last board
    
    system("clear");
    
    cout << "\n\n\t\t Tic-Tac-Toe \n\n";
    if (code == 1){
        cout << winner << " Wins!\n\n";
        File << winner << " (W) - " << loser << " (L)\n\n";
    }
    else{
        cout << "Tie!\n\n";
        File << winner << " (T) - " << loser << " (T)\n\n";
    }

    cout << "Match History: \n\n";
    File.close();

    ifstream ReadFile("Winners.txt");

    while (getline(ReadFile, text)){
        cout << text << endl;
    }

    ReadFile.close();
    
    cout << "\n\nPlay again[yes/no]? ";
    cin >> response;
    
    //convert to lower case

    transform(response.begin(), response.end(), response.begin(), ::tolower);
    
    if (response== "no"){
        return 0;
    }
    else{
        return 1;
    }

}

int check(){
    /*Checks to see if anyone has won the game yet. 
    Returns 1 for win, returns 0 for the game isn't over, and a -1 for a tie
    
    Arguments:
        None
    */

    // Horizontal squares 1/2/3

    if (square[1] == square[2] && square[2] == square[3] && square[1] && square[3]){
        return 1;
    }

    // Vertical squares 1/4/7

    else if (square[1] == square[4] && square[4] == square[7] && square[1] && square[7]){
        return 1;
    }

    // Diagonal squares 1/5/9

    else if (square[1] == square[5] && square[5] == square[9] && square[1] == square[9]){
        return 1;
    }

    // Diagonal squares 3/5/7

    else if (square[3] == square[5] && square[5] == square[7] && square[3] == square[7]){
        return 1;
    }

    // Vertical squares 2/5/8

    else if (square[2] == square[5] && square[5] == square[8] && square[2] == square[8]){
        return 1;
    }

    // Vertical squares 3/6/9

    else if (square[3] == square[6] && square[6] == square[9] && square[3] == square[9]){
        return 1;
    }

    // Horizontal squares 4/5/6

    else if (square[4] == square[5] && square[5] == square[6] && square[4] == square[6]){
        return 1;
    }

    // Horizontal squares 7/8/9

    else if (square[7] == square[8] && square[8] == square[9] && square[7] == square[9]){
        return 1;
    }

    //Checks to see if there is still a number on the board that can be played

    else if(square[1] == '1' || square[2] == '2' || square[3] == '3' || square[4] == '4' || square[5] == '5' || square[6]
            == '6' || square[7] == '7' || square[8] == '8' || square[9] == '9'){
        return 0;
    }

    //If there are no numbers and no winner then it is a tie

    else{
        return -1;
    }
}

int main() {
    /*
    Main function that runs the program

    Arguments:
        None
    */
    
    string player1_name;
    string player2_name;
    int choice;
    bool game_over = false;
    char player1_mark = 'X';
    char player2_mark = 'O';
    int current_player = 0;
    int check_marker = 0;
    int check_play_again = 0;
    char mark = 'X';
    
    cout << "Player 1 Name: ";
    cin >> player1_name;
    cout << "\n" << "player 2 Name: ";
    cin >> player2_name;
    

    // Two instances of the player class

    Players player1;
    Players player2;
    
    player1.set_names(player1_name);
    player2.set_names(player2_name);
    
    player1.set_mark(player1_mark);
    player2.set_mark(player2_mark);

    //game loop

    while (!game_over){

        //prints the board

        print_board(player1.get_name(), player2.get_name());

        //Checks whos turn it is

        if (current_player % 2 == 0){
            cout <<"\n"<< player1.get_name() << " ("<< player1.get_mark() << "):\n\nChoose a square: ";
            cin >> choice;
        }
        else if (current_player % 2 == 1){
            cout <<"\n"<< player2.get_name() << " ("<< player2.get_mark() << "):\n\nChoose a square: ";
            cin >> choice;
        }
        else{
            choice = 0;
        }

        //sets mark to the players mark
        
        if (current_player % 2 == 0){
            mark = player1.get_mark();
        }
        else if (current_player % 2 == 1){
            mark = player2.get_mark();
        }

        //Checks to make sure user put in a correct input

        while(square[choice] == 'X' || square[choice] =='O'|| cin.fail()){

            //clears user input so it doesn't spam the terminal

            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please try again: ";
            cin >> choice;

        }

        //updates the square with the mark 

        square[choice] = mark; 

        //Checks to see if anyone has won
        
        check_marker = check();
        
        if (check_marker == 1 && current_player % 2 == 0){
            
            //player1 wins

            check_play_again = game_over_board(player1.get_name(), check_marker, player2.get_name());
            if (check_play_again == 1){
                reset_board();
            }
            
        }
        else if (check_marker == 1 && current_player % 2 == 1){
            
            //player2 wins

            check_play_again = game_over_board(player2.get_name(), check_marker, player1.get_name());
            if (check_play_again == 1){
                reset_board();
            }
            else{
                return 0;
            }
        }
        else if (check_marker == -1){

            //tie

            check_play_again = game_over_board(player1.get_name(), check_marker, player2.get_name());
            if (check_play_again == 1){
                reset_board();
            }
            else{
                return 0;
            }
        }
        else{

            //switches players

            current_player++;
        }
        
        
    }
    
    return 0;
}