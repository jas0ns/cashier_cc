#include "shopping_cart.h"
#include "gtest/gtest.h"

TEST(Shop, ConstructorFromCString) {
  const Shopping_Item si(kShopName);
  EXPECT_EQ(0, strcmp(si.getName(), kShopName));
}

TEST(Shopping_Cart, CalculateAllowance) {

}

TEST(Shopping_Cart, TotalSave) {

}

TEST(Shopping_Cart, RebateList) {

}

TEST(Shopping_Cart, Details) {

}

TEST(Shopping_Cart, Rebate) {

}

TEST(Shopping_Cart, Total) {

}
