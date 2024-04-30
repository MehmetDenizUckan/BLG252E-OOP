#include <iostream>
#include <string>  

using namespace std;

const int n = 5;  

class product {
public:
  string name;  
  float price;

  product() {}
  product(string n, float p) : name(n), price(p) {}
};

class customer {
public:
  string customer_name;
  float credit_card_limit;
  product list_of_ordered_products[n];  
  int count_of_ordered_products;

  customer(string cname, float cclimit = 1000.0f) : customer_name(cname), credit_card_limit(cclimit), count_of_ordered_products(0) {}

  float calculate_total_debt() {
    float total_debt = 0.0f;
    for (int i = 0; i < count_of_ordered_products; ++i) {
      total_debt += list_of_ordered_products[i].price;
    }
    return total_debt;
  }

  void print() {
    cout << "Customer Name: " << customer_name << endl;
    cout << "Credit Card Limit: $" << credit_card_limit << endl;
    cout << "Count of Ordered Products: " << count_of_ordered_products << endl;
    cout << "List Ordered Products:" << endl;
    for (int i = 0; i < count_of_ordered_products; ++i) {
      cout << "Name: "<< list_of_ordered_products[i].name <<"\t\t" << "Price : " << list_of_ordered_products[i].price << endl;
    }
    cout <<"Total Debt: "<< calculate_total_debt() <<endl;
    cout <<"**************************************************************************************************************"<< endl;
  }

  void operator+(product P) {
    // Constraint 2: Check if maximum product limit is reached
    if (count_of_ordered_products >= n) {
      cout << "Warning: Cannot add more products. Limit reached." << endl;
      cout << "Product add operation is not done\n"<<endl;
      return;
    }

    // Constraint 1: Calculate total debt after adding
    float total_debt_after_addition = calculate_total_debt() + P.price;

    
    if (total_debt_after_addition > credit_card_limit) {
      cout << "Total debt exceeds credit card limit." << endl;
      cout << "Product add operation is not done\n"<<endl;
      return;
    }

    list_of_ordered_products[count_of_ordered_products++] = P;
    cout << "Added Product:"<<P.name<<endl;
    cout << "Product is added to the customer succesfully:\n"<<endl;
  }
};

int main() {
  customer j("John Fisher", 2000.0f);
  customer r("Ronald Craig");
  customer t("Thomas Austin", 750.0f);

  j + product("Panasonic Phone", 800.0f);
  j + product("Toshiba Battery", 400.0f);
  j + product("Kenwook DVD", 300.0f);

  j.print();

  r + product("Canon Battery", 500.0f);
  r + product("Nikon Accesory", 600.0f);
  r + product("Yamaha Subwoofer", 200.0f);

  r.print();

  t + product("Whirlpool Charger", 90.0f);
  t + product("Logitec Remote", 20.0f);
  t + product("LG Dryer", 100.0f);
  t + product("Linksys Router", 60.0f);
  t + product("Nintendo Portable", 150.0f);
  t + product("Mitsubshi Stand", 200.0f);

  
  t.print();


  return 0;
}
