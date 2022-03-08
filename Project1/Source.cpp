/*
* Author: CS
* Date: 2022/03/08
* 
* Define a program that counts the number of words in two ways.
* 1 - whitespace separated sequence of characters	: count_words_as_white_space_separated_characters(Document&)
* 2 - a sequence of alphabetic characters			: count_words_as_alphabetic_sequences(Document&)
*/
#include "cs_texteditor.h"
#include <sstream>
int main() {
	try {
		Document doc;
		std::stringstream input;
		input << "Testing the document's input operation with arbitrary input.\nAlpha\nBravo\nCharlie\n";
		input >> doc;
		input.clear();

		std::cout << "The following document has " << count_characters(doc) << " characters with spaces:\n\n\"\n";
		print(doc);
		std::cout << "\n\"" << std::endl;


		Document test1;
		input << "\n";
		input >> test1;
		input.clear();

		input << "alpha\nbravo charlie\n";
		Document test2;
		input >> test2;
		input.clear();

		input << "alpha.numeric\n";
		Document test3;
		input >> test3;
		input.clear();

		input << "as12b\n";
		Document test4;
		input >> test4;
		input.clear();

		std::cout << "count_words_as_white_space_separated_characters(Document&) test:" << std::endl;
		std::cout << "Should output as 0:\t";
		std::cout << count_words_as_white_space_separated_characters(test1) << std::endl;
		std::cout << "Should output as 3:\t";
		std::cout << count_words_as_white_space_separated_characters(test2) << std::endl;
		std::cout << "Should output as 1:\t";
		std::cout << count_words_as_white_space_separated_characters(test3) << std::endl;
		std::cout << "Should output as 1:\t";
		std::cout << count_words_as_white_space_separated_characters(test4) << std::endl;

		std::cout << "count_words_as_alphabetic_sequences(Document&) test:" << std::endl;
		std::cout << "Should output as 0:\t";
		std::cout << count_words_as_alphabetic_sequences(test1) << std::endl;
		std::cout << "Should output as 3:\t";
		std::cout << count_words_as_alphabetic_sequences(test2) << std::endl;
		std::cout << "Should output as 2:\t";
		std::cout << count_words_as_alphabetic_sequences(test3) << std::endl;
		std::cout << "Should output as 2:\t";
		std::cout << count_words_as_alphabetic_sequences(test4) << std::endl;


	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
