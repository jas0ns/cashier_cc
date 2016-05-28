#include <string>

#include "gtest/gtest.h"

#include "commodity_map.h"
#include "commodity.h"

const std::string kCommoditiesConfigDir("../config/commodities.json");
const std::string kAppleBarcode("ITEM000001");
const std::string kCocaColaBarcode("ITEM000002");
const std::string kBadMintonBarcode("ITEM000003");

TEST(CommodityMap, InitCommodityMapFromDir) {
  Commodity_Map commodity_map; 
  commodity_map.Init_Commodity_Map_From_Dir(kCommoditiesConfigDir);

  EXPECT_STREQ("苹果", 
      commodity_map.get_commodity_by_barcode(kAppleBarcode)->name().c_str());
  EXPECT_DOUBLE_EQ(3.00, 
      commodity_map.get_commodity_by_barcode(kCocaColaBarcode)->price());
  EXPECT_STREQ("运动器材", 
      commodity_map.get_commodity_by_barcode(kBadMintonBarcode)->category().c_str());

}

