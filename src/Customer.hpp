#pragma once

//------------------------------------------------------------------------------

struct Customer
{
    char name[256];
    char address[256];
};

//------------------------------------------------------------------------------

extern unsigned int customerNumber;

//------------------------------------------------------------------------------

extern Customer* customers;

//------------------------------------------------------------------------------

void displayProducts();
void addProduct();
void editProduct();
void deleteProduct();
