#include "shop.h"
#include "gtest/gtest.h"

const char kShopName[] = "ThoughtWorks"

TEST(Shop, ConstructorFromCString) {
  const Shop si(kShopName);
  EXPECT_EQ(0, strcmp(si.getName(), kShopName));
}

TEST(Shop, InitCommodities) {

}

TEST(Shop, InitPromotions) {

}

TEST(Shop, InitShoppingCart) {

}


TEST(Shop, PrintInvoice) {

}
