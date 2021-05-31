#ifndef __QUESTION_HPP__
#define __QUESTION_HPP__

#include "../header/Game_Question.hpp"

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
		int GetScore() = 0;
		int GetTotalPoints() = 0;
		void AddOption(GameQuestion* opt)
		{
			options.push_back(opt);
		}
		vitual string GetAnswer() const
		{
			for(int i = 0; i < option.size(); i++)
			{
				if(option.at(i) -> CorrectAnswer())
				{
					return option.at(i) -> GetAnswer();
				}
			
				else
				{
					return "";
				}
			}
		}	
};
#endif
