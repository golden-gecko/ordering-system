#include <iostream>

//------------------------------------------------------------------------------

#include "Order.hpp"

//------------------------------------------------------------------------------

unsigned int orderNumber = 0;

//------------------------------------------------------------------------------

Order* orders = NULL;

//------------------------------------------------------------------------------

void displayOrders()
{
    std::cout << "Order list\n\n";

    if (orderNumber)
    {
        for (unsigned int i = 0; i < orderNumber; i++)
        {
            std::cout
                << "Order\t\t" << i
                << "\nProduct\t\t" << orders[i].product
                << "\nCustomer\t" << orders[i].customer
                << "\nQuantity\t" << orders[i].quantity
                << "\n\n";
        }
    }
    else
    {
        std::cout << "No orders found in database.\n\n";
    }

    std::cout << "Press Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}

void addOrder()
{
    if (orders)
    {
        Order* newOrders = new Order[++orderNumber];

        for (unsigned int i = 0; i < orderNumber - 1; i++)
        {
            newOrders[i] = orders[i];
        }

        delete[] orders;

        orders = newOrders;
    }
    else
    {
        orders = new Order[++orderNumber];
    }

    std::cout << "Add new order\n\n";

    std::cout << "Type product ID:    ";
    std::cin >> orders[orderNumber - 1].product;

    std::cout << "Type customer ID:    ";
    std::cin >> orders[orderNumber - 1].customer;

    std::cout << "Type product quantity:    ";
    std::cin >> orders[orderNumber - 1].quantity;

    std::cout
        << "\nOrder has been added to database.\n\n"
        << "Press Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}

void editOrder()
{
    unsigned int id;

    std::cout
        << "Edit order\n\n"
        << "Type order ID: ";
    std::cin >> id;

    if (orderNumber)
    {
        if (id > orderNumber - 1)
        {
            std::cout << "\nOrder not found.";
        }
        else
        {
            std::cout << "\nType product ID:    ";
            std::cin >> orders[id].product;

            std::cout << "Type customer ID    ";
            std::cin >> orders[id].customer;

            std::cout << "Type product quantity    ";
            std::cin >> orders[id].customer;

            std::cout << "\nOrder has been updated.";
        }
    }
    else
    {
        std::cout << "\nNo orders in database.";
    }

    std::cout << "\n\nPress Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}

void deleteOrder()
{
    unsigned int id;

    std::cout
        << "Delete order\n\n"
        << "Type order ID: ";
    std::cin >> id;

    if (orderNumber)
    {
        if (id > orderNumber - 1)
        {
            std::cout << "\nOrder not found." << std::endl;
        }
        else
        {
            Order* newOrders = new Order[orderNumber - 1];
            unsigned int newOrderNumber = 0;

            for (unsigned int i = 0; i < orderNumber; i++)
            {
                if (i != id)
                {
                    orders[newOrderNumber++] = orders[i];
                }
            }

            orders = newOrders;
            orderNumber--;

            std::cout << "\nOrder has been deleted.";
        }
    }
    else
    {
        std::cout << "\nNo orders in database.";
    }

    std::cout << "\n\nPress Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}
