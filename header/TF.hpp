#ifndef __TF_HPP__
#define __TF_HPP__

#include "../header/Type.hpp"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TF: public Type {
      
    public:
        TF() : Type() {}
	
	virtual void Display(GameQuestion* gQues) const { //if type points to a TF class, type->Display() will call the Display() function of the TF class
	cout << "\t" << gq->GetQuestion() << endl;
        cout << "\t\t True" << endl;
        cout << "\t\t False" << endl;
	/* vector<GameQuestion*> options = gq->AllOption();
	for (int i=0;i < options.size(); i++){
	cout << "\t\t" << options.at(i)->GetSingleOption() << endl;
	} */
     }
}
}
#endif

