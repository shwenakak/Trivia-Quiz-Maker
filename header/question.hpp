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
		vector<GameQuestion*> options; 

	public:
		Option(string quest, vector<GameQuestion*>o) : GameQuestion(),q(quest), vector<GameQuestion*> o(options) {}
		int GetScore() = 0;
		int GetTotalPoints() = 0;
		void AddOption(GameQuestion*)
		{
			options.push_back(GameQuestions*);
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
					NULL;
				}
			}
		}	
}
#endif
