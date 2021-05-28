#include "../header/game.hpp"
#include "../header/fill.hpp"
#include "../header/tf.hpp"
#include "../header/mc.hpp"
#include "../header/game_question.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	Game g;

	string topic = g.PickTopic(); // user will pick either Sports, Science, or Music as a topic

//	g.SetStrategy(new Fill());	
	g.LoadQuestions(topic, "fill"); // load 2 fill-in-blank questions
	g.LoadQuestions(topic, "tf"); // load 2 tf questions
	g.LoadQuestions(topic, "mc"); // load 2 mc questions

	int size = g.HowManyQuestions();	
	cout << size << endl;

//	g.SetStrategy(new Fill());
	for (int i = 0; i < size; i++) {
		GameQuestion* q = g.GetQuestion(i);
		// if q->HowManyOptions() == 4; SetStrategy(new MC())
		// else if q->HowManyOptions() == 2; SetStrategy(new TF())
		// else SetStrategy(new Fill())
		if (q->HowManyOptions() == 4)
			g.SetStrategy(new MC());
		else if (q->HowManyOptions() == 2)
			g.SetStrategy(new TF());
		else
			g.SetStrategy(new Fill());

		g.print(q);
	}	

	
/*	if (g.LoadQuestions(topic, "fill")) // if 2 fill in the blank questions were appropriately added, change strategy and repeat
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
*/	

	//if (q.RunGame())
	//	cout << "CONGRATS! YOU WON!" << endl;
	//else
	//	cout << "Ouch, better luck next time loser" << endl;	

	return 0;
}
