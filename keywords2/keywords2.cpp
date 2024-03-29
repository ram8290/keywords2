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

int main()
{
	//setup
	const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed.

	// Create a collection of 10 words you had wrote down manually
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

	char again = 'y'; // place holder to rerun whole program.

	do
	{
		int threeTimes = 4; // makes you decode 3 words.
		int fails = 0; // counts the number of times he or she has failed guessing the word.
		int wins = 0; // counts the number of times he or she has correctly guessed the word.
		int s = 1; // count the number of simulations ran.
		
		string login = "";	// Hold the recruit's name in a var, and address them by it throughout the simulation.

		// Display Title of program to user
		cout << "******Welcome To The Code Breaker Training Simulation Program******" << endl;
		cout << "              *******for CIA recruits named*******" << endl;
		cout << "                   *********KEYWORD!*********" << endl;

		// Display an overview of what Keywords II is to the recruit 
		// Display an directions to the recruit on how to use Keywords
		cout << "You will be decoding 3 words before the end of the simulation." << endl;
		cout << "You will take a guess with leatter A-Z to figure out the code." << endl;
		cout << "There are " << MAX_WRONG << " incorrect answers you can give" << endl;
		cout << "for each code before you are 'hanged'." << endl;
		cout << "Good Luck Recruit." << endl;
		// Asks he or she to log in with name.
		cout << "\n\nPlease login with your name: " << endl;
		cin >> login;
		system("cls");
		//Displays the number of simulations run.
		cout << "\n\nSimulation #: " << s << endl;

		// Create an int var to count the number of simulations being run starting at 1
		for (int j = 1; j < threeTimes; ++j)
		{
			//makes sure each time the codes is run it chooses a new word.
			srand(static_cast<unsigned int>(time(0)));
			//randomized the words then assigns the first word in the vector to THE_WORD.
			random_shuffle(words.begin(), words.end());

			// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
			string THE_WORD = words[0];				//word to guess.
			int wrong = 0;							//number of incorrect guesses.
			string soFar(THE_WORD.size(), '-');		//word guessed so far.
			string used = "";						//letters already guessed.
			

			//main loop
			// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
			{
				cout << "#################################################" << endl;
				//Tell recruit how many incorrect guesses he or she has left
				cout << "\n\nRecruit " << login << " you have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				//Show recruit the letters he or she has guessed
				cout << "\nYou've used the following letters:\n" << used << endl;
				//Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;

				char guess; //letter he or she guesses.

				cout << "\nRecruit " << login << endl;
				cout << "Enter your guess: ";
				//Get recruit ’s guess
				cin >> guess;

				guess = toupper(guess); //make uppercase since secret word in uppercase.

				//While recruit has entered a letter that he or she has already guessed
				while (used.find(guess) != string::npos)
				{
					//Displays that he or she has used the guess already.
					system("cls");
					cout << "#################################################" << endl;
					cout << "Sorry" << login << ", you've already guessed " << guess << "." << endl;
					cout << "#################################################" << endl;
					//Tell recruit how many incorrect guesses he or she has left
					cout << "\n\nRecruit " << login << " you have " << (MAX_WRONG - wrong);
					cout << " incorrect guesses left.\n";
					//Show recruit the letters he or she has guessed
					cout << "\nYou've used the following letters:\n" << used << endl;
					//Show player how much of the secret word he or she has guessed
					cout << "\nSo far, the word is:\n" << soFar << endl;

					cout << "Enter your guess: ";
					//Get recruit's next guess
					cin >> guess;
					guess = toupper(guess); //make uppercase since secret word in uppercase.
				}
				used += guess; // adds the guessed letter to used.
				//If the guess is in the secret word
				if (THE_WORD.find(guess) != string::npos)
				{
					//Tell the recruit the guess is correct
					system("cls");
					cout << "#################################################" << endl;
					cout << "That's right " << login << ", " << guess << " is in the word.\n";
					
					//update soFar to include newly guessed letter
					//Add the new guess to the group of used letters
					for (int i = 0; i < THE_WORD.length(); ++i)
					{
						//Update the word guessed so far with the new letter
						if (THE_WORD[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				//Tell the recruit the guess is incorrect
				else
				{
					system("cls");
					cout << "#################################################" << endl;
					cout << "Sorry " << login << ", " << guess << " isn't in the word.\n";
					++wrong;
				}
			}

			//shut down
			//If the recruit has made too many incorrect guesses
			if (wrong == MAX_WRONG)
			{
				//Tell the recruit that he or she has failed the Keywords II course.
				system("cls");
				cout << "#################################################" << endl;
				//Tell recruit how many incorrect guesses he or she has left
				cout << "\n\nRecruit " << login << " you have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				//Show recruit the letters he or she has guessed
				cout << "\nYou've used the following letters:\n" << used << endl;
				//Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;
				cout << "\nRecruit " << login << " you've been hanged!" << endl;
				++fails;
			}
			else if (wrong == 0)
			{
				system("cls");
				cout << "#################################################" << endl;
				//Tell recruit how many incorrect guesses he or she has left
				cout << "\n\nRecruit " << login << " you have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				//Show recruit the letters he or she has guessed
				cout << "\nYou've used the following letters:\n" << used << endl;
				//Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;
				cout << "#################################################" << endl;
				cout << "\nPERFECT SCORE!!!" << endl;
				cout << "\nRecruit " << login << " you guessed it!" << endl;
				++wins;
			}
			else
			{
				//Congratulate the recruit on guessing the secret words
				system("cls");
				cout << "#################################################" << endl;
				//Tell recruit how many incorrect guesses he or she has left
				cout << "\n\nRecruit " << login << " you have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				//Show recruit the letters he or she has guessed
				cout << "\nYou've used the following letters:\n" << used << endl;
				//Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;
				cout << "\nRecruit " << login << " you guessed it!" << endl;
				++wins;
			}
			system("cls");
			cout << "#################################################" << endl;
			cout << "\nThe word was " << THE_WORD << "\n";
		}

		cout << "\n\nRecruit " << login << " has failed " << fails << " times." << endl;
		cout << "\nCorrectly guessing " << wins << "." << endl;
		//Ask the recruit if they would like to run the simulation again
		cout << "\nRerun simulation?" << endl;
		cin >> again;
		//Increment the number of simiulations ran counter
		++s;
	} while (again != 'n'); //If the recruit wants to run the simulation again

	//Display End of Simulations to the recruit
	cout << "Shutdown Sequence Initiated...\n" << endl;

	//Pause the Simulation with press any key to continue
	system("pause");

    return 0;
}
//Move program execution back up to // Display the simulation # is staring to the recruit. 



