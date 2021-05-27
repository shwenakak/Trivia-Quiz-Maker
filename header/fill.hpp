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
			cout << gq->GetQuestion() << endl;
		}
};

#endif // __FILL_HPP__
