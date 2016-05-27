#include <string>

#include "commodity.h"
#include "gtest/gtest.h"

const char kCommodities_config_dir[] = "../config/commodities.json"

TEST(CommodityMap, InitCommodityMap) {
  Shop shop(kShopName); 
  shop.init_commodities(kCommodities_config_dir);
  EXPECT_STREQ("苹果", shop.commodities()["ITEM000001"]->name());
  EXPECT_EQ(3.00, shop.commodities()["ITEM000002"]->price());
  EXPECT_STREQ("运动器材", shop.commodities()["ITEM000003"]->category());
  EXPECT_TRUE(shop.commodities()["ITEM000004"]->promotions() == NULL);
}

