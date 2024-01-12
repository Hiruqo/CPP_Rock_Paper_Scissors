// includes
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

// using statements
using std::cout, std::endl, std::cin, std::string;

// check if data is a number
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// assign numebrs to choices
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;

// 'clear' console
void clrScreen() {
    system("cls");
}

// AI pick a Rock, Paper, Scissors
int aiPick() {
    // std::srand(std::time(0));
    int random = (rand() % 3) + 1;

    return random;
}

// fun to print ai choice in text form
void aiShowPick(int val) {
    switch(val) {
        case 1 :
            cout << "AI: ROCK" << endl;
            break;
        case 2 :
            cout << "AI: PAPER" << endl;
            break;
        case 3 :
            cout << "AI: SCISSORS" << endl;
            break;
        default :
            cout << "Error at aiShowPick()" << endl;
            break;
    }
}

// string to lowercase + player's pick
int playerPick(std::string arg) {

    for(char &chr : arg) {
        chr = tolower(chr);
    }

    if((arg == "rock") || (arg == "roc") || (arg == "ro") || (arg == "r") || (arg == "rck")){
        return ROCK;
    } else if((arg == "paper") || (arg == "pape") || (arg == "pap") || (arg == "pa") || (arg == "p") || (arg == "ppr")){
        return PAPER;
    } else if((arg == "scissors") || (arg == "scissor") || (arg == "scisso") || (arg == "sciss") || (arg == "scis") || (arg == "sci") || (arg == "sc") || (arg == "s")){
        return SCISSORS;
    } else {
        cout << "Please enter only Rock/Paper/Scissors text." << endl;
    }
}

// who got a point
int result(int player, int ai) {
    if((player == ROCK && ai == ROCK) ||(player == PAPER && ai == PAPER) || (player == SCISSORS && ai == SCISSORS)) {
        return 1;
    } else if((player == ROCK && ai == SCISSORS) || (player == PAPER && ai == ROCK) ||(player == SCISSORS && ai == PAPER)) {
        return 2;
    } else if((player == SCISSORS && ai == ROCK) ||(player == ROCK && ai == PAPER) ||(player == PAPER && ai == SCISSORS)) {
        return 3;
    } else {
        return 0;
    }
}

// main loop
int main() {
    string playerChoice;
    string playerName;

    int aiRPS = 0;
    int playerRPS = 0;
    int RoundCounter = 0;
    int ResultOfTheRound = 0;
    int playerPoints = 0;
    int aiPoints = 0;
    int maxPoints = 0;  // correct data flag

    bool GameOver = false;
    bool goodData = false;

    cout << endl;
    cout << "-------- Rock/Paper/Scissors --------" << endl;
    cout << endl;

    // set the player's nickname (with whitespaces)
    cout << "Set your nick: ";
    std::getline(cin >> std::ws, playerName);

    // set the MAX number of points able to collect
    cout << "Set the MAX number of points: ";
    cin >> maxPoints;

    // inf main loop
    while(!GameOver) {

        // clear screen
        clrScreen();

        cout << endl;
        cout << "-------- Round nr " << RoundCounter << " --------" << endl;
        cout << endl;

        // player pick one
        cout << "Choose between: Rock/Paper/Scissors" << endl;
        cout << playerName << ": ";
        cin >> playerChoice;

        // generate the result of the round
        aiRPS = aiPick();
        playerRPS = playerPick(playerChoice);
        ResultOfTheRound = result(playerRPS, aiRPS);

        // show what AI picks
        aiShowPick(aiRPS);

        // show the result
        switch(ResultOfTheRound) {
            case 1 :
                cout << "--> DRAW --> (" << playerName << " : ai) " << playerPoints << " : " << aiPoints << endl;
                break;
            case 2 :
                cout << "--> (" << playerName << " : ai) " << ++playerPoints << " : " << aiPoints << endl;
                break;
            case 3 :
                cout << "--> (" << playerName << " : ai) " << playerPoints << " : " << ++aiPoints << endl;
                break;
            default :
                cout << "Error in main switch(ResultOfTheRound)" << endl;
                break;
        }

        if(playerPoints == maxPoints) {
            GameOver = true;
            cout << endl;
            cout << playerName << " won the game! Congratulations!" << endl;
        } else if(aiPoints == maxPoints) {
            GameOver = true;
            cout << endl;
            cout << "AI won the game! GameOver!" << endl;
        } 

        RoundCounter++;

        cout << "\n";
        // w8 for user input (hold results)
        system("pause");
    }
    
    return 0;
}