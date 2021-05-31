#ifndef __OPTION_HPP__
#define __OPTION_HPP__

#include "GameQuestion.hpp"

#include <string>
#include <iostream>

using namespace std;

class Option : public GameQuestion {
	private:
		string option;
		bool isCorrect;

	public:
		Option(string o, bool c) : GameQuestion(), option(o), isCorrect(c) { }
		//~Option() { cout << endl << "OPTION DESTRUCTOR" << endl; }

		virtual string CorrectAnswer() const { return "need to implement isCorrect function, look at OMT"; }
		virtual string GetQuestion() const { return "dont need this function in this class"; }
		virtual int HowManyOptions() const { return -69; }
		virtual void AddOption(GameQuestion* gq) { cout << "OPTION CLASS" << endl; }
		virtual vector<GameQuestion*> AllOptions() { }
		virtual string GetSingleOption() { return option; }
	
		virtual int GetScore() const { return 1000000; } // not needed in this class
		virtual int GetTotalPoints() const { return 10000; } // not needed in this class
		virtual void UpdateUserScore(int) { }  // not needed in this class
		virtual int QPoints() { } // not needed in this class
		
};

#endif // __OPTION_HPP__
