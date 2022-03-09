/*
* Author: CS
* Date: 2022/03/09
* 
*	It works well.
Try inputting: alphabravocharliedelta
Try inputting: i
*
*/
#include "cs_texteditor.h"
#include <sstream>
int main() {
	try {
		Document doc;
		std::stringstream input;
		input << "alpha bravo charlie\ndelta";
		input >> doc;
		input.clear();

		std::cout << "\n\"\n";
		print(doc);
		std::cout << "\n\"" << std::endl;

		std::vector<char> vect{ ' ', '\n'};
		std::cout << "Specify the characters to seperate words, then press enter: (SPACE & NEWLINE are already included)\n";
		
		char ch{'\0'};
		while (std::cin.get(ch) && ch != '\n')
			vect.push_back(ch);

		std::cout << "The document has " << count_words_as_user_defined(doc, vect) << " words\n";


	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
