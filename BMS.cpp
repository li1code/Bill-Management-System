#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100;
const int MAX_BILLS = 100;

class Product {
public:
    string name;
    double price;
    int quantity; // Added quantity

    Product() : name(""), price(0.0), quantity(0) {}
};

class Bill {
public:
    Product products[MAX_PRODUCTS];
    int productCount;
    double total;

    Bill() : productCount(0), total(0.0) {}

    void addProduct(const Product& product) {
        if (productCount < MAX_PRODUCTS) {
            products[productCount] = product;
            total += product.price * product.quantity; // Multiply price by quantity
            productCount++;
        } else {
            cout << "Cannot add more products to the bill." << endl;
        }
    }

    void displayBill() {
        cout << "Bill Details:\n";
        for (int i = 0; i < productCount; ++i) {
            cout << products[i].name << " - $" << products[i].price 
                 << " x " << products[i].quantity 
                 << " = $" << (products[i].price * products[i].quantity) << endl;
        }
        cout << "Total: $" << total << endl;
    }
};

class BillManagementSystem {
private:
    Product productDatabase[MAX_PRODUCTS];
    int productCount;
    Bill bills[MAX_BILLS];
    int billCount;
    const string databaseFile = "products.txt";

public:
    BillManagementSystem() : productCount(0), billCount(0) {
        loadProductsFromFile();
    }

    void addProductToDatabase(const string& name, double price) {
        if (productCount < MAX_PRODUCTS) {
            productDatabase[productCount].name = name;
            productDatabase[productCount].price = price;
            productCount++;
            cout << "Product added: " << name << " - $" << price << endl;
            saveProductsToFile();
        } else {
            cout << "Product database is full." << endl;
        }
    }

    void generateBill() {
        Bill bill;
        string productName;
        double productPrice;
        int productQuantity;

        cout << "Enter products for the bill (type 'done' to finish):" << endl;
        while (true) {
            cout << "Product Name: ";
            cin >> productName;
            if (productName == "done") break;

            cout << "Product Price: ";
            cin >> productPrice;

            cout << "Quantity: ";
            cin >> productQuantity;

            Product product;
            product.name = productName;
            product.price = productPrice;
            product.quantity = productQuantity;
            bill.addProduct(product);
        }

        if (bill.productCount > 0) {
            bills[billCount++] = bill;
            cout << "Bill generated successfully!" << endl;
            bill.displayBill();
        } else {
            cout << "No products added to the bill." << endl;
        }
    }

    void deleteBill(int billIndex) {
        if (billIndex < 0 || billIndex >= billCount) {
            cout << "Invalid bill index!" << endl;
            return;
        }
        for (int i = billIndex; i < billCount - 1; ++i) {
            bills[i] = bills[i + 1];
        }
        billCount--;
        cout << "Bill deleted successfully!" << endl;
    }

    void displayBills() {
        if (billCount == 0) {
            cout << "No bills to display." << endl;
            return;
        }

        for (int i = 0; i < billCount; ++i) {
            cout << "Bill " << i + 1 << ":\n";
            bills[i].displayBill();
            cout << endl;
        }
    }

    void loadProductsFromFile() {
        ifstream inFile(databaseFile);
        if (inFile.is_open()) {
            string name;
            double price;
            while (inFile >> name >> price) {
                if (productCount < MAX_PRODUCTS) {
                    productDatabase[productCount].name = name;
                    productDatabase[productCount].price = price;
                    productCount++;
                } else {
                    cout << "Product database is full, cannot load more products from file." << endl;
                    break;
                }
            }
            inFile.close();
            cout << "Products loaded from file successfully!" << endl;
        } else {
            cout << "Could not open file: " << databaseFile << ". Starting with an empty database." << endl;
        }
    }

    void saveProductsToFile() {
        ofstream outFile(databaseFile);
        if (outFile.is_open()) {
            for (int i = 0; i < productCount; ++i) {
                outFile << productDatabase[i].name << " " << productDatabase[i].price << endl;
            }
            outFile.close();
            cout << "Products saved to file successfully!" << endl;
        } else {
            cout << "Error saving products to file!" << endl;
        }
    }
};

int main() {
    BillManagementSystem system;
    int choice;

    while (true) {
        cout << "\nBill Management System Menu:\n";
        cout << "1. Add Product to Database\n";
        cout << "2. Generate Bill\n";
        cout << "3. Delete Bill\n";
        cout << "4. Display All Bills\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                double price;
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product price: ";
                cin >> price;
                system.addProductToDatabase(name, price);
                break;
            }
            case 2:
                system.generateBill();
                break;
            case 3: {
                int index;
                cout << "Enter bill index to delete: ";
                cin >> index;
                system.deleteBill(index - 1);
                break;
            }
            case 4:
                system.displayBills();
                break;
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
