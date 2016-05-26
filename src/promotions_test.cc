#include "gtest/gtest.h"

#include "promotions.h"

const int type = 0x00000001;
const string name("单品打折");
const string arguments("0.8");
const double subtotal = 100.0;
const double allowance = 0.0;

TEST(Promotions, GetPromotionsInstance) {
  Shopping_Item shopping_item;
  shopping_item.subtotal = subtotal;
  shopping_item.allowance = allowance;
  Promotions *promotions = GetPromotionsInstance(type, name, arguments);
  promotions->CalculatePromotions(&shopping_item);

  EXPECT_EQ(80.0, shopping_item.subtotal);
  EXPECT_EQ(20.0, shopping_item.allowance);
}
