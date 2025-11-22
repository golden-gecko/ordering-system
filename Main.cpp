#include <fstream>
#include <iostream>

//------------------------------------------------------------------------------

#include "Customer.hpp"
#include "Order.hpp"
#include "Product.hpp"

//------------------------------------------------------------------------------

void loadData()
{
    std::ifstream in("data\\products.bin", std::ios::binary);

    in.seekg(0, std::ios::end);
    unsigned int size = (unsigned int)in.tellg();
    in.seekg(0, std::ios::beg);

    products = new Product[productNumber = size / sizeof(Product)];

    for (unsigned int i = 0; i < size / sizeof(Product); i++)
    {
        in.read((char*)&products[i], sizeof(Product));
    }

    in.close();

    in.open("data\\customers.bin", std::ios::binary);

    in.seekg(0, std::ios::end);
    size = (unsigned int)in.tellg();
    in.seekg(0, std::ios::beg);

    customers = new Customer[customerNumber = size / sizeof(Customer)];

    for (unsigned int i = 0; i < size / sizeof(Customer); i++)
    {
        in.read((char*)&customers[i], sizeof(Customer));
    }

    in.close();

    in.open("data\\orders.bin", std::ios::binary);

    in.seekg(0, std::ios::end);
    size = (unsigned int)in.tellg();
    in.seekg(0, std::ios::beg);

    orders = new Order[orderNumber = size / sizeof(Order)];

    for (unsigned int i = 0; i < size / sizeof(Order); i++)
    {
        in.read((char*)&orders[i], sizeof(Order));
    }

    in.close();
}

void saveData()
{
    std::ofstream out("data\\products.bin", std::ios::binary);

    for (unsigned int i = 0; i < productNumber; i++)
    {
        out.write((char*)&products[i], sizeof(Product));
    }

    out.close();

    out.open("data\\customers.bin", std::ios::binary);

    for (unsigned int i = 0; i < customerNumber; i++)
    {
        out.write((char*)&customers[i], sizeof(Customer));
    }

    out.close();

    out.open("data\\orders.bin", std::ios::binary);

    for (unsigned int i = 0; i < orderNumber; i++)
    {
        out.write((char*)&orders[i], sizeof(Order));
    }

    out.close();
}

//------------------------------------------------------------------------------

int main()
{
    char c;

    loadData();

    do
    {
        system("cls");

        std::cout
            << "Simple Oil Order System\n\n"
            << "a - Display products\n"
            << "b - Add product\n"
            << "c - Edit product\n"
            << "d - Delete product\n\n"
            << "e - Display customers\n"
            << "f - Add customer\n"
            << "g - Edit customer\n"
            << "h - Delete customer\n\n"
            << "i - Display orders\n"
            << "j - Add order\n"
            << "k - Edit order\n"
            << "l - Delete order\n\n"
            << "m - Quit\n\n"
            << "Type letter from 'a' do 'm' and press Enter to confirm: ";

        c = std::cin.get();

        system("cls");

        switch (c)
        {
            case 'a': displayProducts(); break;
            case 'b': addProduct(); break;
            case 'c': editProduct(); break;
            case 'd': deleteProduct(); break;
            case 'e': displayCustomers(); break;
            case 'f': addCustomer(); break;
            case 'g': editCustomer(); break;
            case 'h': deleteCustomer(); break;
            case 'i': displayOrders(); break;
            case 'j': addOrder(); break;
            case 'k': editOrder(); break;
            case 'l': deleteOrder(); break;
        }
    }
    while (c != 'm');

    saveData();

    if (products)
    {
        delete[] products;
    }

    if (customers)
    {
        delete[] customers;
    }

    if (orders)
    {
        delete[] orders;
    }

    return 0;
}
