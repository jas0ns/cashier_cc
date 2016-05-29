#ifndef CASHIER_COMMODITY_H_
#define CASHIER_COMMODITY_H_

#include <string>

class Promotions;

class Commodity {
 public:
  Commodity() : promotions_(NULL) {}

  void set_barcode(std::string s) { barcode_ = s; }
  void set_name(std::string s) { name_ = s; }
  void set_unit(std::string s) { unit_ = s; }
  void set_category(std::string s) { category_ = s; }
  void set_subCategory(std::string s) { subCategory_ = s; }
  void set_price(double p) { price_ = p; }
  void set_promotions(Promotions* p) { promotions_ = p; }

  std::string barcode() const { return barcode_; }
  std::string name() const { return name_; }
  std::string unit() const { return unit_; }
  std::string category() const { return category_; }
  std::string subCategory() const { return subCategory_; }
  double price() const { return price_; }
  Promotions* promotions() const { return promotions_; }

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
