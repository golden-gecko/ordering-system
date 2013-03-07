#pragma once

//------------------------------------------------------------------------------

struct Order
{
    unsigned int product;
    unsigned int customer;
    float quantity;
};

//------------------------------------------------------------------------------

extern unsigned int orderNumber;

//------------------------------------------------------------------------------

extern Order* orders;

//------------------------------------------------------------------------------

void displayOrders();
void addOrder();
void editOrder();
void deleteOrder();
