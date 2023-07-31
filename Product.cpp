#include "Product.h"


std::ostream &operator<<(std::ostream &os, const Product &rhs) {
    os << "productId: " << rhs.productId
       << " productName: " << rhs.productName
       << " productPrice: " << rhs.productPrice;
    return os;
}


Product::Product(std::variant<std::string, int> id, std::string name, float price)
{
}

Product::~Product()
{
}
