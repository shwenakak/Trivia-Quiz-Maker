#ifndef __QUIZ_HPP__
#define __QUIZ_HPP__

#include "questions.h"

#include <string>
#include <vector>

class Questions; // forward declaration of Questions class

using namespace std;

class Quiz {
	private:
		string topic;
		string type;
		
		//holds all questions and answers
		vector<Questions*> game_questions;
		
		void LoadQuestions(string, string); //fils vectors
	public:
		~Quiz();
		void PickTopic(); // which topic will user choose: Music, Sports, or Science
		void QType(); // which questions does user want: T/F, MC, FillinBlank
		//TODO

		bool RunGame();
};

#endif //__QUIZ_HPP__ 
