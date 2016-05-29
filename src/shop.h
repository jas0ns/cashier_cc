#ifndef CASHIER_SHOP_H_
#define CASHIER_SHOP_H_

#include <string>
#include <map>

class Commodity;
class Shopping_Cart;

class Shop {
 public:
  explicit Shop(std::string s) : name_(s) {}
  std::string GenerateInvoice(Shopping_Cart*);

  std::string name() const { return name_; }
  
 private:
  std::string name_;
};

#endif // CASHIER_SHOP_H_
