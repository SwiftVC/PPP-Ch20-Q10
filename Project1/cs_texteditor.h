#ifndef cs_texteditor_
#define cs_texteditor_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <exception>
#include <cctype>

using Line = std::vector<char>;

// iterate past characters, ignoring line breaks
class Text_iterator {
	std::list<Line>::iterator ln; // line
	Line::iterator pos;		// character position in line/vector<char>

public:
	Text_iterator(std::list<Line>::iterator ll, Line::iterator pp)
		: ln{ ll }, pos{ pp } {}

	char& operator*() { return *pos; }
	Text_iterator& operator++();

	bool operator==(const Text_iterator& other) const
	{
		return ln == other.ln && pos == other.pos;
	}
	bool operator!=(const Text_iterator& other) const
	{
		return !(*this == other);
	}
	Text_iterator delete_char() {
		return Text_iterator{ ln, ln->erase(pos) };	// return a Text_iterator with the pos set to vector<char>/line's return value
	}
	Text_iterator insert_char(char ch) {
		return Text_iterator{ ln, ln->insert(pos, ch) };
	}

	operator bool() const {
		return this->ln->size();	// is pos at the blank end line?
	}
};

struct Document {
	std::list<Line> line;

	Text_iterator begin() {
		return Text_iterator(line.begin(), (*line.begin()).begin());
	}
	Text_iterator end() {
		auto last = line.end();
		--last;
		return Text_iterator(last, (*last).end());
	}
	Document() { line.push_back(Line{}); }
};

bool match(Text_iterator p, Text_iterator l, const std::string& s);
std::istream& operator>>(std::istream& is, Document& d);		// used to read into documents
void print(Document& d);
void erase_line(Document& d, int n);
template<typename Iter> void advance(Iter& p, int n);
template<typename T, typename E> T find(T first, T last, E& element);
Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s);
template<typename T, typename E> T find(T first, T last, E& element); // used by find_txt
void find_and_replace(Document& d, const std::string& repl, const std::string& with);
int count_characters(Document& doc);	// count letters and spaces but not newlines
int count_words_as_white_space_separated_characters(Document&); // count words but not newlines
int count_words_as_alphabetic_sequences(Document&);				// count words but not newlines
int count_words_as_user_defined(Document& doc, std::vector<char> vect);	// count words as user-defined

#endif