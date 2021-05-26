#include "game.cpp"
#include "../header/fill.hpp"
//#include "../header/tf.hpp"
//#include "../header/mc.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	Game g;

	string topic = g.PickTopic(); // user will pick either Sports, Science, or Music as a topic
	
	g.SetStrategy(new Fill());
	if (g.LoadQuestion(topic, "fill")) // if 2 fill in the blank questions were appropriately added, change strategy and repeat
		g.SetStrategy(new TF());
	else {
		cout << "Error adding Fill-in-the=Blank Questions" << endl;
		exit(1);
	}

	if (g.LoadQuestions(topic, "tf")) // if 2 TF questions were approrpately added, change strategy and repeat
		g.SetStrategy(new MC());
	else {
		cout << "Error adding TF Questions" << endl;
		exit(1);
	}

	if (!g.LoadQuestions(topic, "mc")) { // if 2 MC questions were NOT appropriately added, spit ERROR. Else move on
		cout << "Error adding MC Questions" << endl;
		exit(1);
	}
	

	//if (q.RunGame())
	//	cout << "CONGRATS! YOU WON!" << endl;
	//else
	//	cout << "Ouch, better luck next time loser" << endl;	

	return 0;
}
