#include "gtest/gtest.h"

#include "rebate_promotions.h"

const char[] kRebatePromotions = "单品打折商品";

TEST(RebatePromotions, Constructor) {
  Promotions promotions = new RebatePromotions(kRebatePromotions);
  ASSERT_STREQ(kRebatePromotions, promotions.name());
}

TEST(RebatePromotions, CalculatePromotions) {
  Commodity commodity;
  Shopping_Item shopping_item;
  shopping_item.setCommodity(commodity);
  commodity.set_price(5.0);
  shopping_item.amount = 2;
  shopping_item.totalPrice = 10.0;
  Promotions *promotions = new RebatePromotions(kRebatePromotions);
  promotions->percent = 0.8;
  promotions.calculatePromotions(shopping_item);
  EXCEPT_EQ(8.0, shopping_item.totalPrice);
  EXCEPT_EQ(2.0, shopping_item.allowance);
}
