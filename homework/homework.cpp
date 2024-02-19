#include "pattern.h"

int main()
{
    Builder* builder = new Builder();
    Director* director = new Director(builder);

    director->buildMinimal();
    cout << "Minimal" << endl;
    Product* product = builder->getProduct();
    product->ListParts();
    delete product;

    director->buildMedium();
    cout << "Medium" << endl;
    product = builder->getProduct();
    product->ListParts();
    delete product;

    director->buildFull();
    cout << "Full" << endl;
    product = builder->getProduct();
    product->ListParts();
    delete product;

    cout << "Custom" << endl;
    builder->produceComponent1();
    builder->produceComponent3();
    product = builder->getProduct();
    product->ListParts();
    delete product;

    delete builder;
    delete director;

    return 0;
}