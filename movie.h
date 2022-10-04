#include <string>
#include <set>

#include "product.h"

class Movie : public Product{
  public: 
    Movie (std::string category,
          std::string name, 
          double price, 
          int qty, 
          std::string genre, 
          std::string rating);
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;
  private: 
    std::string genre_;
    std::string rating_;
};