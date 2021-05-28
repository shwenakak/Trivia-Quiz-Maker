#ifndef __TF_HPP__
#define __TF_HPP__

#include "type.hpp"

#include <string>
#include <vector>

using namespace std;

class TF : public Type {
	public:
		TF() : Type() {} 
		virtual void Display(GameQuestion* gq) const {
			cout << "IN TF CLASS" << endl;
			cout << "\t" << gq->GetQuestion() << endl;
		}
};

#endif // __TF_HPP__
