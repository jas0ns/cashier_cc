#include <string>

#include "shopping_cart.h"
#include "shop.h"

std::string Shop::GenerateInvoice(Shopping_Cart* shopping_cart) {
  std::string invoice;
  invoice += this->name_;
  invoice += "\n";
  invoice += shopping_cart->details_part();
  invoice += "\n----------------------------\n";
  invoice += shopping_cart->promotions_part();
  invoice += "\n----------------------------\n";
  invoice += shopping_cart->summary_part();
  return invoice;
}

