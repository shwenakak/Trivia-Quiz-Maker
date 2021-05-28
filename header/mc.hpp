#ifndef __MC_HPP__
#define __MC_HPP__

#include "type.hpp"

#include <string>
#include <vector>

using namespace std;

class MC : public Type {
        public:
                MC() : Type() {}
                virtual void Display(GameQuestion* gq) const {
                        cout << "IN MC CLASS" << endl;
                        cout << "\t" << gq->GetQuestion() << endl;
                }
};

#endif // __MC_HPP__
