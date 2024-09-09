/*Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class 
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books. 
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program 
should be menu driven and should not cause memory leakage. 
Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3] */

#include <iostream>
using namespace std;

class products
{
protected:

    int id;
    string title;
    double price;
    static int _id;
    
public:
    products()
    {
        id= 0;
        title = "";
        price = 0;
        
    }

    products(string title, int price) 
    {
        id= 0;
        title = "";
        price = 0;
      
    }

    virtual void newproduct()
    {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter products: ";
    };
   

    virtual void displayproductdetails()
    {
        cout << "................." << endl;
        cout << "id: " << id << endl;
        cout << "title: " << title << endl;
        cout << "price: " << price << endl;
        cout << "................." << endl;
    }

    virtual double getDiscountedPrice() {
        return price;
    }
};

class book : public products
{
    protected:
     string author;
   

public:
 void newproduct()
{
    products::newproduct();
    cout << "Enter Author: ";
    cin>> author;

}
double getDiscountedPrice() {
        return price * 0.90; // 10% discount on books

}

    void displayproductdetails()
    {
        products::displayproductdetails();
       cout << "Author: " << author;
       cout << "Discounted Price: $" << getDiscountedPrice() << endl;
    }

};

class tape : public products
{
    string artist;
    
public:

    void displayproductdetails()
    {
    products::displayproductdetails();
    
    }

    double getDiscountedPrice()  {
        return price * 0.95; // 5% discount on tapes
    }
    void newproduct()
    {
        products::newproduct();
        cout << "Enter Artist: ";
        cin >> artist;
        cout << "Discounted Price: $" << getDiscountedPrice() << endl;
    }
};
int main()
{   
    products* arr[3];
    int choice;
    int count=0;
    double totalBill = 0.0;
    do
    {
        
        cout << "\nMenu:\n";
        cout << "1. Add a new product (Book or Tape)\n";
        cout << "2. Display all products and calculate total bill\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int productType;
            cout << "Enter product type (1 for Book, 2 for Tape): ";
            cin >> productType;

            if (productType == 1) {
            arr[count] = new book();  // Create a Book object
            } else if (productType == 2) {
            arr[count] = new tape();  // Create a Tape object
            } else {
            cout << "Invalid product type. Try again.\n";
            continue;
            }

            arr[count]->newproduct();  // Accept details for the chosen product
                    count++;
    
            cout << "You can only add 3 products.\n";
                
           
            break;

        case 2:
                totalBill = 0.0;
                cout << "\nProduct Details:\n";
                for (int i = 0; i < count; i++) {
                    arr[i]->displayproductdetails();
                    totalBill += arr[i]->getDiscountedPrice();
                }
                cout << "\nTotal Bill: $" << totalBill << endl;
                break;

        case 3:
                cout << "Exiting...\n";
                break;
        default:
        
                cout << "Invalid choice. Try again.\n";
            break;
        }

    } while (choice != 3);
    for (int i = 0; i < count; i++) {
        delete arr[i];
    }
}

