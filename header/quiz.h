#ifndef __QUIZ_HPP__
#define __QUIZ_HPP__

#include "questions.h"

#include <string>
#include <vector>

// may need to forward declare Questions class like in lab5

using namespace std;

class Quiz {
	private:
		string topic;
		string type;
		Questions* question = nullptr; // reference to Questions class; composite component

		vector<string> MusicQ;
		vector<string> ScienceQ;
		vector<string> SportsQ;

	public:
		~Quiz();
		void LoadQuestions(string); // fill vectors with questions according to user topic
		void SetType(string); // param is what type of questions user wants
		void PickTopic(); // which topic will user choose: Music, Sports, or Science
		void QType(); // which questions does user want: T/F, MC, FillinBlank
		// TODO
		bool RunGame(); // this will play the game
};

#endif // __QUIZ_HPP__
