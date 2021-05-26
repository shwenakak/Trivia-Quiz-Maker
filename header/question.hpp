#ifndef __QUESTION_HPP__
#define __QUESTION_HPP__

#include "game_question.hpp"

#include <string>
#include <vector>

using namespace std;

class Question : public GameQuestion {
	private:
		string q; // what is the question
		vector<GameQuestion*> options; // list of options for each question
		int hint = 1; // one hint for rn, can change later
	public:
		Question(string, int);
		~Question() {
			for (int i = 0; i < options.size(); i++)
				delete options.at(i);
		}
		int GetScore() { return score } // protected var in parent class
		int GetTotalPoints() { return totalPoints; } // protected var in parent class
		void UseHint(); // protected var hint--
		void AddOption(GameQuestion* op) { options.push_back(op); }
		virtual string GetAnswer() const;
};



#endif // __QUESTION_HPP__
