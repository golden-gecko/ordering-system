#include <iostream>

//------------------------------------------------------------------------------

#include "Customer.hpp"

//------------------------------------------------------------------------------

unsigned int customerNumber = 0;

//------------------------------------------------------------------------------

Customer* customers = NULL;

//------------------------------------------------------------------------------

void displayCustomers()
{
    std::cout << "Customer list\n\n";

    if (customerNumber)
    {
        for (unsigned int i = 0; i < customerNumber; i++)
        {
            std::cout
                << "Customer\t" << i
                << "\nName\t\t" << customers[i].name
                << "\nAddress\t\t" << customers[i].address
                << "\n\n";
        }
    }
    else
    {
        std::cout << "No customers found in database.\n\n";
    }

    std::cout << "Press Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}

void addCustomer()
{
    if (customers)
    {
        Customer* newCustomers = new Customer[++customerNumber];

        for (unsigned int i = 0; i < customerNumber - 1; i++)
        {
            newCustomers[i] = customers[i];
        }

        delete[] customers;

        customers = newCustomers;
    }
    else
    {
        customers = new Customer[++customerNumber];
    }

    std::cout << "Add new customer\n\n";

    std::cout << "Type customer name:    ";
    std::cin >> customers[customerNumber - 1].name;

    std::cout << "Type customer address:    ";
    std::cin >> customers[customerNumber - 1].address;

    std::cout
        << "\nCustomer has been added to database.\n\n"
        << "Press Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}

void editCustomer()
{
    unsigned int id;

    std::cout
        << "Edit customer\n\n"
        << "Type customer ID: ";
    std::cin >> id;

    if (customerNumber)
    {
        if (id > customerNumber - 1)
        {
            std::cout << "\nCustomer not found.";
        }
        else
        {
            std::cout << "\nType customer name:    ";
            std::cin >> customers[id].name;

            std::cout << "Type customer address    ";
            std::cin >> customers[id].address;

            std::cout << "\nCustomer has been updated.";
        }
    }
    else
    {
        std::cout << "\nNo customers in database.";
    }

    std::cout << "\n\nPress Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}

void deleteCustomer()
{
    unsigned int id;

    std::cout
        << "Delete customer\n\n"
        << "Type customer ID: ";
    std::cin >> id;

    if (customerNumber)
    {
        if (id > customerNumber - 1)
        {
            std::cout << "\nCustomer not found." << std::endl;
        }
        else
        {
            Customer* newCustomers = new Customer[customerNumber - 1];
            unsigned int newCustomerNumber = 0;

            for (unsigned int i = 0; i < customerNumber; i++)
            {
                if (i != id)
                {
                    strcpy(newCustomers[newCustomerNumber].name, customers[i].name);
                    strcpy(newCustomers[newCustomerNumber].address, customers[i].address);

                    newCustomerNumber++;
                }
            }

            delete[] customers;
            customers = newCustomers;
            customerNumber--;

            std::cout << "\nCustomer has been deleted.";
        }
    }
    else
    {
        std::cout << "\nNo customers in database.";
    }

    std::cout << "\n\nPress Enter to continue." << std::endl;

    std::cin.get();
    std::cin.get();
}
