#ifndef CASHIER_COMMODITY_H_
#define CASHIER_COMMODITY_H_

#include <string>

class Promotions;

class Commodity {
 public:
  Commodity() {}

  void set_barcode(std::string s) { barcode_ = s; }
  void set_name(std::string s) { name_ = s; }
  void set_unit(std::string s) { unit_ = s; }
  void set_category(std::string s) { category_ = s; }
  void set_subCategory(std::string s) { subCategory_ = s; }
  void set_price(double p) { price_ = p; }

  std::string barcode() { return barcode_; }
  std::string name() { return name_; }
  std::string unit() { return unit_; }
  std::string category() { return category_; }
  std::string subCategory() { return subCategory_; }
  double price() { return price_; }

 private:
  std::string barcode_;
  std::string name_;
  std::string unit_;
  std::string category_;
  std::string subCategory_;
  double price_;

  Promotions* promotions_;
};


#endif // CASHIER_COMMODITY_H_
