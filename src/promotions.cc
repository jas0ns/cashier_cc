#include "promotions.h"
#include "rebate_promotions.h"
#include <iostream>

Promotions* Promotions::GetPromotionsInstance(
    const char type, const std::string name, 
    const std::string arguments) {
  Promotions *promotions;
  switch (type) {
    case 0x00: 
      promotions = new Rebate_Promotions();
      promotions->set_name(name);
      promotions->set_arguments(arguments);
      break;
    default:
      return NULL;
  }

  return promotions;
}
