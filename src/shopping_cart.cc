#include <stdlib.h>

#include <string>
#include <list>
#include <map>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
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
    exit(1);
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
  
  cJSON_Delete(jsonRoot);

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

/* TODO
void Shopping_Cart::InitShoppingCartFromFile(
    const std::string& dir, Commodity_Map* commodity_map) {
}
*/

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

void Shopping_Cart::GenerateInvoiceParts() {
  std::list<Shopping_Item*>::iterator i = shopping_item_list_.begin();
  std::ostringstream oss;
  oss.precision(2);
  oss.setf(std::ios::fixed);
  while (i != shopping_item_list_.end()) {
    Shopping_Item *shopping_item = *i;
    Commodity *commodity = shopping_item->commodity();
    // generate details part
    oss.str("");
    oss << "名称:" << commodity->name()
        << "，数量：" << shopping_item->amount() << commodity->unit()
        << "，单价：" << commodity->price() << "（元）"
        << "，小计：" << shopping_item->subtotal() << "（元）";
    if (shopping_item->allowance() != 0.0) {
      oss << "，优惠：" << shopping_item->allowance() << "（元）";
    } 
    oss << "\n";
    details_part_ += oss.str();
    // generate promotions part
    if (commodity->promotions()) {
      int promotions_type = commodity->promotions()->get_type();
      if (promotions_map_.end() == promotions_map_.find(promotions_type)) {
        promotions_map_[promotions_type] = 
          commodity->promotions()->get_name() + "：";
      } 
      oss.str("");
      oss << "名称：" << commodity->name()
        << "，" << commodity->promotions()->get_print()
        << " ";
      promotions_map_[promotions_type] += oss.str();
    }

    ++i;
  }

  oss.str("");
  std::map<int, std::string>::iterator it = promotions_map_.begin();
  while (it != promotions_map_.end()) {
    promotions_part_ += (*it).second; 
    ++it;
  }

  // summary part
  oss.str("");
  oss << "总计：" << this->total_price_ << "（元）";
  if (this->total_allowance_ > 0) {
    oss << "节省：" << this->total_allowance_ << "（元）";
  }
  summary_part_ += oss.str();
}



