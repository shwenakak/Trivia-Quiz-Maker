#include "../header/quiz.h"

#include <string>
#include <iostream>
#include <cctpye> // for tolower() function

using namespace std;

Quiz::~Quiz {
	delete question;
}

void Quiz::SetType(string q) {
	delete question;

	if (tolower(q) == "t/f")
		question = new TF(); // new class
	else if (tolower(q) == "mc")
		question = new MC(); // new class
	else if (tolower(q) == "fill")
		question = new Fill(); // new class
}

void Quiz::PickTopic() {
	cout << "What topic would you like to test your knowledge in?" << endl;
	cout << "Music, Sports, or Science" << endl;
	cin >> tolower(topic); // store user choice in instance variable as undercase for saftey
}

void Quiz::QType() {
	cout << "What kind of questions would you like?" << endl;
	cout << "T/F, MC, or Fill" << endl;
	cin >> tolower(type); // store user choice in instance variable as undercase for safety
	this->SetType(type);
}
