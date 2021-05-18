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

		// holds all questions and answers
		vector<string> all_q;
		vector<string> all_a;
			
		// holds all the objects of questions for the current game
		vector<Questions*> game_questions;
	
		void LoadQuestions(string, string); // fill vectors with questions according to uswer topic anf type
	public:
		~Quiz();
		void PickTopic(); // which topic will user choose: Music, Sports, or Science
		void QType(); // which questions does user want: T/F, MC, FillinBlank
		
		// TODO
		// in this function, we will loop through the two instance var vectors and 
		// call the functions for each entry in the vector
		bool RunGame(); // this will play the game
};

#endif // __QUIZ_HPP__
