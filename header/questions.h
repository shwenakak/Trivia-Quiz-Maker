#ifndef __QUESTIONS_HPP__
#define __QUESTIONS_HPP__

#include <string>

using namespace std;

class Questions {
	public:
		// the param will be the current question to display
		virtual string DisplayQuestion() const = 0;

		// if user has won the game, return true
		// the param will be user input and correct answer which we want to check 
		virtual bool CheckAnswer(string, string) const = 0;
};

#endif // __QUESTIONS_HPP__
