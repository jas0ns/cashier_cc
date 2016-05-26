#include "shop.h"
#include "string.h"
#include "string"
#include "gtest/gtest.h"

const char kShopName[] = "ThoughtWorks"

TEST(Shop, ConstructorFromCString) {
  const Shop si(kShopName);
  EXPECT_EQ(0, strcmp(si.name(), kShopName));
}

const char kCommodities_config_dir[] = "../config/commodities.json"

TEST(Shop, InitCommodities) {
  Shop shop(kShopName); 
  shop.init_commodities(kCommodities_config_dir);
  EXPECT_STREQ("苹果", shop.commodities()["ITEM000001"]->name());
  EXPECT_EQ(3.00, shop.commodities()["ITEM000002"]->price());
  EXPECT_STREQ("运动器材", shop.commodities()["ITEM000003"]->category());
  EXPECT_TRUE(shop.commodities()["ITEM000004"]->promotions() == NULL);
}

const char[] kInvoice = "***<没钱赚商店>购物清单***\n
                ----------------------------\n
                单品打折商品\n
                ----------------------------\n
                总计：123123.00";

TEST(Shop, GenerateInvoice) {
  Shop shop(kShopName);
  Shopping_Cart shopping_cart;
  shopping_cart.set_details_output("***<没钱赚商店>购物清单***\n");
  shopping_cart.set_rebate_output("单品打折商品");
  shopping_cart.set_total_output("总计:123123.00");

  std::string s = shop.GenerateInvoice(shopping_cart);

  EXPECT_STREQ(kInvoice, s.c_str());
}

