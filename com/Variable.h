//
// Created by Witold Synowiec on 27/04/2020.
//

#ifndef ETHWORKS_ZADANIE_VARIABLE_H
#define ETHWORKS_ZADANIE_VARIABLE_H


#include <string>

/**
 * Class Variable stores singular variables with its coefficients and exponents.
 * It contains three class members including
 * @param multi_num stores storing coefficient
 * @param var_name storing name of a variable
 * @param pow_num that stores exponent.
 *
 * It was decided that class would be
 * wholly private as there is no need to get particular variable outside of
 * Expression class usage.
 *
 * It has only one explicit constructor that requires string storing expression
 * to be stored in the class.
 */
class Variable {
    friend class Expression;

    double multi_num = 1;
public:
    double getMultiNum() const;

    const std::string &getVarName() const;

    double getPowNum() const;

private:
    std::string var_name;
    double pow_num = 1;

/**
*
* @param input requires string storing expression to be stored in the class members.
*/
    explicit Variable(const std::string &input);

/**
 *
 * @param q is a variable to compare.
 * @return true if names AND expotentials of two compared objects are equal.
 */
    bool operator==(Variable &q) const;
};


#endif //ETHWORKS_ZADANIE_VARIABLE_H
