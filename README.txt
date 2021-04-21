Title of the project: Trivia Quiz Maker
Group member names, and links to their GitHub pages:
	Alexus: alexthelionnnn (github.com)
	Arnav: https://github.com/Arnav-Menon 
	Shwena: https://github.com/shwenakak
A Project Description
	The trivia quiz will allow the user to play a trivia game. The user will be able to choose between a genre-specific quiz or a generalized quiz. Based on their selection the quiz will contain multiple-choice, true/false, or fill-in-the-blank questions.
Why is it important or interesting to you?
	Games are a fun way to destress and relax, especially in these current times, learning how to relax and take care of yourself is equally as important as staying on top of your stuff.
What languages/tools/technologies do you plan to use?
	We will be using C++, Valgrind, and CMake.
What will be the input/output of your project?
	Input
		User selection/answers
		Reference text documents
	Output
		Quiz questions
What are the two design patterns you will be using? Why you picked this pattern and what feature you will implement with it? Why the chosen design pattern will lead to a good solution to that problem? What problems do you anticipate encountering when implementing your project that you will solve using the design pattern? For each design pattern you must explain in 4-5 sentences:
	Composite: 
		We picked this pattern because we felt that a quiz allows us to nicely and cleanly divide the project into separate components. For example, the quiz can be generated about one specific topic or multiple topics; each topic can be its own class, or component, which will have a list of questions specific to it. A problem we could potentially face when implementing our project is failing to access the uploaded files when prompted by the user for which quiz they want to take and questions. An additional composite design pattern problem that may arise is that the user’s input is incomprehensible forcing either an error or the program marking a correct answer as incorrect. 
	Strategy:  
		We chose this design pattern because we anticipate having multiple algorithms to check the validity of the users’ answers. For example, the algorithm to determine the correctness of a T/F question will differ from the algorithm to determine the correctness of the fill in the blank questions. We might not be able to do that with one, clear-cut algorithm. So to be safe, we may need to implement multiple different algorithms, which we can then call whenever necessary. Another problem we anticipate coming upon is the delayed completion of reading in all the files. Implementing specific algorithms can help lower the runtime and ensure the user is able to take the quiz as soon as possible.

