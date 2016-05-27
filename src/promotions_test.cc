#include <string>
#include <iostream>

#include "gtest/gtest.h"

#include "shopping_item.h"
#include "promotions.h"

const char type = 0x00;
const std::string name("单品打折");
const std::string arguments("0.8");
const double subtotal = 100.0;
const double allowance = 0.0;

TEST(RebatePromotions, CalculateRebatePromotions) {
  Shopping_Item shopping_item;
  shopping_item.set_subtotal(subtotal);
  shopping_item.set_allowance(allowance);
  Promotions *promotions = Promotions::GetPromotionsInstance(type, name, arguments);
  promotions->CalculatePromotions(&shopping_item);

  EXPECT_DOUBLE_EQ(80.0, shopping_item.subtotal());
  EXPECT_DOUBLE_EQ(20.0, shopping_item.allowance());
}
