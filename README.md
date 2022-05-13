# Wordle-Solver

I created this Wordle Solver to learn more about C++ when I was first beginning to use it and rewrote it several months later.  My first version was 500 lines of spaghetti code in one file, but I placed much more of an emphasis on object oriented programming upon rewriting.

One of the first challenges in this project was finding the word lists.  They are easily found in the Wordle source code (main.9622bc55.js).  From there, I got to designing my algorithm.

My algorithm is relatively simple - assign each character a score (3 for green, 2 for yellow) and pick the word with the highest score.

My new implementation is working and is much prettier than my first attempt, but still requires some tuning as it took >4 guesses per word on average and lost on ~2% of words compared to my first version which took 3.8 guesses and only lost on about 1% of words.

## files

 - data
	 - contains the word lists
 - Guess
	 - Contains information about the guessed word and what information it revealed
 - Word
	 - Holds a word.  Used to evaluate whether the word should be eliminated or not based off of known information
 - WordList
	 - List of words - main handles a list of possible guesses and possible answers
 - CharInfo
	 - Contains the known information about the word - greens, yellows, grays, etc.
 - ValueFinder
	 - Used to find an integer score for a word based off of character frequencies
 - analysis.cpp
	 - Runs through every possible answer to find the average number of guesses this solver takes
 - main.cpp
	 - Interactive playthrough with user interaction
