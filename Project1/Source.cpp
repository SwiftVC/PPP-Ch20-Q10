/*
* Author: CS
* Date: 2022/03/08
* 
* Define a function that counts the number of characters in a Document
*/
#include "cs_texteditor.h"
#include <sstream>
int main() {
	try {
		Document doc;
		std::stringstream input;
		input << "Testing the document's input operation with arbitrary input.\nAlpha\nBravo\nCharlie\n";
		input >> doc;

		std::cout << "The following document has " << count_characters(doc) << " characters with spaces:\n\n\"\n";
		print(doc);
		std::cout << "\n\"" << std::endl;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
