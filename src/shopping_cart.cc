#include <stdlib.h>

#include <string>
#include <list>
#include <iterator>
#include <iostream>
#include <fstream>
#include <iterator>

#include "cJSON.h"

#include "shopping_cart.h"
#include "shopping_item.h"
#include "commodity_map.h"
#include "commodity.h"
#include "promotions.h"

void Shopping_Cart::InitShoppingCartFromString(
    const std::string& str, Commodity_Map* commodity_map) {
  cJSON* jsonRoot = cJSON_Parse(str.c_str());
  if (!jsonRoot) {
    std::cerr << "Wrong format of Config file" << std::endl;
  }

  // count commodity amount for every barcode entry
  for (int i=0; i < cJSON_GetArraySize(jsonRoot); ++i) {
    std::string barcode_str = cJSON_GetArrayItem(jsonRoot, i)->valuestring;
    std::string barcode(barcode_str.c_str(), 10);
    int amount = 1;
    if (barcode_str.length() > 10) {
      amount = atoi(std::string(barcode_str, 11).c_str());
    }
    
    count_map_[barcode] += amount;
  }

  // init shopping_item list
  std::map<std::string, int>::iterator i = count_map_.begin();
  while (i != count_map_.end()) {
    Shopping_Item *shopping_item = new Shopping_Item();
    shopping_item->set_commodity(
        commodity_map->get_commodity_by_barcode(i->first));
    shopping_item->set_amount(i->second);
    shopping_item_list_.push_back(shopping_item);
    ++i;
  }
}

void Shopping_Cart::InitShoppingCartFromFile(
    const std::string& dir, Commodity_Map* commodity_map) {
}

void Shopping_Cart::CalculateTotalPriceAndAllowance() {
  double total_price = 0.0;
  double total_allowance = 0.0;
  std::list<Shopping_Item*>::iterator i = shopping_item_list_.begin();
  while (i != shopping_item_list_.end()) {
    Shopping_Item *shopping_item = *i;
    // calculate origin price
    shopping_item->set_subtotal(
        shopping_item->commodity()->price() * shopping_item->amount());

    // calculate promotions
    if (shopping_item->commodity()->promotions()) {
      shopping_item->commodity()->promotions()
          ->CalculatePromotions(shopping_item);
    }

    total_price += shopping_item->subtotal();
    total_allowance += shopping_item->allowance();
    ++i;
  }
  this->total_price_ = total_price;
  this->total_allowance_ = total_allowance;
}


