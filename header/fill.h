#ifndef __FILL_HPP__
#define __FILL_HPP__

#include "questions.h"

#include <string>
#include <vector>

using namespace std;

class Fill : public Questions {
	public:
		Fill() {} 

		virtual string DisplayQuestion(string) const;
		virtual bool CheckAnswer(string, string) const;
			
};

#endif // __FILL_HPP__
