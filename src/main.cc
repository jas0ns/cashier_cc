

int main(int argc, char **argv) {
  Shop s("thoughtworks");
  Commodity_Map *commodity_map = Init_Commodity_Map("../config/commodities.json");
  Shopping_Cart *shopping_cart = Init_Shopping_Cart(commodity_map);
  string invoice = s.GenerateInvoice(shopping_cart); 

  std::cout << invoice << std::endl;

  
  return 0;
}
