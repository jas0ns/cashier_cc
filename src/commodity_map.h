#ifndef CASHIER_COMMODITY_MAP_
#define CASHIER_COMMODITY_MAP_

#include <string>
#include <map>

class Commodity;

class Commodity_Map {
 public:
  Commodity_Map() {}
  ~Commodity_Map() {};
  void Init_Commodity_Map_From_Dir(const std::string&);
  Commodity* get_commodity_by_barcode(const std::string&);

 private:
  std::map<std::string, Commodity*> commodity_map_;
};

#endif // CASHIER_COMMODITY_MAP_

