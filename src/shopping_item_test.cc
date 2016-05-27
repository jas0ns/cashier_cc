#include "shopping_item.h"
#include "gtest/gtest.h"

TEST(Shopping_Item, SetMembers) {
  Shopping_Item shopping_item;
  shopping_item.set_commodity(NULL);
  shopping_item.set_amount(5);
  shopping_item.set_subtotal(100.0);
  shopping_item.set_allowance(20.0);

  EXPECT_EQ(NULL, shopping_item.commodity());
  EXPECT_EQ(5, shopping_item.amount());
  EXPECT_EQ(100.0, shopping_item.subtotal());
  EXPECT_EQ(20.0, shopping_item.allowance());
}

