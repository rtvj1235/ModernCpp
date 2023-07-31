#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<memory>
#include<variant>

class Product
{
    private:
        std::variant<std::string,int> productId;
        std::string productName;
        float productPrice;

    public:
        Product()=delete;
        Product(Product& obj)=delete;
        Product(Product&& obj)=delete;
        Product(std::variant<std::string, int> id, std::string name, float price);
        ~Product();

        std::variant<std::string,int> getProductId() const { return productId; }
        void setProductId(const std::variant<std::string,int> &productId_) { productId = productId_; }

        std::string getProductName() const { return productName; }
        void setProductName(const std::string &productName_) { productName = productName_; }

        float getProductPrice() const { return productPrice; }
        void setProductPrice(float productPrice_) { productPrice = productPrice_; }

        friend std::ostream &operator<<(std::ostream &os, const Product &rhs);

        
};

#endif // PRODUCT_H
