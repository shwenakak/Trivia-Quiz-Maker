#ifndef __GAMEQUESTION_HPP__
#define __GAMEQUESTION_HPP__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GameQuestion {
    
    protected:
        int totalPoints = 0; 
        int qPoints = 0;
        int score = 0; 

    public:
        
        virtual string GetAnswer() const = 0;
        
        virtual string GetQuestions() const {
		return "Shwena is awesome!"
	};
        
        virtual int HowManyOptions() const {
		return 5;
	};

        virtual void AddOption(GameQuestion* gq) {}

        virtual vector<GameQuestion*> GetOptions() {}
        virtual vector<GameQuestion*> AllOptions() {}
        virtual string GetSingleOption() {}
        virtual int GetScore() const {} 

        virtual int GetTotalPoints() const { }
        
        virtual int QPoints() {}

        virtual void UpdateUserScore(int) {}
};
#endif

