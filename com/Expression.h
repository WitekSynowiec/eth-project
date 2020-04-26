//
// Created by Witold Synowiec on 27/04/2020.
//

#ifndef ETHWORKS_ZADANIE_EXPRESSION_H
#define ETHWORKS_ZADANIE_EXPRESSION_H


#include <vector>
#include "Variable.h"

/**
 * Expression class stores Variable instances in itself. It contains one member field
 * which is vector of variables.
 */
class Expression {
public:
    std::vector<Variable> expression;

    explicit Expression(std::string &);

/**
 *
 * @param q is an expression to be added at the end of this class vector
 * @return this pointer
 */
    Expression operator+(Expression &);

private:
/**
* method regroup is a private method that kinda sorts and merge elements of vector
* meaning if two variables have the same exponent and name they can be merged
*/
    void regroup();
};


#endif //ETHWORKS_ZADANIE_EXPRESSION_H
