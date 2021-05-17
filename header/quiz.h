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

		// holds all questions and answers
		vector<string> all_q;
		vector<string> all_a;
			
		// holds all the questions for the current game
		vector<string> game_questions;
		// holds all the questions for the current game
		vector<string> game_answers;
		
	public:
		~Quiz();
		void LoadQuestions(string, string); // fill vectors with questions according to user topic and type
		bool SetType(string); // param is what type of questions user wants
		void PickTopic(); // which topic will user choose: Music, Sports, or Science
		void QType(); // which questions does user want: T/F, MC, FillinBlank
		
		// TODO
		// in this function, we will loop through the two instance var vectors and 
		// call the functions for each entry in the vector
		bool RunGame(); // this will play the game
};

#endif // __QUIZ_HPP__
