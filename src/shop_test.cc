#include <string>

#include "gtest/gtest.h"

#include "shop.h"
#include "shopping_cart.h"

const std::string kShopName("ThoughtWorks");

TEST(Shop, ConstructorFromString) {
  Shop shop(kShopName);
  EXPECT_STREQ(shop.name().c_str(), kShopName.c_str());
}

TEST(Shop, GenerateInvoice) {
  Shop shop(kShopName);
  Shopping_Cart shopping_cart;
  shopping_cart.set_details_part(std::string("苹果 120"));
  shopping_cart.set_promotions_part(std::string("单品打折商品"));
  shopping_cart.set_summary_part(std::string("总计:123123.00"));

  std::string invoice = shop.GenerateInvoice(&shopping_cart);

  std::cout << invoice << std::endl;
}


