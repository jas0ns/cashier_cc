#include <string>

#include "gtest/gtest.h"

#include "shopping_cart.h"
#include "commodity_map.h"

const std::string kCommoditiesConfigDir = "../config/commodities.json";
const std::string kInputBarcodeDir = "../testcase/input.json";
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

TEST(Shopping_Cart, InitShoppingCartFromString) {
  Commodity_Map commodity_map; 
  commodity_map.Init_Commodity_Map_From_Dir(kCommoditiesConfigDir);

  Shopping_Cart shopping_cart;
  shopping_cart.InitShoppingCartFromString(
      kInputBarcodeStr, &commodity_map);
  //EXPECT_EQ(3, shopping_cart.shopping_item_list()->size());
}

TEST(Shopping_Cart, InitShoppingCartFromFile) {
  Commodity_Map commodity_map; 
  commodity_map.Init_Commodity_Map_From_Dir(kCommoditiesConfigDir);

  Shopping_Cart shopping_cart;
  shopping_cart.InitShoppingCartFromFile(
      kInputBarcodeDir, &commodity_map);
  //EXPECT_EQ(3, shopping_cart()->size());
}

TEST(Shopping_Cart, CalculateTotalPriceAndAllowance) {
  Commodity_Map commodity_map; 
  commodity_map.Init_Commodity_Map_From_Dir(kCommoditiesConfigDir);

  Shopping_Cart shopping_cart;
  shopping_cart.InitShoppingCartFromString(
      kInputBarcodeStr, &commodity_map);
  shopping_cart.CalculateTotalPriceAndAllowance();

  EXPECT_DOUBLE_EQ(86.9, shopping_cart.total_price());
  EXPECT_DOUBLE_EQ(11.1, shopping_cart.total_allowance());
}

