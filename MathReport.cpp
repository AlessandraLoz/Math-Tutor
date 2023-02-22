#include "MathReport.h"
#include <iostream>

using namespace std;

//initializing private member functions
MathReport::MathReport()
{	
	//initializes member functions 
	numCorrectAnswers = 0;
	numWrongAnswers = 0;
}

void MathReport::insert(MathOperations newQuestion, int response)
{
	//adds element to vector
	mathQuestions.push_back(newQuestion);
	
	//if else to check whether the answer given is correct
	if (newQuestion.checkAnswer(response))
	{
		//updates number of correct answers by one
		numCorrectAnswers = numCorrectAnswers + 1 ;
	}
	else
	{	
		//adds question to List of questions users got wrong
		errorList.push_back(newQuestion);
		//updates number of wrong answers by one
		numWrongAnswers = numWrongAnswers + 1;
	}
}

int MathReport::getNumOfCorrectAnswers() const
{
	//returns number of correct answers
	return numCorrectAnswers;
}

int MathReport::getNumOfWrongAnswers() const
{
	//returns number of wrong answers
	return numWrongAnswers;
}

void MathReport::generateReport(bool showAnswer) const
{
	//outputs how many questions the user has answered
	cout << "You have solved the following " << mathQuestions.size() << " math problems : \n";

	//for loop that iterates over the vector of questions asked 
	for (int i = 0; i < mathQuestions.size(); i++)
	{
		cout << "Question " << i + 1 << ":" << endl;
		//prints question at that iteration
		mathQuestions[i].print();

		//if else statement that checks whether or not to show answer
		if (showAnswer)
		{
			//displays answer
			cout << mathQuestions[i].getAnswer() << endl;
		}
		else
		{
			//outputs new line
			cout << "\n";
		}
		
	}
	//output statements to match sample output
	cout << "---------------------------------- " << endl;
	cout << "You have answered " << numCorrectAnswers << " questions correctly\n";
	cout << "You made " << numWrongAnswers << " mistakes\n";

	//if else to chceck if they have any amount of wrong answers and outputs respective statements
	if (numWrongAnswers > 1)
	{
		cout << "You will do better next time ..." << endl;
	}
	else
	{
		cout << "Great Job!" << endl;
	}

}


bool MathReport::needMorePactice()
{
	//creating iterator for list
	list<MathOperations>::iterator it = errorList.begin();
	//variable to store user answer
	int studentAnswer;
	
	//while loop that runs through all elements in the list
	while (it != errorList.end())
	{
		//collects student answer using math operations function
		studentAnswer = (*it).collectUserAnswer();

		//if else statement that checks whether the answer was right
		if ((*it).checkAnswer(studentAnswer))
		{
			cout << "Congratulations!" << studentAnswer << " is the right answer." << endl;
			//updates number of wrong and correct answers
			numCorrectAnswers = numCorrectAnswers + 1;
			numWrongAnswers = numWrongAnswers - 1;
			//deletes element from error list 
			it = errorList.erase(it);

		}
		else
		{
			//outputs that the answers is incorrect
			cout << "Sorry the answer is wrong.You may practice again." << endl;
			//iterator is updated
			it++; 
		}

		
	}
	
	//if else statement that checks whether they answered all of the questions correctly with output respective to that evaluation
	if (errorList.empty())
	{
		cout << "Excellent, your answers are all correct!" << endl;
		//ends while loop
		return false;
	}
	else
	{
		cout << "You still need more practice!" << endl;
		//continues while loop
		return true;
	}
}
