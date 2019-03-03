//Norman Nguyen
//2/28/19
//Program: Keywords II
#include<iostream> //IOStream
#include<algorithm> //Algorithm
#include<vector> //Vector
#include<string> //String
#include<ctime> //Ctime
#include<cctype> //CCtype
//Standard Library
using namespace std;
//Main Function
int main()
{
	string recruitName; //String Recruit Name
	//*****INFO ON WHAT THE PROGRAM*****
	cout << "Keywords II";
	cout << "\nUAT CSC215 C++ Course ";
	cout << "\nCoded by: Norman Nguyen ";
	cout << "\n\nEnter your recruit name: ";
	//*****INFO ON WHAT THE PROGRAM*****
	//Boolean
	bool playAgain = false;
	//Enter recruit name
	cin >> recruitName;

	system("title CIA KeywordsII");
	cout << "\n\nHello " << recruitName << endl;
	cout << "\nWelcome to CodeBreaker II. Good Luck Playing!\n";
	system("pause");
	const int MAX_WRONG = 8;
	int wordWrongs = 0;
	int wordsCorrrects = 0;
	vector <string> words;
	//Words
	words.push_back("SPY");
	words.push_back("INCOGNITO");
	words.push_back("INTEL");
	words.push_back("RECON");
	words.push_back("AGENTS");
	words.push_back("ANONYMOUS");
	words.push_back("CIA");
	words.push_back("SECRETS");
	words.push_back("ENCRYPTION");
	words.push_back("SECURITY");
	//Do loop
	do
	{
		//For loop that uses 3 random words
		for (int i = 0; i < 3; ++i)
		{
			srand(static_cast<unsigned int> (time(0)));
			//Shuffle the words listed on top.
			random_shuffle(words.begin(), words.end());
			//Guess Words
			const string THE_WORD = words[0];
			int wrong = 0; //Wrong words if the word is incorrect
			string soFar(THE_WORD.size(), '-');
			string used = "";

			//main loop
			while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
			{
				//Shows how many incorrect guesses left
				cout << "\n\nYou have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				//List the letters you've used.
				cout << "\nYou've used the following letters:\n" << used << endl;
				cout << "\nSo far, the words is:\n" << soFar << endl;
				//Character
				char guess;
				//Message to enter your guess
				cout << "\n\nEnter your guess:";
				//Type in your guess
				cin >> guess;
				//Toupper helps to make lower case letters to uppercase.
				guess = toupper(guess);
				while (used.find(guess) != string::npos)
				{
					//You already guessed message
					cout << "\nYou've already guessed " << guess << endl;
					//Enter the guess
					cout << "\n\nEnter your guess:";
					cin >> guess;
					//Toupper
					guess = toupper(guess);
				}
				//Words that are used won't be given again
				used += guess;
				if (THE_WORD.find(guess) != string::npos)
				{
					//Letter is correct
					cout << "Correct! " << "'" << guess << "'" << " is the word.\n";
					for (unsigned int i = 0; i < THE_WORD.length(); ++i)
					{
						if (THE_WORD[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				//Else saying that you got the word wrong
				else
				{
					cout << "Sorry, " << "'" << guess << "'" << " isn't in the word.\n";
					++wrong;
				}
			}
			//If you missed to the max limit, you're given to move to the next word
			if (wrong == MAX_WRONG)
			{
				cout << "\nUnfortunately, due to reaching its limit, you're immedietely let go.";
				//Add if you've an incorrect word.
				++wordWrongs;
			}
			//See if you got it right on the right word.
			else
			{
				cout << "\nYou got it right!";
				cout << "\nThe secret word is " << THE_WORD << endl;
				//Add if you got a corrected word.
				++wordsCorrrects;;
			}
		}
		cout << "\n\nYou got " << wordWrongs << " Wrongs"; //Number of Wrongs
		cout << "\nYou got " << wordsCorrrects << " Corrects"; //Number of Corrected Words.
		cout << "\nWould you like to r un the simulation again? (Y/N): ";
		//String player choice
		string playerChoice;
		//Enter your choice of yes or no.
		cin >> playerChoice;
		//Yes
		if (playerChoice == "y" || playerChoice == "Y")
		{
			playAgain = true;
			wordsCorrrects = 0;
			wordWrongs = 0;
		}
		//No
		else if (playerChoice == "n" || playerChoice == "N")
		{
			//Allow simulation to finish
			cout << "Simulation Ended, proceed to exit." << endl;
			system("pause");
		}
	} while (playAgain == true);
	return 0;
}