#ifndef __GAMEQUESTION_HPP__
#define __GAMEQUESTION_HPP__

#include <iostream>
#include <string>
#include <vector>

#include "../header/Game.hpp"

using namespace std;

class GameQuestion : public Game {
    
    protected:
        int totalPoints = 0; //++
        int qPoints = 5;
        int score = 0;  //++

    public:
        virtual GameQuestion(string , int ) = default;
        virtual GameQuestion(string , bool ) = default;
        
        virtual string GetAnswer() const = 0;
        
        virtual string GetQuestions() const = 0;
        
        virtual int HowManyOptions() const = 0;

        virtual void AddOption(GameQuestion* gq) {}

        virtual vector<GameQuestion*> GetOptions() {}
        virtual vector<GameQuestion*> AllOptions() {}
        virtual string GetSingleOption() {}
        virtual int GetScore() const {
          return this->score;
        } 

        virtual int GetTotalPoints() const {
          return this->totalPoints;
        }
        
        virtual int QPoints() {
          return this->qPoints;
        }  
        virtual void UpdateUserScore(int) {}
}
#endif

