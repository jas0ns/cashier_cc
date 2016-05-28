#ifndef CASHIER_SHOP_H_
#define CASHIER_SHOP_H_

#include <string>
#include <map>

class Commodity;
class Shopping_Cart;

class Shop {
 public:
  explicit Shop(std:string s) name_(s) {}
  void Init_Commodities(std::string);
  std::string GenerateInvoice(Shopping_Cart*);
  const std::map<string, Commodity*>& commodity_map() {
    return commodity_map_;
  }
  
 private:
  Commodity_Map commodity_map_;
  std:string name_;
};

#endif // CASHIER_SHOP_H_
