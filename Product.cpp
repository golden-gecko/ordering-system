#include <iostream>

//------------------------------------------------------------------------------

#include "Product.hpp"

//------------------------------------------------------------------------------

unsigned int productNumber = 0;

//------------------------------------------------------------------------------

Product* products = NULL;

//------------------------------------------------------------------------------

void displayProducts()
{
    std::cout << "Product list\n\n";

    if (productNumber)
    {
        for (unsigned int i = 0; i < productNumber; i++)
        {
            std::cout
                << "Product\t\t" << i
                << "\nName\t\t" << products[i].name
                << "\nPrice\t\t" << products[i].price
                << "\nDiscount\t" << products[i].discount
                << "\n\n";
        }
    }
    else
    {
        std::cout << "No products found in database.\n\n";
    }

    std::cout << "Press Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}

void addProduct()
{
    if (products)
    {
        Product* newProducts = new Product[++productNumber];

        for (unsigned int i = 0; i < productNumber - 1; i++)
        {
            newProducts[i] = products[i];
        }

        delete[] products;

        products = newProducts;
    }
    else
    {
        products = new Product[++productNumber];
    }

    std::cout << "Add new product\n\n";

    std::cout << "Type product name:    ";
    std::cin >> products[productNumber - 1].name;

    std::cout << "Type product price:    ";
    std::cin >> products[productNumber - 1].price;

    std::cout << "Type product discount:    ";
    std::cin >> products[productNumber - 1].discount;

    std::cout
        << "\nProduct has been added to database.\n\n"
        << "Press Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}

void editProduct()
{
    unsigned int id;

    std::cout
        << "Edit product\n\n"
        << "Type product ID: ";
    std::cin >> id;

    if (productNumber)
    {
        if (id > productNumber - 1)
        {
            std::cout << "\nProduct not found.";
        }
        else
        {
            std::cout << "\nType product name:    ";
            std::cin >> products[id].name;

            std::cout << "Type product price:    ";
            std::cin >> products[id].price;

            std::cout << "Type product discount:    ";
            std::cin >> products[id].discount;

            std::cout << "\nProduct has been updated.";
        }
    }
    else
    {
        std::cout << "\nNo products in database.";
    }

    std::cout << "\n\nPress Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}

void deleteProduct()
{
    unsigned int id;

    std::cout
        << "Delete product\n\n"
        << "Type product ID: ";
    std::cin >> id;

    if (productNumber)
    {
        if (id > productNumber - 1)
        {
            std::cout << "\nProduct not found." << std::endl;
        }
        else
        {
            Product* newProducts = new Product[productNumber - 1];
            unsigned int newProductNumber = 0;

            for (unsigned int i = 0; i < productNumber; i++)
            {
                if (i != id)
                {
                    strcpy(newProducts[newProductNumber].name, products[i].name);
                    newProducts[newProductNumber].price = products[i].price;
                    newProducts[newProductNumber].discount = products[i].discount;

                    newProductNumber++;
                }
            }

            delete[] products;
            products = newProducts;
            productNumber--;

            std::cout << "\nProduct has been deleted.";
        }
    }
    else
    {
        std::cout << "\nNo products in database.";
    }

    std::cout << "\n\nPress Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}
