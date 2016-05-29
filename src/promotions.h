#ifndef CASHIER_PROMOTIONS_H_
#define CASHIER_PROMOTIONS_H_

#include <string>

class Shopping_Item;

class Promotions {
 public:
  Promotions() {}
  virtual void CalculatePromotions(Shopping_Item*) = 0;
  void set_name(std::string n) { name = n; }
  void set_print(std::string p) { print = p; }
  void set_type(int i) { type = i; }
  std::string get_name() const { return name; }
  std::string get_print() const { return print; }
  int get_type() const { return type; }
  void set_arguments(std::string a) { arguments = a; }

  static Promotions* GetPromotionsInstance(
      const int type, const std::string& name, 
      const std::string& print, const std::string& arguments);

 protected:
  int type;
  std::string name;
  std::string arguments;
  std::string print;
}; 


#endif // CASHIER_PROMOTIONS_H_
