#include <string>

#include "gtest/gtest.h"

#include "shop.h"
#include "shopping_cart.h"

const std::string kShopName = "ThoughtWorks"

TEST(Shop, ConstructorFromString) {
  Shop si(kShopName);
  EXPECT_EQ(0, strcmp(si.name(), kShopName));
}


const char[] kInvoice = "ThoughtWorks\n"
                苹果 120 \n
                ----------------------------\n
                单品打折商品\n
                ----------------------------\n
                总计：123123.00";

TEST(Shop, GenerateInvoice) {
  Shop shop(kShopName);
  Shopping_Cart shopping_cart;
  shopping_cart.set_details_part("苹果 120\n");
  shopping_cart.set_promotions_part("单品打折商品");
  shopping_cart.set_summary_part("总计:123123.00");

  std::string s = shop.GenerateInvoice(shopping_cart);

  EXPECT_STREQ(kInvoice, s.c_str());
}

