#ifndef __GAMEQUESTION_HPP__
#define __GAMEQUESTION_HPP__

//#include "type.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//class Type;

class GameQuestion {
	protected:
		int totalPoints; // how many points all questions are worth together
		int qPoints; // how much each question is worth
		int score; // user score
	public:
		//GameQuestion(string, int);
		//GameQuestion(string, bool);
		//virtual ~GameQuestion();
		virtual string GetAnswer() const = 0;

		virtual string GetQuestion() const { return "garbage. need this for Question class"; }
		// implement in Option class so we can use it in Display(GameQuestion*) function in Type derived classes
		//virtual vector<GameQuestion*> GetOptions() const = 0;
};


#endif // __GAMEQUESTION_HPP__
