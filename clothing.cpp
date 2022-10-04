#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(string category, string name, double price, int qty, string size, string brand)
  : Product(category, name, price, qty){
    size_ = size;
    brand_ = brand;
}

set<string> Clothing::keywords() const{
  string name_ = getName();
  set<string> cKeywords_ = parseStringToWords(name_);
  cKeywords_.insert(size_);
  cKeywords_.insert(brand_);
  return cKeywords_;
}

string Clothing::displayString() const{
  string name_ = getName();
  string price_ = to_string(getPrice());
  string qty_ = to_string(getQty());
  string cString;

  cString += name_ + "\n";
  cString += "Author: " + brand_ + "ISBN: " + size_ + "\n";
  cString += price_ + qty_ + " left." + "\n"; 
  return cString;
}

void Clothing::dump(std::ostream& os) const{
  os << "book" << endl << getName() << endl << getPrice() << endl << getQty() << endl << size_ << endl << brand_ << endl;
}
