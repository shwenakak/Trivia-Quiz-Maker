#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "game_question.hpp"

#include <string>
#include <vector>

class GameQuestion; // forward declaration of GameQuestion class

using namespace std;

class Game {
	private:
		// holds all questions and answers
		//vector<string> all_q;
		//vector<string> all_a;
			
		// holds all the objects of questions for the current game
		vector<GameQuestion*> questions;
		Type* type = nullptr;
	
		//void LoadQuestions(string, string); // fill vectors with questions according to uswer topic anf type
	public:
		~Game() {
			delete type;
			for (int i = 0; i < questions.size(); i++)
				delete questions.at(i);
		}
		//void PickTopic(); // which topic will user choose: Music, Sports, or Science
		//void QType(); // which questions does user want: T/F, MC, FillinBlank
		
		// TODO
		// in this function, we will loop through the two instance var vectors and 
		// call the functions for each entry in the vector
		//bool RunGame(); // this will play the game
};

#endif // __GAME_HPP__
