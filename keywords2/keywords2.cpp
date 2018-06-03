// keywords2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
//includes functions for converting charaters to uppercase.
#include <cctype>

using namespace std;
/*
int shutDown()
{
	//shut down
	if (wrong == MAX_WRONG)
	{
		cout << "\nRecruit " << login << " you've been hanged!";
	}
	else if (wrong == 0)
	{
		cout << "PERFECT SCORE!!!" << endl;
		cout << "\nRecruit " << login << " you guessed it!";
	}
	else
	{
		cout << "\nRecruit " << login << " you guessed it!";
	}
	cout << "\nThe word was " << THE_WORD << endl;
}
*/
int main()
{
	//setup
	const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed.

	vector<string> words; //collection of possible words to guess.
	words.push_back("SPY");
	words.push_back("SNEAKY");
	words.push_back("AGENT");
	words.push_back("OPERATION");
	words.push_back("CASE");
	words.push_back("BURNED");
	words.push_back("CAR");
	words.push_back("CLOAK");
	words.push_back("SURVEILLANCE");
	words.push_back("SECRET");

	char again = 'y';

	do
	{
		int threeTimes = 3;
		
		string login = "";						//recuits name.

												// Display Title of program to user
		cout << "******Welcome The Code Breaker Training Simulation Program******\n**********named Keywords for CIA recruits. Gook luck!***********\n";
		cout << "\nPlease login with your name: " << endl;
		cin >> login;

		for (int j = 0; j < threeTimes; ++j)
		{
			//makes sure each time the codes is run it chooses a new word.
			srand(static_cast<unsigned int>(time(0)));
			//randomized the words then assigns the first word in the vector to THE_WORD.
			random_shuffle(words.begin(), words.end());

			string THE_WORD = words[0];				//word to guess.
			int wrong = 0;							//number of incorrect guesses.
			string soFar(THE_WORD.size(), '-');		//word guessed so far.
			string used = "";						//letters already guessed.
			

			//main loop
			while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
			{
				cout << "#################################################" << endl;
				cout << "\n\nRecruit " << login << " you have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				cout << "\nYou've used the following letters:\n" << used << endl;
				cout << "\nSo far, the word is:\n" << soFar << endl;

				char guess;

				cout << "\nRecruit " << login << endl;
				cout << "Enter your guess: ";
				cin >> guess;

				guess = toupper(guess); //make uppercase since secret word in uppercase.

				while (used.find(guess) != string::npos)
				{
					cout << "#################################################" << endl;
					cout << "Sorry" << login << ", you've already guessed " << guess << "." << endl;
					cout << "Enter your guess: ";
					cin >> guess;
					guess = toupper(guess);
				}
				used += guess;
				if (THE_WORD.find(guess) != string::npos)
				{
					cout << "#################################################" << endl;
					cout << "That's right " << login << ", " << guess << " is in the word.\n";
					//update soFar to include newly guessed letter
					for (int i = 0; i < THE_WORD.length(); ++i)
					{
						if (THE_WORD[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				else
				{
					cout << "#################################################" << endl;
					cout << "Sorry " << login << ", " << guess << " isn't in the word.\n";
					++wrong;
				}
			}
			//shutDown();

			//shut down
			if (wrong == MAX_WRONG)
			{
				system("cls");
				cout << "#################################################" << endl;
				cout << "\n\nRecruit " << login << " you have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				cout << "\nYou've used the following letters:\n" << used << endl;
				cout << "\nSo far, the word is:\n" << soFar << endl;
				cout << "\nRecruit " << login << " you've been hanged!" << endl;
			}
			else if (wrong == 0)
			{
				system("cls");
				cout << "#################################################" << endl;
				cout << "\n\nRecruit " << login << " you have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				cout << "\nYou've used the following letters:\n" << used << endl;
				cout << "\nSo far, the word is:\n" << soFar << endl;
				cout << "#################################################" << endl;
				cout << "\nPERFECT SCORE!!!" << endl;
				cout << "\nRecruit " << login << " you guessed it!" << endl;
			}
			else
			{
				system("cls");
				cout << "#################################################" << endl;
				cout << "\n\nRecruit " << login << " you have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				cout << "\nYou've used the following letters:\n" << used << endl;
				cout << "\nSo far, the word is:\n" << soFar << endl;
				cout << "\nRecruit " << login << " you guessed it!" << endl;
			}
			cout << "#################################################" << endl;
			cout << "\nThe word was " << THE_WORD << "\n";
		}

		cout << "\nRerun simulation?" << endl;
		cin >> again;

	} while (again != 'n');

    return 0;
}



// Ask the recruit to login using thier name

// Hold the recruit's name in a var, and address them by it throughout the simulation.

// Display an overview of what Keywords II is to the recruit 

// Display an directions to the recruit on how to use Keywords



// Create a collection of 10 words you had wrote down manually

// Create an int var to count the number of simulations being run starting at 1

// Display the simulation # is staring to the recruit. 

// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 



// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word

//     Tell recruit how many incorrect guesses he or she has left

//     Show recruit the letters he or she has guessed

//     Show player how much of the secret word he or she has guessed

//     Get recruit's next guess

//     While recruit has entered a letter that he or she has already guessed

//          Get recruit ’s guess

//     Add the new guess to the group of used letters

//     If the guess is in the secret word

//          Tell the recruit the guess is correct

//          Update the word guessed so far with the new letter

//     Otherwise

//          Tell the recruit the guess is incorrect

//          Increment the number of incorrect guesses the recruit has made

// If the recruit has made too many incorrect guesses

//     Tell the recruit that he or she has failed the Keywords II course.

// Otherwise

//     Congratulate the recruit on guessing the secret words

// Ask the recruit if they would like to run the simulation again

// If the recruit wants to run the simulation again

//     Increment the number of simiulations ran counter

//     Move program execution back up to // Display the simulation # is staring to the recruit. 

// Otherwise 

//     Display End of Simulations to the recruit

//     Pause the Simulation with press any key to continue