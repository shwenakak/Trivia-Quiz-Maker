#ifndef __QUESTIONS_HPP__
#define __QUESTIONS_HPP__

#include <string>

using namespace std;

class GameQuestion;

class Questions {
	public:
		virtual Type() = default;
		// the param will be the current question object to display
		virtual void DisplayQuestion(GameQuestion*) const = 0;
};

#endif // __QUESTIONS_HPP__
