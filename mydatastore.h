#include "datastore.h"
#include "product.h"


class MyDataStore : public DataStore {
  public:
    MyDataStore();
    virtual void addProduct(Product* p);
    virtual void addUser(User* u);
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);
    virtual void dump(std::ostream& ofile);
  private:
    std::vector<Product*> products;
    std::vector<User*> users;
};