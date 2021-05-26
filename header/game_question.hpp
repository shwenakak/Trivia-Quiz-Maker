#ifndef __GAMEQUESTION_HPP__
#define __GAMEQUESTION_HPP__

#include <string>
#include <iostream>

using namespace std;

class GameQuestion {
	protected:
		int totalPoints; // how many points all questions are worth together
		int qPoints; // how much each question is worth
		int score; // user score
	public:
		virtual GameQuestion(string, int) = default;
		virtual GameQuestion(string, bool) = default;
		virtual ~GameQuestion() = default;
		virtual string GetAnswer() const = 0;
};


#endif // __GAMEQUESTION_HPP__
