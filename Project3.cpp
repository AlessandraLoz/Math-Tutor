#include <iomanip>
#include "MathOperations.h"
#include "MathReport.h"
#include <iostream>
#include <string>



using namespace std; 
 
int main()
{
	//declaring/initializing variables and objects used 
	bool stop = false;
	bool Quit = false;
	int MenuChoice = 0;
	int num1;
	int num2; 
	int StuAnswer;
	int tracker = 0;
	string practice; 
	MathReport ListItem;
	MathOperations Question;

	//while loop to repeatedly display menu options for user until user chooses to quit problem
	while (!stop)
	{
		//output for user menu
		cout << "Math is fun! Take a challenge..." << endl;
		cout << "-------------------------------- " << endl;
		cout << "1. Addition problem " << endl;
		cout << "2. Subtraction problem " << endl;
		cout << "3. Multiplication problem " << endl;
		cout << "4. Division problem " << endl;
		cout << "5. Quit problem " << endl;
		cout << "-------------------------------- " << endl;

		//output directions for input 
		cout << "Enter your choice (1-5): ";
		//stores user input in variable MenuChoice
		cin >> MenuChoice;
		cin.ignore(256, '\n');
		cout << endl;

		//if else that evaluates menu options and executes respective code
		if (cin.fail())
		{
			//output for when the input is not a number 
			cin.clear();
			cin.ignore();
			cout << "Invalid choice!"<< endl;

		}
		else if (MenuChoice == 5)
		{
			//ends while loop
			stop == true;
			break;
		}
		else if(MenuChoice < 1 || MenuChoice > 5)
		{
			//output for when input is out of range
			cin.clear();
			cin.ignore();
			cout << "Invalid choice! The valid choices are 1,2,3,4, and 5." << endl;
		}
		else
		{
			// Seed the random number generator.
			srand(time(NULL)); 
			//creates random numbers from 1- 500 to be used as operators
			num1 = 1 + (rand() % 500);
			num2 = 1 + (rand() % 500);
			//sets operators equal to random numbers generated
			Question.setOperands(num1, num2);

			if (MenuChoice == 1)
			{	
				Question.Addition();
				
			}
			else if (MenuChoice == 2)
			{
				//checks whether num1 is greater than num1 and switches the placement of the operators if it is
				if (num2 > num1)
				{
					//sets operators equal to random numbers generated 
					Question.setOperands(num2, num1);
				}
				else
				{
					//sets operators equal to random numbers generated

					Question.setOperands(num1, num2);
				}
				//calls subtraction function 
				Question.Subtraction();
			}
			else if (MenuChoice == 3)
			{
				//creates random numbers in respective range to be used as operators
				num1 = 11 + (rand() % 88);
				num2 = 2 + (rand() % 7);
				//sets operators equal to random numbers generated 
				Question.setOperands(num1, num2);
				//calls Multiplication function 
				Question.Multiplication();
			}
			else if (MenuChoice == 4)
			{
				//creates random numbers in respective range to be used as operators
				num1 = 2 + (rand() % 96);
				num2 = 2 + (rand() % 7);
				//to ensure num1 is divisible by num2 we multiply them 
				num1 = num1 * num2; 
				//sets operators equal to random numbers generated 
				Question.setOperands(num1, num2);
				// calls Multiplication function
				Question.Division();
			}
		
			//sets variable StuAnswer equal to answer from collectUserAnswer
			StuAnswer = Question.collectUserAnswer();
	
			//if else statement tgat evaluates whether the answer is right then displays respective output
			if (Question.checkAnswer(StuAnswer))
			{
				cout << "Congratulations! " << StuAnswer << " is the right answer." << endl;
			}
			else
			{
				cout << "Sorry, the answer is wrong. You may practice again." << endl;
			}

			//inserts new item into list 
			ListItem.insert(Question, StuAnswer);
			//Tracker variable to keep track of how many questions have been asked and is updated every while loop
			tracker = tracker + 1; 
		}

	}
	//if else statement which displays respective output depending on the number of correct answers
	if (tracker == 0) 
	{
		//output for when no questions were asked
		cout << "Thank you for using Math Tutor.";
	}
	else if (ListItem.getNumOfWrongAnswers() > 0)
	{
		//generates report without answers
		ListItem.generateReport(false);

		//while loop to keep asking whether or not they want to continue until Q is pressed or until they get all of them right
		while (!Quit && ListItem.getNumOfWrongAnswers() != 0)
		{
			//user instructions
			cout << "Do you want to practice the questions with wrong answers?" << endl << "(enter 'Q' or 'q' to quit) " << endl;	
			//gets input from user and stores it in practice variable
			getline(cin, practice);
			cin.ignore(256, '\n');
			//if statement that breaks loop
			if (practice == "Q" || practice == "q" )
			{
				Quit = true;
				break;
			}
			//calls need more practice function 
			ListItem.needMorePactice();

		}
		
			//generates report with all the answers shown
			ListItem.generateReport(true);
			cout << "Thank you for using MathTutor";

	}
	else 
	{
		//generates report with all the answers shown
		ListItem.generateReport(true);
		cout << "Thank you for using MathTutor";
	}

	//ends program
	return 0;
}