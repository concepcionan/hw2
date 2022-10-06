#include "mydatastore.h"
#include "product.h"
#include "util.h"

using namespace std;

MyDataStore::MyDataStore() {

}

void MyDataStore::addProduct(Product* p) {  
  products.push_back(p);
}

void MyDataStore::addUser(User* u) {
  users.push_back(u);
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type) {
  vector<Product*> hits;
  set<string> termSet(terms.begin(), terms.end());
  for (int i = 0; i < (int)products.size(); i++){ //for each product in database
    set<string> keywordSet = products[i]->keywords();
    set<string> unionSet = setUnion(keywordSet, termSet);
    set<string> intersectSet = setIntersection(keywordSet,termSet);

    if (type == 0){ //AND
      if (intersectSet == termSet){
        hits.push_back(products[i]);
      }
    }
    else if (type == 1){ //OR
      if (termSet.size() + keywordSet.size() != unionSet.size()){
        hits.push_back(products[i]);
      }
    }
  } 
  return hits;
}

void MyDataStore::dump(ostream& ofile) {
  ofile << "<products>\n";
  for (int i = 0; i < (int)products.size(); i++){
    products[i]->dump(ofile);
  }
  ofile << "</products>\n";

  ofile << "<users>\n";
  for (int i = 0; i < (int)users.size(); i++){
    users[i]->dump(ofile);
  }
  ofile << "</users>\n";
}
