#ifndef __FILL_HPP__
#define __FILL_HPP__

#include "type.hpp"

#include <string>
#include <vector>

using namespace std;

class Fill : public Type {
	public:
		Fill() : Type() {} 
		virtual void Display(GameQuestion* gq) const {
			cout << "IN FILL CLASS" << endl;
			cout << "\t" << gq->GetQuestion() << endl;
			vector<GameQuestion*> options = gq->AllOptions();
			for (int i = 0; i < options.size(); i++) {
				cout << "\t\t" << options.at(i)->GetSingleOption() << endl; 
			}
		}
};

#endif // __FILL_HPP__
