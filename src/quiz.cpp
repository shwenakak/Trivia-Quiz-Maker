#include "../header/quiz.h"
#include "fill.cpp"

#include <string>
#include <iostream>
#include <algorithm> // need this to manually convert user inputs to lowercase
#include <fstream>

using namespace std;

Quiz::~Quiz() {
	delete question;
}

void Quiz::LoadQuestions(string t) {
	ifstream inFile;
	string line;

	// specify path to file from directory where executbale is called
	inFile.open("notes/" + t + ".txt");
	
	if (!inFile.is_open())
		cout << "FILE NOT OPEN" << endl;
	else
		cout << "FILE OPENED" << endl;

	// read from file and add to vector of questions
	while(!inFile.eof()) {
		inFile >> line;
		if (line == (this->type + ":")) { // added the ':' bc that's how it's formatted in the notes/sports.txt file
			getline(inFile, line);
			game_questions.push_back(line);
			//cout << line << endl;
		}
	}

	inFile.close();
}

bool Quiz::SetType(string q) {
	delete question;
	
	if (q == "t/f")
		//question = new TF(topic); // new class
		string s = "h"; // will remove when TF class is implemented
	else if (q == "mc")
		//question = new MC(topic); // new class
		string h = "h"; // will remove when MC class is implemented
	else if (q == "fill")
		question = new Fill(topic); // new class
	else {
		cout << "Please enter a valid choice" << endl;
		return false;
	}

	return true;	
}

void Quiz::PickTopic() {
	while (topic != "music" || topic != "sports" || topic != "science") {
		// weirdly it doesn't break out of loop without this if statement...
		if (topic == "music" || topic == "sports" || topic == "science")	
			break;
		cout << "TOPIC: " << topic << endl;
		cout << "What topic would you like to test you knowledge in?" << endl;
		cout << "Music, Sports, or Science" << endl;
		//cin >> topic; // store user chouce in instance variable as undercase for safety	
		topic = "sports";
		cout << "TOPIC: " << topic << endl;
		transform(topic.begin(), topic.end(), topic.begin(), ::tolower);		
	}
}

void Quiz::QType() {
	while (!SetType(type)) {
		cout << "What kind of questions would you like?" << endl;
		cout << "T/F, MC, or Fill" << endl;
		cin >> type; // store user choice in instance variable as undercase for safety
	
		// params: beginnigng of word, end of word, beginning of word we want to store result inm what we want to do	
		transform(type.begin(), type.end(), type.begin(), ::tolower);	
		
		cout << "QTYPE: " << type << endl;
	}
	
	LoadQuestions(topic); // load questions about user topic
}

// TODO
//bool RunGame() {
	// display question based on user's topic
//	question->DisplayQuestion();
	
//	question->CheckAnswer();
//}
