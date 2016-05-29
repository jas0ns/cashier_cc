#include "promotions.h"
#include "rebate_promotions.h"
#include <iostream>

Promotions* Promotions::GetPromotionsInstance(
    const int type, const std::string& name, 
    const std::string& print, const std::string& arguments) {
  Promotions *promotions;
  switch (type) {
    case 0: 
      promotions = new Rebate_Promotions();
      promotions->set_name(name);
      promotions->set_print(print);
      promotions->set_type(type);
      promotions->set_arguments(arguments);
      break;
    default:
      return NULL;
  }

  return promotions;
}
