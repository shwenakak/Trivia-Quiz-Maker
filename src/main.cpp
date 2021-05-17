#include "quiz.cpp"

#include <iostream>

using namespace std;

int main() {
	
	Quiz q;

	q.PickTopic();
	q.QType();

	//if (q.RunGame())
	//	cout << "CONGRATS! YOU WON!" << endl;
	//else
	//	cout << "Ouch, better luck next time loser" << endl;	

	return 0;
}
