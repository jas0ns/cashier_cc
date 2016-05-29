#ifndef CASHIER_PROMOTIONS_H_
#define CASHIER_PROMOTIONS_H_

#include <string>

class Shopping_Item;

class Promotions {
 public:
  Promotions() {}
  virtual void CalculatePromotions(Shopping_Item*) = 0;
  void set_name(std::string n) { name = n; }
  void set_arguments(std::string a) { arguments = a; }

  static Promotions* GetPromotionsInstance(
      const int type, const std::string& name, 
      const std::string& arguments);

 protected:
  std::string name;
  std::string arguments;
}; 


#endif // CASHIER_PROMOTIONS_H_
