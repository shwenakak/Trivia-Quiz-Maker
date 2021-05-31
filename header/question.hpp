#ifndef __QUESTION_HPP__
#define __QUESTION_HPP__

#include "../header/GameQuestion.hpp"

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
		Question(string quest, int n) : GameQuestion(),q(quest), num(n) {}
		virtual int GetScore() const (return score);
		virtual int GetTotalPoints() const return(totalPoints);
		virtual void AddOption(GameQuestion* opt)
		{
			options.push_back(opt);
		}
		virtual string GetAnswer() const
		{
			for(int i = 0; i < option.size(); i++)
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
};
#endif
