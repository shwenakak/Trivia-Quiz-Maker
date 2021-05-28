#ifndef __OPTION_HPP__
#define __OPTION_HPP__

#include "game_question.hpp"

#include <string>
#include <iostream>

using namespace std;

class Option : public GameQuestion {
	private:
		string option;
		bool isCorrect;

	public:
		Option(string o, bool c) : GameQuestion(), option(o), isCorrect(c) { }

		virtual string GetAnswer() const { return "dummy"; }
		virtual string GetQuestion() const { return "dont need this function in this class"; }
		virtual int HowManyOptions() const { return -69; }
		virtual void AddOption(GameQuestion* gq) { cout << "OPTION CLASS" << endl; }
		virtual vector<GameQuestion*> AllOptions() { }
		virtual string GetSingleOption() { return option; }
		
};

#endif // __OPTION_HPP__
