/**
 * @author Witek Synowiec
 * zadanie rekrutacyjne Ethworks
 */
#include <iostream>
#include <string>
#include "addExpression.h"


void menu()
{
    std::string expr1;
    std::string expr2;

    while (true)
    {
        std::cout<<"Welcome in test function!"<<std::endl;
        std::cout<<"To stop type 'end'"<<std::endl;
        std::cout<<"Insert expression 1: ";
        std::cin>>expr1;
        if (expr1 == "end") break;
        std::cout<<"Insert expression 2: ";
        std::cin>>expr2;
        if (expr2 == "end") break;
        std::cout<<std::endl<<expr1<<std::endl<<expr2<<std::endl;
        std::cout<<addExpression(expr1,expr2)<<std::endl;
    }
}

//DO NOT UNCOMMENT DURING TESTING
//int main(){
//    return 0;
//}


