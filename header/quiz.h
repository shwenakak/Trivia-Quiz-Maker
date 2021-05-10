#ifndef __QUIZ_HPP__
#define __QUIZ_HPP__

#include <string>
#include <iostream>

using namespace std;

// may need to forward declare Questions class like in lab5

class Quiz {

	private:
		string topic;
		string type;
		Questions* question = nullptr; // reference to Questions class; composite component

	public:
		~Quiz();
		void SetType(string); // param is what type of questions user wants
		// TODO
		void PickTopic(); // which topic will user choose: Music, Sports, or Science
		// TODO
		void QType(); // which questions does user want: T/F, MC, FillinBlank
		// TODO
		bool RunGame(); // this will play the game
};

#endif // __QUIZ_HPP__
