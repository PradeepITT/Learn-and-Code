#include "ProductCatalog.h"
#include "InventoryManager.h"
#include "CustomExceptions.h"
#include <iostream>
#include <limits> // for clearing input buffer
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    ProductCatalog catalog;
    InventoryManager manager;

    int choice;
    bool exitProgram = false;

    do {
        try {
            cout << "Main Menu:\n";
            cout << "1. Add Product\n";
            cout << "2. Update Product\n";
            cout << "3. Delete Product\n";
             cout << "4. Sell Product\n";
            cout << "5. Display Inventory\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int id;
                    string name;
                    float price;
                    int quantity;

                    cout << "Enter product ID: ";
                    if (!(cin >> id)) {
                        throw InvalidInputException(); 
                    }
                    clearInputBuffer();

                    cout << "Enter product name: ";
                    getline(cin, name);

                    cout << "Enter product price: ";
                    if (!(cin >> price) || price < 0) {
                        throw InvalidInputException(); 
                    }
                    clearInputBuffer();

                    cout << "Enter product quantity: ";
                    if (!(cin >> quantity) || quantity < 0) {
                        throw InvalidInputException(); 
                    }
                    clearInputBuffer();

                    catalog.addProduct(Product(id, name, price, quantity));
                    cout << "Product added successfully.\n";
                    break;
                }
                case 2: {
                    int id;
                    float price;
                    int quantity;

                    cout << "Enter product ID to update: ";
                    if (!(cin >> id)) {
                        throw InvalidInputException(); 
                    }
                    clearInputBuffer();

                    cout << "Enter new price: ";
                    if (!(cin >> price) || price < 0) {
                        throw InvalidInputException(); 
                    }
                    clearInputBuffer();

                    cout << "Enter new quantity: ";
                    if (!(cin >> quantity) || quantity < 0) {
                        throw InvalidInputException(); 
                    }
                    clearInputBuffer();

                    catalog.updateProduct(id, price, quantity);
                    cout << "Product updated successfully.\n";
                    break;
                }
                case 3: {
                    int id;
                    cout << "Enter product ID to delete: ";
                    if (!(cin >> id)) {
                        throw InvalidInputException(); 
                    }
                    clearInputBuffer();

                    catalog.deleteProduct(id);
                    cout << "Product deleted successfully.\n";
                    break;
                }
                case 4: {
                    int id;
                    int quantity;

                    cout << "Enter product ID to sell: ";
                    if (!(cin >> id)) {
                        throw InvalidInputException(); 
                    }
                    clearInputBuffer();

                    cout << "Enter quantity to sell: ";
                    if (!(cin >> quantity) || quantity <= 0) {
                        throw InvalidInputException(); 
                    }
                    clearInputBuffer();

                    catalog.sellProduct(id, quantity); 
                    cout << "Product sold successfully.\n";
                    break;
                }
                case 5:
                    manager.displayInventory(catalog);
                    break;
                case 6:
                    cout << "Exiting...\n";
                    exitProgram = true;
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const InvalidInputException& e) {
            cerr << "Invalid input data: " << e.what() << endl;
            clearInputBuffer();
        } catch (const ProductNotFoundException& e) {
            cerr << "Product not found: " << e.what() << endl;
        } catch (const InsufficientQuantityException& e) {
            cerr << "Insufficient quantity: " << e.what() << endl;
        } catch (const DuplicateProductException& e) {
            cerr << "Duplicate product: " << e.what() << endl;
        } catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;
        }

    } while (!exitProgram);

    return 0;
}
