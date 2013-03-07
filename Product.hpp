#pragma once

//------------------------------------------------------------------------------

struct Product
{
    char name[256];
    float price;
    float discount;
};

//------------------------------------------------------------------------------

extern unsigned int productNumber;

//------------------------------------------------------------------------------

extern Product* products;

//------------------------------------------------------------------------------

void displayCustomers();
void addCustomer();
void editCustomer();
void deleteCustomer();
