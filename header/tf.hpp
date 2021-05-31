#ifndef __TF_HPP__
#define __TF_HPP__

#include "type.hpp"

#include <string>
#include <vector>

using namespace std;

class TF : public Type {
	public:
		TF() : Type() {} 
		virtual void Display(GameQuestion* gq, std::ostream& out) const {
			out << "\t" << gq->GetQuestion() << endl;
			vector<GameQuestion*> options = gq->AllOptions();
                        for (int i = 0; i < options.size(); i++) {
                                out << "\t\t" << options.at(i)->GetSingleOption() << endl;
                        }	
		}
};

#endif // __TF_HPP__
