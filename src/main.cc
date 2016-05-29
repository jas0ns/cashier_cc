#include <iostream>

#include "shop.h"
#include "commodity_map.h"
#include "shopping_cart.h"

const std::string kInputBarcodeStr = "[ \"ITEM000001\", \
                                     \"ITEM000001\", \
                                     \"ITEM000001\", \
                                     \"ITEM000001\", \
                                     \"ITEM000001\", \
                                     \"ITEM000002-2\", \
                                     \"ITEM000003\", \
                                     \"ITEM000003\", \
                                     \"ITEM000003\", \
                                     \"ITEM000004-2\"]";

int main() {
  Shop shop("没钱赚商店");
  Commodity_Map commodity_map;
  commodity_map.Init_Commodity_Map_From_Dir("../config/commodities.json");

  Shopping_Cart shopping_cart;
  shopping_cart.InitShoppingCartFromString(kInputBarcodeStr, &commodity_map);
  shopping_cart.CalculateTotalPriceAndAllowance();
  shopping_cart.GenerateInvoiceParts();
  
  std::string invoice = shop.GenerateInvoice(&shopping_cart); 
  std::cout << invoice << std::endl;

  return 0;
}
