#include "../header/fill.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Fill::DisplayQuestion() const {
	cout << this->question << endl;
	return "hello";
}

bool Fill::CheckAnswer(string i, string s) const {
	cout << this->answer << endl;
	return true;
}

