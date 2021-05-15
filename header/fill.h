#ifndef __FILL_HPP__
#define __FILL_HPP__

#include <string>
#include <vector>

class Fill : public Questions {
	private:
		// will number each question so we can easily find which question we want to check the answer of
		vector<string> MusicAns;
		vector<string> ScienceAns;
		vector<string> SportsAns;

		string user_topic; // will use this to preselect 5 questions when the object is created
	public:
		Fill(string);

		virtual void DisplayQuestion() const;
		virtual bool CheckAnswer() const;
			
};

#endif // __FILL_HPP__
