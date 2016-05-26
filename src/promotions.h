#ifndef CASHIER_PROMOTIONS_H_
#define CASHIER_PROMOTIONS_H_

#include "shopping_item.h"

class Promotions {
 public:
  Promotions() {}
  virtual void CalculatePromotions(Shopping_Item*) = 0;

 private:
}; 

Promotions* GetPromotionsInstance();

#endif // CASHIER_PROMOTIONS_H_
