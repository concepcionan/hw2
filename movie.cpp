#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(string category, string name, double price, int qty, string genre, string rating)
  : Product(category, name, price, qty){
    genre_ = genre;
    rating_ = rating;
}

set<string> Movie::keywords() const{
  string name_ = getName();
  set<string> mKeywords_ = parseStringToWords(name_);
  mKeywords_.insert(genre_);
  mKeywords_.insert(rating_);
  return mKeywords_;
}

string Movie::displayString() const{
  string name_ = getName();
  string price_ = to_string(getPrice());
  string qty_ = to_string(getQty());
  string mString;

  mString += name_ + "\n";
  mString += "Author: " + rating_ + "ISBN: " + genre_ + "\n";
  mString += price_ + qty_ + " left." + "\n"; 
  return mString;
}

void Movie::dump(std::ostream& os) const{
  os << "book" << endl << getName() << endl << getPrice() << endl << getQty() << endl << genre_ << endl << rating_ << endl;
}
