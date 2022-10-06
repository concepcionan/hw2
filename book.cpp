#include "book.h"
#include "util.h"
#include <cmath>

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string isbn, string author)
      : Product(category, name, price, qty){
    isbn_ = isbn;
    author_ = author;
}

set<string> Book::keywords() const{
  string name_ = getName();
  set<string> bKeywords_ = parseStringToWords(name_);
  bKeywords_.insert(isbn_);
  bKeywords_.insert(author_);
  return bKeywords_;
}
string Book::displayString() const{
  string name_ = getName();
  string price_ = to_string(getPrice());
  price_ = price_.substr(0, price_.find(".")+3); 
  string qty_ = to_string(getQty());
  string bString;

  bString += name_ + "\n";
  bString += "Author: " + author_ + " ISBN: " + isbn_ + "\n";
  bString += "$" + price_ + " " + qty_ + " left." + "\n"; 
  return bString;
}

void Book::dump(std::ostream& os) const{
  os << "book" << endl << getName() << endl << getPrice() << endl << getQty() << endl << isbn_ << endl << author_ << endl;
}
