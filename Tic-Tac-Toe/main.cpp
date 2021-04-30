//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Reed hunsaker on 4/28/21.
//

#include <iostream>
#include <charconv>


using namespace std;

char square[10] = {'O', '1','2','3','4','5','6','7','8','9'};

class Players{
    string player_name;
    int score;
    char mark;
public:
    void set_names (string);
    void set_score (int);
    void set_mark (char);
    string get_name() {return player_name;}
    int get_score() {return score;}
    char get_mark() {return mark;}
};

void Players::set_names(string name){
    player_name = name;
}
void Players::set_score(int player_score){
    score = player_score;
}
void Players::set_mark(char player_mark){
    mark = player_mark;
}

void print_board(string player1, string player2){
    system("clear");
    
    cout << "\n\n\t\t Tic-Tac-Toe \n\n";
    
    cout << "Player 1: " << player1 << "(X)"<< "\tPlayer 2: " << player2 << "(O)" << endl;
    
    cout << "\n\n";


    cout << "\t|\t |\n";
    cout << " " << square[1] << "  |  " << square[2] << " | " << square[3] << endl;
    cout << "____|____|____ \n";
    cout << "\t|\t |\n";
    
    cout << " " << square[4] << "  |  " << square[5] << " | " << square[6] << endl;
    cout << "____|____|____ \n";
    cout << "\t|\t |\n";
    cout << " " << square[7] << "  |  " << square[8] << " | " << square[9] << endl;
    cout << "\t|\t |\n";
    
}

void reset_board(){
    char reset[10] = {'O', '1','2','3','4','5','6','7','8','9'};
    for (int i = 1; i <11; i++){
        square[i] = reset[i];
    }
}

int game_over_board(string player1, int code){
    string response;
    system("clear");
    
    cout << "\n\n\t\t Tic-Tac-Toe \n\n";
    if (code == 1){
        cout << player1 << " Wins!\n\n";
    }
    else{
        cout << "Tie!\n\n";
    }
    
    cout << "Play again[yes/no]? ";
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
    if (square[1] == square[2] && square[2] == square[3] && square[1] && square[3]){
        return 1;
    }
    else if (square[1] == square[4] && square[4] == square[7] && square[1] && square[7]){
        return 1;
    }
    else if (square[1] == square[5] && square[5] == square[9] && square[1] == square[9]){
        return 1;
    }
    else if (square[3] == square[5] && square[5] == square[7] && square[3] == square[7]){
        return 1;
    }
    else if (square[2] == square[5] && square[5] == square[8] && square[2] == square[8]){
        return 1;
    }
    else if (square[3] == square[6] && square[6] == square[9] && square[3] == square[9]){
        return 1;
    }
    else if (square[4] == square[5] && square[5] == square[6] && square[4] == square[6]){
        return 1;
    }
    else if (square[7] == square[8] && square[8] == square[9] && square[7] == square[9]){
        return 1;
    }
    else if(square[1] == '1' || square[2] == '2' || square[3] == '3' || square[4] == '4' || square[5] == '5' || square[6]
            == '6' || square[7] == '7' || square[8] == '8' || square[9] == '9'){
        return 0;
    }
    else{
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
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
    
    Players player1;
    Players player2;
    
    player1.set_names(player1_name);
    player2.set_names(player2_name);
    
    player1.set_mark(player1_mark);
    player2.set_mark(player2_mark);
    
    
//    cout << "\nPlayer 1: " << player1.get_name() << " Player 2: " << player2.get_name() << "\n";
    
    
//    Save player names or make a new player profile can improve
    
    
//    Input which square
    
    //main loop
    while (!game_over){
        print_board(player1.get_name(), player2.get_name());
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
        
        if (current_player % 2 == 0){
            mark = player1.get_mark();
        }
        else if (current_player % 2 == 1){
            mark = player2.get_mark();
        }
        square[choice] = mark;
        
        check_marker = check();
        
        if (check_marker == 1 && current_player % 2 == 0){
            //player1 wins
            check_play_again = game_over_board(player1.get_name(), check_marker);
            if (check_play_again == 1){
                reset_board();
            }
            
        }
        else if (check_marker == 1 && current_player % 2 == 1){
            //player2 wins
            check_play_again = game_over_board(player2.get_name(), check_marker);
            if (check_play_again == 1){
                reset_board();
            }
            else{
                return 0;
            }
        }
        else if (check_marker == -1){
            //tie
            check_play_again = game_over_board(player1.get_name(), check_marker);
            if (check_play_again == 1){
                reset_board();
            }
            else{
                return 0;
            }
        }
        else{
            current_player++;
        }
        
        
    }
    
    return 0;
}


