#ifndef __FILL_HPP__
#define __FILL_HPP__

#include "questions.h"

#include <string>
#include <vector>

using namespace std;

class Fill : public Questions {
	private:
		string question;
		string answer;

	public:
		Fill(string question, string answer) {
			this->question = question;
			this->answer = answer;
		}

		virtual string DisplayQuestion() const;
		virtual bool CheckAnswer(string, string) const;
			
};

#endif // __FILL_HPP__
