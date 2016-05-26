#include <string>

#include "commodity.h"
#include "gtest/gtest.h"

const char kBarcode[] = "ITEM000000";
const char kName[] = "可口可乐";
const char kUnit[] = "瓶";
const char kCategory[] = "食品";
const char kSubCategory[] = "碳酸饮料";
const double kPrice = 3.00;

TEST(Commodity, SetMembers) {
  Commodity commodity;
  commodity.set_barcode(kBarcode);
  commodity.set_name(kName);
  commodity.set_unit(kUnit);
  commodity.set_category(kCategory);
  commodity.set_subCategory(kSubCategory);
  commodity.set_price(kPrice);

  EXPECT_STREQ(kBarcode, commodity.barcode().c_str());
  EXPECT_STREQ(kName, commodity.name().c_str());
  EXPECT_STREQ(kUnit, commodity.unit().c_str());
  EXPECT_STREQ(kCategory, commodity.category().c_str());
  EXPECT_STREQ(kSubCategory, commodity.subCategory().c_str());
  EXPECT_EQ(kPrice, commodity.price());
}
