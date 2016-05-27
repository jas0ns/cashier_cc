#ifndef CASHIER_SHOPPING_CART_H_
#define CASHIER_SHOPPING_CART_H_

#include <string>
#include <list>

class Shopping_Item;

class Shopping_Cart {
 public:
  Shopping_Cart() : total_price(0.0), total_allowance(0.0) {}

  void InitShoppingCartFromString(std::string, const Commodity_Map&);
  void InitShoppingCartFromFile(std::string, const Commodity_Map&);
  void CalculateTotalPriceAndAllowance();

  void set_details_part(std::string s) { details_part_ = s; }
  void set_promotions_part(std::string s) { promotions_part_ = s; }
  void set_summary_part(std::string s) { summary_part_ = s; }
  std::string details_part() { return details_part_; }
  std::string promotions_part() { return promotions_part_; }
  std::string summary_part() { return summary_part_; }

  
 private:
  double total_price;
  double total_allowance;
  std::string details_part_;
  std::string promotions_part_;
  std::string summary_part_;
  std::list<Shopping_Item*> shopping_item_list;
};

#endif // CASHIER_SHOPPING_CART_H_
