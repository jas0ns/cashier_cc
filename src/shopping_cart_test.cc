#include "shopping_cart.h"
#include "gtest/gtest.h"

const char kShopName[] = "ThoughtWorks"
const char kCommodities_config_dir[] = "../config/commodities.json"
const char kInput_Barcode_Dir[] = "../testcase/input.json"
const char kInput_Barcode_Str[] = "[ 'ITEM000001', \
                                     'ITEM000001', \
                                     'ITEM000001', \
                                     'ITEM000001', \
                                     'ITEM000001', \
                                     'ITEM000002-2', \
                                     'ITEM000003', \
                                     'ITEM000003', \
                                     'ITEM000003' ]";

TEST(Shop, InitShoppingCartFromString) {
  Shopping_Cart shopping_cart;
  shopping_cart.InitShoppingCartFromString(kInputBarcode);
  EXPECT_EQ(3, shopping_cart()->size());
}

TEST(Shop, InitShoppingCartFromFile) {
  Shopping_Cart shopping_cart;
  shopping_cart.InitShoppingCartFromDir(kInputBarcode);
  EXPECT_EQ(3, shopping_cart()->size());
}

TEST(Shopping_Cart, CalculateTotalPrice) {
  Shop shop(kShopName);
  shop.InitCommodities(kCommodities_config_dir);

  Shopping_Cart shopping_cart;
  shopping_cart.InitShoppingCartFromString(kInputBarcode);
  shopping_cart.CalculateTotalPrice();

  EXPECT_EQ(108.35, shopping_cart->total_price());
  EXPECT_EQ(14.15, shopping_cart->total_allowance());
}

