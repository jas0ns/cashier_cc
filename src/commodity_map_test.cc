#include <string>

#include "gtest/gtest.h"

#include "commodity_map.h"
#include "commodity.h"
#include "shopping_item.h"
#include "promotions.h"

const std::string kCommoditiesConfigDir("../config/commodities.json");
const std::string kAppleBarcode("ITEM000001");
const std::string kCocaColaBarcode("ITEM000002");
const std::string kBadMintonBarcode("ITEM000003");
const std::string kBeefBarcode("ITEM000004");

TEST(CommodityMap, InitCommodityMapFromDirForNormalAttributes) {
  Commodity_Map commodity_map; 
  commodity_map.Init_Commodity_Map_From_Dir(kCommoditiesConfigDir);

  EXPECT_STREQ("苹果", 
      commodity_map.get_commodity_by_barcode(
        kAppleBarcode)->name().c_str());
  EXPECT_DOUBLE_EQ(3.00, 
      commodity_map.get_commodity_by_barcode(
        kCocaColaBarcode)->price());
  EXPECT_STREQ("运动器材", 
      commodity_map.get_commodity_by_barcode(
        kBadMintonBarcode)->category().c_str());
}

TEST(CommodityMap, InitCommodityMapFromDirForPromotions) {
  Commodity_Map commodity_map;
  commodity_map.Init_Commodity_Map_From_Dir(kCommoditiesConfigDir);
  Commodity *apple = 
      commodity_map.get_commodity_by_barcode(kAppleBarcode);
  Commodity *cocacola = 
      commodity_map.get_commodity_by_barcode(kCocaColaBarcode);
  Commodity *beef = 
      commodity_map.get_commodity_by_barcode(kBeefBarcode);
  
  EXPECT_TRUE(apple->promotions());
  EXPECT_FALSE(cocacola->promotions());
  EXPECT_TRUE(beef->promotions());
}

