#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "game_question.hpp"

#include <string>
#include <vector>

class GameQuestion; // forward declaration of GameQuestion class

using namespace std;

class Game {
	private:
		string topic; // what topic does user want: Sports, Science, or Music
		// holds all questions and answers
		//vector<string> all_q;
		//vector<string> all_a;
			
		// holds all the objects of questions for the current game
		vector<GameQuestion*> questions;
		// holds the correct answers for each question in above vector
		vector<string> answers;
		Type* type = nullptr;
	
		//void LoadQuestions(string, string); // fill vectors with questions according to uswer topic anf type
	public:
		Game() { }
		~Game() {
			delete type;
			for (int i = 0; i < questions.size(); i++)
				delete questions.at(i);
		}
		void SetStrategy(Type*);
		void AddQuestion(GameQuestion*);
		void PopulateAnswers();
		void print(GameQuestion*);
		
		string PickTopic(); // which topic will user choose: Music, Sports, or Science
		bool LoadQuestions(string, string) // fill vectors with questions according to user topic
		//void QType(); // which questions does user want: T/F, MC, FillinBlank
		
		bool RunGame(); // this will play the game
};

#endif // __GAME_HPP__
