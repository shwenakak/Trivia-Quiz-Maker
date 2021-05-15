#include "../header/quiz.h"
#include "fill.cpp"

#include <string>
#include <iostream>
//#include <ctpye.h> // for tolower() function
#include <algorithm> // need this to manually convert user inputs to lowercase
#include <fstream>

using namespace std;

Quiz::~Quiz() {
	delete question;
}

void Quiz::LoadQuestions(string t) {
	ifstream inFile;
	inFile.open("../notes/" + t + ".txt");
	if (inFile.is_open())
		cout << "SPORTS QUESTIONS OPENED" << endl;
}

void Quiz::SetType(string q) {
	delete question;
	
	// params: beginnigng of word, end of word, beginning of word we want to store result inm what we want to do	
	transform(q.begin(), q.end(), q.begin(), ::tolower);	

//	if (tolower(q) == "t/f" || tolower(q) == "tf")
//		question = new TF(topic); // new class
//	else if (tolower(q) == "mc")
//		question = new MC(topic); // new class
	if (q == "fill")
		question = new Fill(topic); // new class
	else {
		cout << "Please enter a valid choice" << endl;
		this->QType(); // call function again to get user input
	}
}

void Quiz::PickTopic() {
	while (topic != "music" || topic != "sports" || topic != "science") {
		// weirdly it doesn't break out of loop without this if statement...
		if (topic == "music" || topic == "sports" || topic == "science")	
			break;
		cout << "TOPIC: " << topic << endl;
		cout << "What topic would you like to test you knowledge in?" << endl;
		cout << "Music, Sports, or Science" << endl;
		cin >> topic; // store user chouce in instance variable as undercase for safety	
		transform(topic.begin(), topic.end(), topic.begin(), ::tolower);		
	}

	this->LoadQuestions(topic); // load questions about user topic
}

void Quiz::QType() {
	cout << "What kind of questions would you like?" << endl;
	cout << "T/F, MC, or Fill" << endl;
	cin >> type; // store user choice in instance variable as undercase for safety
	
	cout << "QTYPE: " << type << endl;
	
	this->SetType(type);
}

// TODO
//bool RunGame() {
	// display question based on user's topic
//	question->DisplayQuestion();
	
//	question->CheckAnswer();
//}
