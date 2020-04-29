//
// Created by Witold Synowiec on 27/04/2020.
//

#include <sstream>
#include <iostream>
#include "Variable.h"

Variable::Variable(const std::string &input) {
    int dot_pos = -1, first_char = -1, pow_pos = -1;
    for (int i = 0; i < input.length(); i++) {
        if (dot_pos == -1 && (input[i] == '.'))
            dot_pos = i;
        if (first_char == -1 && isalpha(input[i]))
            first_char = i;
        if (pow_pos == -1 && input[i] == '^')
            pow_pos = i;
    }
    if (first_char == 1 && input[0] == '-')
        multi_num = -1;
    else {
        std::stringstream m_num(input.substr(0, first_char));
        m_num >> multi_num;
    }
    if (pow_pos != -1) {
        std::stringstream p_num(input.substr(pow_pos + 1));
        p_num >> pow_num;
    }
    try {
        var_name = input.substr(first_char, pow_pos - first_char);
    }
    catch (std::out_of_range) {
//        std::cout << "Out of range. Propably used non alpha char in expression." << std::endl;
    }


}

bool Variable::operator==(Variable &q) const {
    return var_name == q.var_name && pow_num == q.pow_num;
};

double Variable::getMultiNum() const {
    return multi_num;
}

const std::string &Variable::getVarName() const {
    return var_name;
}

double Variable::getPowNum() const {
    return pow_num;
}