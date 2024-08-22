#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;   

void displayMenu()  // display menu 
{
    cout << "\n1) ROCK"<< endl;//print Rock
    cout << "\n2) PAPER"<< endl;//print paper
    cout << "\n3) SCISSOR"<< endl;//print scissor
    cout << "\n-> Select Your Choice :- ";// enter your choice
}

void playRound(char playerChoice, char computerChoice, int &playerScore, int &computerScore) // round play for win or loss or tie
{
    switch(playerChoice) // swich case for Player choice
	{
        case 'R':		// case R is for player Rock choice
            switch(computerChoice) 			//player rock switch case for computer's choice
			{
                case 'R': cout << "It's a tie!" << endl; break;		//it's for tie between player & computer
                case 'P': cout << "You lose!" << endl; computerScore++; break;		//it's for you lose between player & computer
                case 'S': cout << "You win!" << endl; playerScore++; break;		//it's for You win between player & computer
            }
            break;//break statement
        case 'P':		// case P is player Paper choice
            switch(computerChoice) 			//player Paper switch case for computer's choice
			{
                case 'R': cout << "You win!" << endl; playerScore++; break;
                case 'P': cout << "It's a tie!" << endl; break;
                case 'S': cout << "You lose!" << endl; computerScore++; break;
            }
            break;
        case 'S':		// case S is player Scissor choice
            switch(computerChoice) 			//player Scssior switch case for computer's choice
			{
                case 'R': cout << "You lose!" << endl; computerScore++; break;
                case 'P': cout << "You win!" << endl; playerScore++; break;
                case 'S': cout << "It's a tie!" << endl; break;
            }
            break;
        default:
            cout << "Invalid input!" << endl;  //invalid chioice
    }
}

int main() 
{
    srand(time(0)); // Initialize random number generator
    char playerChoice, computerChoice;
    int randomChoice, rounds,i;
    int playerScore = 0, computerScore = 0;
    string playerName;
	cout << "Welcome to Rock,Paper,Scissors!"<<endl;//Game welcome message


	cout << "\n\n*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*";
	cout << "\n\n\t\t\tNAME";
	cout << "\n\n*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*";
    // Accept the player's name
    cout << "\nEnter Your Name :- ";
    cin >> playerName;


	cout << "\n\n*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*";
	cout << "\n\n\t\t\tROUNDS";
	cout << "\n\n*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*\n";
    // Ask the qustion to player number of rounds to play
    cout << playerName << ", How Many Rounds You Want To Play? :-";
    cin >> rounds;

	//start the game rock , paper , scissor
	cout << "\n\n*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*";
	cout << "\n\n\t\t\tGAME";
	cout << "\n\n*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*__*";
	
	
    for (i=0;i<rounds;i++)//loop for players enter the round as 
	{
        cout << "\nRound No:- "<< (i+1) << "/" << rounds << endl;		// round number ex:-1/3
        cout << "\n_* " << playerName << "'s Score :- " << playerScore << endl;		// this print your score
        cout << "\n_* Computer Score :- " << computerScore << endl;      // this print computer score

        displayMenu();   // display menu called
        int choice;
        cin >> choice;   //scan choice

        switch(choice) 
		{
            case 1: playerChoice = 'R'; break; //player Rock choice 
            case 2: playerChoice = 'P'; break; //player Paper choice 
            case 3: playerChoice = 'S'; break; //player Scssior choice 
            default: playerChoice = 'X'; break; // default choice
        }

        // Generate computer's choice
        randomChoice=rand()%3; 
        if (randomChoice == 0) 
		{
            computerChoice = 'R';
        } 
		else if (randomChoice == 1) 
		{
            computerChoice = 'P';
        } 
		else 
		{
            computerChoice = 'S';
        }
        
		// computer choice print	
        cout << "Computers choice Is :- " << (computerChoice == 'R' ? "ROCK":(computerChoice == 'P' ? "PAPER" : "SCISSOR"))<< endl;
		
        playRound(playerChoice, computerChoice, playerScore, computerScore);
    }
    
	//print Final score
    cout << "\nFinal Scores:- \n";
    cout << playerName << "'s Score :- " << playerScore << endl;
    cout << "Computer Score :- " << computerScore << endl;
    
	// print your condition game final score 
    if (playerScore > computerScore) 
	{
        cout << "You win the game!" << endl;
    } 
	else if (playerScore < computerScore) 
	{
        cout << "You lose the game!" << endl;
    } 
	else 
	{
        cout << "The game is a tie!" << endl;
    }

    return 0;
}
