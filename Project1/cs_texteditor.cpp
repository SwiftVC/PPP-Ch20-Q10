#include "cs_texteditor.h"

int count_characters(Document& doc) {
	int count = 0;
	Text_iterator iter = doc.begin();

	if (!iter)
		throw std::exception("Invalid Document");

	if (*iter != '\n')		// count first character
		count++;

	while (++iter)			// count other characters and iterate across lines
		if(*iter != '\n')
			count++;

	return count;
}

bool match(Text_iterator p, Text_iterator l, const std::string& s) {
	// empty string check, match check

	if (s.size() == 0)
		return false;
	for (int i = 0; p != l && i < s.size(); i++) {
		if (*p != s[i])
			return false;
		++p;
	}

	return true;
}

std::istream& operator>>(std::istream& is, Document& d)
{
	for (char ch; is.get(ch);) {
		d.line.back().push_back(ch);
		if (ch == '\n')
			d.line.push_back(Line{});
	}
	if (d.line.back().size()) d.line.push_back(Line{}); // add final empty line
	return is;
}

Text_iterator& Text_iterator::operator++() {
	++pos;
	if (pos == (*ln).end()) {
		++ln;
		pos = (*ln).begin();
	}
	return *this;
}

void print(Document& d) {
	for (auto p : d) std::cout << p;
}



void erase_line(Document& d, int n) {
	if (n < 0 || d.line.size() - 1 <= n) return;
	auto p = d.line.begin();
	advance(p, n);
	d.line.erase(p);
}


template<typename Iter>
void advance(Iter& p, int n) {
	while (0 < n) { ++p; --n; }
}


template<typename T, typename E>			// homemade find to avoid bug in find_txt(..) find usage
T find(T first, T last, E& element) {
	while (first != last)
	{
		if (*first == element)
			return first;
		++first;
	}
	return last;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s) {
	if (s.size() == 0) return last;
	char first_char = s[0];
	while (true) {
		auto p = find(first, last, first_char);	//
		// this is correct, *first and *last both return char.
		if (p == last || match(p, last, s))
			return p;
		first = ++p;
	}
}

void find_and_replace(Document& d, const std::string& repl, const std::string& with) {
	auto destination = find_txt(d.begin(), d.end(), repl); // an iterator with line and position

	if (!destination)
		return;

	if (destination != d.end())	// NOT d.end() but the end of the current line!
		for (int i = 0; i < repl.size(); i++)
			destination = destination.delete_char();

	for (int i = with.size(); i > -1; i--)
		destination = destination.insert_char(with[i]);

	return;
}

