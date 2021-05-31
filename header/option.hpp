#ifndef __OPTION_HPP__
#define __OPTION_HPP__

#include "../header/GameQuestion.hpp"

#include <string>
#include <iostream>

using namespace std;

class Option : public GameQuestion {
	private:
		string option;
		bool isCorrect; 

  public:
	Option(string opt, bool corr) : GameQuestion(), option(opt), isCorrect(corr) { }

	bool CorrectAnswer() {
		return this->isCorrect;
         }

        virtual string GetAnswer() const { 
        if ( CorrectAnswer() ) {
        return this->option;
        }
         else{
           return "";
        }
       }
};
#endif
