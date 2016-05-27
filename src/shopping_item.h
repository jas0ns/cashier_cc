#ifndef CASHIER_SHOPPING_ITEM_H_
#define CASHIER_SHOPPING_ITEM_H_

class Commodity;

class Shopping_Item {
 public:
  Shopping_Item() : commodity_(0), amount_(0), 
                    subtotal_(0.0), allowance_(0.0) {}

  void set_commodity(Commodity* pc) { commodity_ = pc; }
  void set_amount(int a) { amount_ = a; }
  void set_subtotal(double s) { subtotal_ = s; }
  void set_allowance(double a) { allowance_ = a; }

  Commodity* commodity() { return commodity_; }
  int amount() { return amount_; }
  double subtotal() { return subtotal_; }
  double allowance() { return allowance_; }

 private:
  Commodity* commodity_;
  int amount_;
  double subtotal_;
  double allowance_;
};

#endif // CASHIER_SHOPPING_ITEM_H_
