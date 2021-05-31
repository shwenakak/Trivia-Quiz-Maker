#ifndef __QUESTION_HPP__
#define __QUESTION_HPP__

#include "GameQuestion.hpp"

#include <string>
#include <vector>

using namespace std;

class Question : public GameQuestion {
	private:
		string q; // what is the question
		int p; // how much is that question worth
		vector<GameQuestion*> options; // list of options for each question
		int hint = 1; // one hint for rn, can change later
	public:
		Question(string question, int points) : GameQuestion(), q(question), p(points) {
			qPoints = points; 
			totalPoints += points;
		}
		~Question() {
			for (int i = 0; i < options.size(); i++)
				delete options.at(i);
			options.clear();
		}
		
		// TODO
		virtual string CorrectAnswer() const {
			return "happy";
		}
		virtual int GetScore() const { return score; }
		virtual int GetTotalPoints() const { return totalPoints; }
		virtual void UpdateUserScore(int add) {
			score += add;
		}
		virtual int QPoints() { 
			//cout << "THIS QUESTION WORTH: " << qPoints << endl;
			return qPoints; }

		virtual string GetQuestion() const { return q; }

		virtual int HowManyOptions() const { return options.size(); }

		virtual void AddOption(GameQuestion* op) { options.push_back(op); }
		virtual vector<GameQuestion*> AllOptions() { return options; }
		virtual string GetSingleOption() { return "dont need in this class. need in Option class"; }
};



#endif // __QUESTION_HPP__
