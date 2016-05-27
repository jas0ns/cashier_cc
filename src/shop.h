#ifndef CASHIER_SHOP_H_
#define CASHIER_SHOP_H_

#include <string>

class Commodity_Map;


class Shop {
 public:
  explicit Shop(std:string s) name_(s) {}
  std::string GenerateInvoice(Shopping_Cart*);

 private:
  Commodity_Map *commodity_map_;
  std:string name_;
};

#endif // CASHIER_SHOP_H_
