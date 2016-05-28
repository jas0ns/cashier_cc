#include <stdlib.h>

#include <string>
#include <iostream>
#include <fstream>
#include <iterator>

#include "cJSON.h"

#include "commodity_map.h"
#include "commodity.h"
#include "promotions.h"

void Commodity_Map::Init_Commodity_Map_From_Dir(
    const std::string& commodity_config_dir) {
  std::ifstream in(commodity_config_dir.c_str());
  if (!in.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    exit(1);
  }

  std::istreambuf_iterator<char> begin(in), end;
  std::string *commodities = new std::string(begin, end);
  in.close();


  cJSON* jsonRoot = cJSON_Parse(commodities->c_str());
  if (!jsonRoot) {
    std::cerr << "Wrong format of Config file" << std::endl;
  }
  cJSON* commodity_array_json = cJSON_GetObjectItem(jsonRoot, "commodities");
  cJSON* commodity_json = commodity_array_json->child;
  while (commodity_json) {
    Commodity *commodity = new Commodity();
    commodity->set_barcode(std::string(cJSON_GetObjectItem(
          commodity_json, "barcode")->valuestring));
    commodity->set_name(std::string(cJSON_GetObjectItem(
          commodity_json, "name")->valuestring));
    commodity->set_unit(std::string(cJSON_GetObjectItem(
          commodity_json, "unit")->valuestring));
    commodity->set_category(std::string(cJSON_GetObjectItem(
          commodity_json, "category")->valuestring));
    commodity->set_subCategory(std::string(cJSON_GetObjectItem(
          commodity_json, "subCategory")->valuestring));
    commodity->set_price(cJSON_GetObjectItem(
          commodity_json, "price")->valuedouble);

    cJSON* promotions_json = cJSON_GetObjectItem(commodity_json, "promotions");
    if (promotions_json) {
      int type = cJSON_GetObjectItem(promotions_json, "type")->valueint;
      std::string name = std::string(
          cJSON_GetObjectItem(promotions_json, "name")->valuestring);
      std::string arguments = std::string(
          cJSON_GetObjectItem(promotions_json, "arguments")->valuestring);
      Promotions *promotions = 
          Promotions::GetPromotionsInstance(type, name, arguments);
      commodity->set_promotions(promotions);
    }

    commodity_map_[commodity->barcode()] = commodity;

    commodity_json = commodity_json->next;
  }
}

Commodity* Commodity_Map::get_commodity_by_barcode(
      const std::string& barcode) {
  return commodity_map_[barcode];
}

