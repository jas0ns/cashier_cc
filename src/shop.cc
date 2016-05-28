#include <string>

#include "shopping_cart.h"
#include "commodity.h"
#include "shop.h"

void Shop::Init_Commodities(std::string dir) {
  
}

std::string Shop::GenerateInvoice(Shopping_Cart* shopping_cart) {
  string invoice;
  invoice += this->name_;
  invoice += shopping_cart->details_part();
  invoice += shopping_cart->promotions_part();
  invoice += shopping_cart->summary_part();
  return invoice;
}

