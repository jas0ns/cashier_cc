#include <string>

#include "shopping_cart.h"
#include "shop.h"

std::string Shop::GenerateInvoice(Shopping_Cart* shopping_cart) {
  std::string invoice;
  invoice += "***<";
  invoice += this->name_;
  invoice += ">购物清单***\n";
  invoice += "-----------------------------------------------------------------------\n";
  invoice += shopping_cart->details_part();
  invoice += "-----------------------------------------------------------------------\n";
  if (shopping_cart->promotions_part().length() != 0) {
    invoice += shopping_cart->promotions_part();
    invoice += "\n-----------------------------------------------------------------------\n";
  }
  invoice += shopping_cart->summary_part();
  invoice += "\n-----------------------------------------------------------------------\n";
  return invoice;
}

