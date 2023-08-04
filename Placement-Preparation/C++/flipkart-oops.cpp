#include<iostream>
#include<vector>
using namespace std;

class Product {
    protected:
    int prod_id;
    int category_id;
    string name;
    double price;
    int quantity;
    
public:
   explicit Product(int prod_id,int category_id,string name,double price,int quantity)
   {
         this->prod_id=prod_id;
         this->category_id=category_id;
         this->name=name;
         this->price=price;
         this->quantity=quantity;
   }  

   int getProductId() const
   {
     return prod_id;
   }
   int getCategoryId() const 
   {
    return category_id;
   }
   double getPrice() const 
   {
    return price;
   }
   int getQuantity() const{
    return quantity;
   }

   double get_total_price(){
    return price*quantity;
   }
};

class ShoppingCart {
    private:
    vector<Product> products;

    public:

    void add_product(Product product){
        this->products.push_back(product);
    }

    bool remove_product(const int category_id, const int product_id)
    {
        for(auto it = products.begin(); it != products.end(); ++it)
        {
            if(it->getCategoryId()==category_id and it->getProductId() == product_id)
            {
                 products.erase(it);
                 return true;
            }
        }
        return  false;
    }

    double calculate_total()
    {
        double total=0;
        for(const auto& product:products)
        {
            total+=product.getPrice()*product.getQuantity();
        }
        return total;
    }
};

class User{
    private:
    string name;
    string email;
    ShoppingCart shopping_cart;

    public: 
    User(string name,string email)
    {
        this->name=name;
        this->email=email;
    }

    void add_to_cart(Product product)
    {
        shopping_cart.add_product(product);
    }

    void remove_from_cart(Product product)
    {
        shopping_cart.remove_product(product.getCategoryId(),product.getProductId());
    }

    void checkout()
    {
        double total_amount=shopping_cart.calculate_total();
        cout << "Total amount to pay: " << total_amount << endl;
        // Implement payment and order processing logic here
        shopping_cart = ShoppingCart();  // Clear the cart after checkout
    }
};

int main()
{
    // int prod_id,int category_id,string name,double price,int quantity

    Product product1(1,1,"Smartphone",500,1);
    Product product2(2,1,"Laptop",100,1);
    Product product3(2,1,"Soap",10,1);

     // Create a user
    User user1("John Doe", "john@example.com");

    // Add products to the user's cart
    user1.add_to_cart(product1);
    user1.add_to_cart(product2);
    user1.add_to_cart(product3);

    // Calculate and print the total amount
     user1.checkout();

    return 0;
}