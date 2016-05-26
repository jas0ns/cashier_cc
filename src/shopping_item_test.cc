#include "shopping_item.h"
#include "gtest/gtest.h"

TEST(Shopping_Item, SetMembers) {
  Shopping_Item shopping_item;
  shopping_item.set_commodity(NULL);
  shopping_item.set_amount(5);
  shopping_item.set_subtotal(100.0);
  shopping_item.set_allowance(20.0);

  EXCEPT_EQ(NULL, shopping_item.commodity());
  EXCEPT_EQ(5, shopping_item.amount());
  EXCEPT_EQ(100.0, shopping_item.totalPrice());
  EXPECT_EQ(20.0, shopping_item.allowance());
}

