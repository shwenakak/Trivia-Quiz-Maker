#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "tf_display"

using namespace std;

int main()
{
	//opens the sports tf txt
	ifstream tf;
	tf.open("sports_tf.txt")
	
	//displays error message if file isnt open
	if(!tf.is_open())
	{
		cout << "Error opening" << endl;
	}
	
	//creates a vector of strings
	vector <string> lines;
	srand(time(0));
	
	//creates a counter to find the total amount of lines for the files
	int tot_lines = 0;

	//gets the question
	while(getline(tf, quest))
	{
		tot_lines++;
		lines.push_back(line);
	}
	
	//chooses a random question
	int rand_num = rand()%tot_lines;
	
	//displays a random question
	cout << lines[rand_num] << endl;
	
	//Prompts user response
	cout << "Please enter true or false" <<endl;

	//gets answer 
	cin  >> uans;
	cout << uans << endl;
	
}

