#include <stdlib.h>

#include "rebate_promotions.h"
#include "shopping_item.h"

void Rebate_Promotions::CalculatePromotions(Shopping_Item *shopping_item) {
  this->set_percent(atof(arguments.c_str()));
  shopping_item->set_allowance(
      shopping_item->subtotal() * (1 - percent_));
  shopping_item->set_subtotal(
      shopping_item->subtotal() - shopping_item->allowance());
}



