#ifndef CASHIER_SHOPPING_CART_H_
#define CASHIER_SHOPPING_CART_H_

#include <string>
#include <list>
#include <map>

class Shopping_Item;
class Commodity_Map;

class Shopping_Cart {
 public:
  Shopping_Cart() : total_price_(0.0), total_allowance_(0.0) {}
  ~Shopping_Cart() {};

  void InitShoppingCartFromString(const std::string&, Commodity_Map*);
 //TODO void InitShoppingCartFromFile(const std::string&, Commodity_Map*);
  void CalculateTotalPriceAndAllowance();
  void GenerateInvoiceParts();

  void set_details_part(std::string s) { details_part_ = s; }
  void set_promotions_part(std::string s) { promotions_part_ = s; }
  void set_summary_part(std::string s) { summary_part_ = s; }

  double total_price() const { return total_price_; }
  double total_allowance() const { return total_allowance_; }
  std::string details_part() const { return details_part_; }
  std::string promotions_part() const { return promotions_part_; }
  std::string summary_part() const { return summary_part_; }
  
 private:
  double total_price_;
  double total_allowance_;
  std::map<int, std::string> promotions_map_;
  std::string details_part_;
  std::string promotions_part_;
  std::string summary_part_;
  std::map<std::string, int> count_map_;
  std::list<Shopping_Item*> shopping_item_list_;
};

#endif // CASHIER_SHOPPING_CART_H_
