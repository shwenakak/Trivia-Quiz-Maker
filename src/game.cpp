#include "../header/game.hpp"
#include "../header/game_question.hpp"
#include "fill.cpp"

#include <string>
#include <iostream>
#include <algorithm> // need this to manually convert user inputs to lowercase and see if elemenet is already in a vector
#include <fstream>
// these 2 libs are for rand and srand functions
#include <time.h>
#include <stdlib.h>

using namespace std;

void Game::SetStrategy(Type* new_strategy) {
	delete type;
	type = new_strategy;
}

void Game::AddQuestion(GameQuestion* gq) {
	questions.push_back(gq);
}

// composite pattern
void Game::PopulateAnswers() {
	for (int i = 0; i < questions.size(); i++) {
		answers.push_back(questions.at(i)->GetAnswer()); //will call GetAnswer() on each question object, which will call GetNaswer() on each option object in question object vector of options 
	}
}

void Game::print(GameQuestion* gq) {
	type->Display(gq);
}

// params: t = topic
// 	   y = type
bool Game::LoadQuestions(string t, string y) {
	ifstream qFile; // use this to go through questions file and upload questions
	ifstream aFile; // use this to go through answers file and upload answers
	string question;
	string answer;
	
	vector<int> nums; // nums of whcih questions are already in game_question vector

	// specify path to file from directory where executbale is called
	qFile.open("notes/" + t + "_" + y + ".txt");
	aFile.open("notes/" + t + "_answers_" + y + ".txt");
	
	if (!qFile.is_open()) {
		cout << "QUESTIONS FILE NOT OPEN" << endl;
		exit(1);
	}
	if (!aFile.is_open()) {
		cout << "ANSWERS FILE NOT OPEN" << endl;
		exit(1);
	}
	
	// count total lines and popuylate vectors with all questions and answers
	int totalLines = 0;
	while(getline(qFile, question) && getline(aFile, answer)) {
		totalLines++;
		all_q.push_back(question);
		all_a.push_back(answer);
	}

	srand(time(0));
	int randNum = 0;
	while (nums.size() != 2) {	
		randNum = rand() % totalLines;
		cout << randNum;
		// add it to vector only if not found
		if (find(nums.begin(), nums.end(), randNum) == nums.end())
			nums.push_back(randNum);
	}
	
	// populate game questoins and answers with random questions by generating random number between 0 and totalLines
	srand(time(0));
	for (int i = 0; i < nums.size(); i++) { 
		questions.push_back(new GameQuestion(all_q.at(nums.at(i)), randNum);
	}

	cout << "-----------------------------------------------------------------------------" << endl;	
	for (int i = 0; i < game_questions.size(); i++) {
		cout << "\t" << questions.at(i)->DisplayQuestion() << endl;
	}

	qFile.close();
	aFile.close();
	nums.clear();
}

string Game::PickTopic() {
	string topic;
	while (topic != "music" || topic != "sports" || topic != "science") {
		// weirdly it doesn't break out of loop without this if statement...
		if (topic == "music" || topic == "sports" || topic == "science") {
			return topic;
		}
		cout << "TOPIC: " << topic << endl;
		cout << "What topic would you like to test you knowledge in?" << endl;
		cout << "Music, Sports, or Science" << endl;
		cin >> topic; // store user chouce in instance variable as undercase for safety	
		//topic = "sports";
		transform(topic.begin(), topic.end(), topic.begin(), ::tolower);		
	}
}
/*
void Game::QType() {
	while (type != "tf" || type != "mc" || type != "fill") {
		if (type == "tf" || type == "mc" || type == "fill") 
			break;
		cout << "What kind of questions would you like?" << endl;
		cout << "TF, MC, or Fill" << endl;
		cin >> type; // store user choice in instance variable as undercase for safety
	
		// params: beginnigng of word, end of word, beginning of word we want to store result inm what we want to do	
		transform(type.begin(), type.end(), type.begin(), ::tolower);	
		
		cout << "QTYPE: " << type << endl;
	}
	
	LoadQuestions(topic, type); // load questions about user topic and type
}
*/
// TODO
//bool RunGame() {
//	int score = 0;
	// display question based on user's topic
//	for (int i = 0; i < game_questions.size(); i++) {
//		string user_input = question->DisplayQuestion(game_questions.at(i));
	
	//	if (question->CheckAnswer(user_input, game_answers.at(i)))
	//		score++;
//	}
//
//	// if all questions are asked, end the game and clear the vectors 
//	if (score == 5) {
//		// end game
//		game_questions.clear();
//		game_answers.clear();
//	}
//}
