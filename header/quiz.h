#ifndef __QUIZ_HPP__
#define __QUIZ_HPP__

#include <string>
#include <iostream>

using namespace std;

// may need to forward declare Questions class like in lab5

class Quiz {

	private:
		Questions* q; // reference to Questions class; composite component

	public:
		~Quiz();
		// TODO
		string PickTopic(); // which topic will user choose: Music, Sports, or Science
		// TODO
		string QType(); // which questions does user want: T/F, MC, FillinBlank
		// TODO
		bool RunGame(); // this will play the game
};

#endif // __QUIZ_HPP__
