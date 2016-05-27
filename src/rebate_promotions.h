#ifndef CASHIER_REBATE_PROMOTIONS_H_
#define CASHIER_REBATE_PROMOTIONS_H_

#include "promotions.h"

class Shopping_Item;

class Rebate_Promotions : public Promotions {
 public:
  Rebate_Promotions() : percent_(1.0) {}
  virtual void CalculatePromotions(Shopping_Item*);

  void set_percent(double p) { percent_ = p; }

 private:
  double percent_;

};

#endif // CASHIER_REBATE_PROMOTIONS_H_
