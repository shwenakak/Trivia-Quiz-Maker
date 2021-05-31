#ifndef __QUESTION_HPP__
#define __QUESTION_HPP__

#include "GameQuestion.hpp"

#include <string>
#include <iostream>

using namespace std;

class Question : public GameQuestion 
{
	private:
		string q;
		int num;
		vector<GameQuestion*> options; 

	public:
		Question(string quest, int n) : GameQuestion(), q(quest), num(n) {
			qPoints = n;
			totalPoints += n;
		}
		~Question() {
			for (int i = 0; i < options.size(); i++) {
				delete options.at(i);
			}
		}
		virtual int GetScore() const { return score; }
		virtual int GetTotalPoints() const { return totalPoints; }
		virtual void AddOption(GameQuestion* opt)
		{
			options.push_back(opt);
		}
		virtual bool CorrectAnswer() { return true; }
		virtual string GetAnswer() const
		{
			for(int i = 0; i < options.size(); i++)
			{
				if(options.at(i) -> CorrectAnswer())
				{
					return options.at(i) -> GetAnswer();
				}
				else
				{
					return "";
				}
			}
		}
		virtual int HowManyOptions() const { return options.size(); }
		virtual void UpdateUserScore(int add) { score += add; }
		virtual int QPoints() { return qPoints; }
		virtual string GetQuestion() const { return q; }
		virtual vector<GameQuestion*> AllOptions() { return options; }
		virtual vector<GameQuesiton*> GetOptions() { }
		virtual string GetSingleOption() { return "dont need in this class. need in Option class"; }
};

#endif
