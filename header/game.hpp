#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "type.hpp"
//#include "game_question.hpp"
#include "question.hpp"
#include "option.hpp"

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
		// holds all the objects of questions for the current game
		vector<GameQuestion*> questions;
		// holds the correct answers for each question in above vector
		vector<string> answers;
		// holds bool values of if the question hasbeen printed or not
		vector<bool> printed;
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
				printed.push_back(false);
			}
/*			
			for (int i = 0; i < questions.size(); i++) {
				if (printed.at(i) == false) {
					print(questions.at(i));
					printed.at(i) = true;
				}
			}
			cout << endl;
*/			
			qFile.close();
			aFile.close();
			nums.clear();
		}
		
		void LoadTFQuestions(string topic) {
			ifstream qFile; // use this to go thorugh questions file
			ifstream aFile; // use this to go thorugh questions file
			string question;
			string answer;

			vector<int> nums; // nums of which questions are already in the questions vector

			vector<string> all_q;
			vector<string> all_a;

			// specify path to file from directory where executable is called
			qFile.open("notes/" + topic + "_tf.txt");
			aFile.open("notes/" + topic + "_answers_tf.txt");
			
			if (!qFile.is_open()) {
				cout << topic << " TF QUESTIONS FILE NOT OPEN" << endl;
				exit(1);
			}
			if (!aFile.is_open()) {
				cout << topic << " TF ANSWERS FILE NOT OPEN" << endl;
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
				GameQuestion* new_q = new Question(all_q.at(nums.at(i)), 3);
				new_q->AddOption(new Option("true", true));
				new_q->AddOption(new Option("false", false));
				questions.push_back(new_q);
				printed.push_back(false);
			}
	/*		
			for (int i = 0; i < questions.size(); i++) {
				if (printed.at(i) == false) {
					print(questions.at(i));
					printed.at(i) = true;
				}
			}
			cout << endl;			
*/
			qFile.close();
			aFile.close();
			nums.clear();
		}
		
		void LoadMCQuestions(string topic) {
			ifstream qFile; // use this to go thorugh questions file
			ifstream aFile; // use this to go thorugh questions file
			string question;
			string answer;

			vector<int> nums; // nums of which questions are already in the questions vector

			vector<string> all_q;
			vector<string> all_a;

			// specify path to file from directory where executable is called
			qFile.open("notes/" + topic + "_mc.txt");
			aFile.open("notes/" + topic + "_answers_mc.txt");
			
			if (!qFile.is_open()) {
				cout << topic << " MC QUESTIONS FILE NOT OPEN" << endl;
				exit(1);
			}
			if (!aFile.is_open()) {
				cout << topic << " MC ANSWERS FILE NOT OPEN" << endl;
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
				GameQuestion* new_q = new Question(all_q.at(nums.at(i)), 4);
				new_q->AddOption(new Option("1", false));
				new_q->AddOption(new Option("2", false));
				new_q->AddOption(new Option("3", false));
				new_q->AddOption(new Option("4", true));
				questions.push_back(new_q);
				printed.push_back(false);
			}
		/*	
			for (int i = 0; i < questions.size(); i++) {
				if (printed.at(i) == false) {
					print(questions.at(i));
					printed.at(i) = true;
				}
			}
			cout << endl;
		*/	
			qFile.close();
			aFile.close();
			nums.clear();
		}
	
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
/*		void AddQuestion(GameQuestion* gq) {
			questions.push_back(gq);
		}*/
		void PopulateAnswers() { 
			for (int i = 0; i < questions.size(); i++)
				answers.push_back(questions.at(i)->GetAnswer());
		}
		void print(GameQuestion* gq) {
			cout << "NUM OPTIONS: " << gq->HowManyOptions() << endl;
			type->Display(gq); /*
			for (int i = 0; i < questions.size(); i++) {
				if (printed.at(i) == false) {
					type->Display(questions.at(i));
					printed.at(i) = true;
                                }
                        } */
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
		void LoadQuestions(string t, string y) {
			if (y == "fill")
				LoadFillQuestions(t);
			else if (y == "tf")
				LoadTFQuestions(t);
			else if (y == "mc")
				LoadMCQuestions(t);
		}
	
		GameQuestion* GetQuestion(int index) { return questions.at(index); }

		int HowManyQuestions() { return questions.size(); }	
	
		//bool RunGame(); // this will play the game
};

#endif // __GAME_HPP__
