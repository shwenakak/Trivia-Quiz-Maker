#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "type.hpp"
//#include "game_question.hpp"
#include "question.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <stdlib.h>

class Type; // forward declaration of Type class

using namespace std;

class Game {
	private:
		//string topic; // what topic does user want: Sports, Science, or Music
		// holds all questions and answers
		//vector<string> all_q;
		//vector<string> all_a;
			
		// holds all the objects of questions for the current game
		vector<GameQuestion*> questions;
		// holds the correct answers for each question in above vector
		vector<string> answers;
		Type* type = nullptr;

		void LoadFillQuestions(string topic) {
			ifstream qFile; // use this to go thorugh questions file
			ifstream aFile; // use this to go thorugh questions file
			string question;
			string answer;

			vector<int> nums; // nums of which questions are already in the questions vector

			vector<string> all_q;
			vector<string> all_a;

			// specify path to file from directory where executable is called
			qFile.open("notes/" + topic + "_fill.txt");
			aFile.open("notes/" + topic + "_answers_fill.txt");

			if (!qFile.is_open()) {
				cout << topic << " FILL QUESTIONS FILE NOT OPEN" << endl;
				exit(1);
			}
			if (!aFile.is_open()) {
				cout << topic << " FILL ANSWERS FILE NOT OPEN" << endl;
				exit(1);
			}


			// count total lines and ppulate vectors with all questions and answers
			int totalLines = 0;
			while (getline(qFile, question) && getline(aFile,answer)) {
				totalLines++;
				all_q.push_back(question);
				all_a.push_back(answer);
			}
			
			srand(time(0));
			int randNum = 0;
			while (nums.size() != 2) {
				randNum = rand() % totalLines;
				// add it to vector only if not found
				if (find(nums.begin(), nums.end(), randNum) == nums.end())
					nums.push_back(randNum);
			}
																		srand(time(0));
			for (int i = 0; i < nums.size(); i++) {
				questions.push_back(new Question(all_q.at(nums.at(i)), 5));
			}
																		for (int i = 0; i < questions.size(); i++)
				print(questions.at(i));
																		qFile.close();
			aFile.close();
			nums.clear();
		}
		void LoadTFQuestions();
		void LoadMCQuestion();
	
		//void LoadQuestions(string, string); // fill vectors with questions according to uswer topic anf type
	public:
		Game() {}
		~Game() {
			if (type != nullptr)
				delete type;
			for (int i = 0; i < questions.size(); i++)
				delete questions.at(i);
		}
		void SetStrategy(Type* new_strategy) {
			delete type;
			type = new_strategy;
		}
		void AddQuestion(GameQuestion* gq) {
			questions.push_back(gq);
		}
		void PopulateAnswers() { 
			for (int i = 0; i < questions.size(); i++)
				answers.push_back(questions.at(i)->GetAnswer());
		}
		void print(GameQuestion* gq) {
			type->Display(gq);
		}
		// which topic will user choose: Music, Sports, or Scinec
		string PickTopic() {
			string topic;
			while (topic != "music" || topic != "sports" || topic != "science") {
				// doesnt work without it
				if (topic == "music" || topic == "sports" || topic == "science") {
					return topic;
				}
				cout << "TOPIC: " << topic << endl;
				cout << "What topic would you like to test your knowledge in?" << endl;
				cout << "Music, Sports, or Science" << endl;
				//cin >> topic;
				topic = "SpoRTs";
				transform(topic.begin(), topic.end(), topic.begin(), ::tolower);
			}
		}
		// fill vectors with questions according to user topic
		bool LoadQuestions(string t, string y) {
			ifstream qFile; // use this to go through questions file
			ifstream aFile; // use this to go thorugh answers file
			string question;
			string answer;
			
			vector<int> nums; // nums of which questions are alreafy in the questions vector

			vector<string> all_q;
			vector<string> all_a;

			// specifiy path to file from directory where executbale is called
			qFile.open("notes/" + t + "_" + y +".txt");
			aFile.open("notes/" + t + "_answers_" + y +".txt");

			if (!qFile.is_open()) {
				cout << "QUESTIONS FILE NOT OPEN" << endl;
				exit(1);
			}
			if (!aFile.is_open()) {
				cout << "ANSWERS FILE NOT OPEN" << endl;
				exit(1);
			}

			// count total lines and ppulate vectors with all questions and answers
			int totalLines = 0;
			while (getline(qFile, question) && getline(aFile,answer)) {
				totalLines++;
				all_q.push_back(question);
				all_a.push_back(answer);
			}

			srand(time(0));
			int randNum = 0;
			while (nums.size() != 2) {
				randNum = rand() % totalLines;
				// add it to vector only if not found
				if (find(nums.begin(), nums.end(), randNum) == nums.end())
					nums.push_back(randNum);
			}

			srand(time(0));
			for (int i = 0; i < nums.size(); i++) {
				questions.push_back(new Question(all_q.at(nums.at(i)), 5));
			}

			for (int i = 0; i < questions.size(); i++)
				print(questions.at(i));

			qFile.close();
			aFile.close();
			nums.clear();
		}
		//void QType(); // which questions does user want: T/F, MC, FillinBlank
		
		//bool RunGame(); // this will play the game
};

#endif // __GAME_HPP__
