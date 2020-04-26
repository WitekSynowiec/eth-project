/**
 * @author Witek Synowiec
 * zadanie rekrutacyjne Ethworks
 */
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>



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
     explicit Variable(const std::string& input) {
        int dot_pos = -1, first_char = -1, pow_pos = -1;
        for (int i = 0; i<input.length();i++)
        {
            if (dot_pos==-1&&(input[i]=='.'))
                dot_pos = i;
            if (first_char==-1&&isalpha(input[i]))
                first_char = i;
            if (pow_pos==-1&&input[i]=='^')
                pow_pos = i;
        }
        if (first_char==1&&input[0]=='-')
            multi_num=-1;
        else
        {
            std::stringstream m_num(input.substr(0,first_char));
            m_num >> multi_num;
        }
        if (pow_pos!=-1)
        {
            std::stringstream p_num(input.substr(pow_pos+1));
            p_num >> pow_num;
        }
        try {
            var_name = input.substr(first_char,pow_pos-first_char);
        }
        catch (std::out_of_range) {
            std::cout<<"Out of range. Propably used non alpha char in expression."<<std::endl;
        }



    }

/**
 *
 * @param q is a variable to compare.
 * @return true if names AND expotentials of two compared objects are equal.
 */
    bool operator== ( Variable &q) const {
        return var_name == q.var_name && pow_num == q.pow_num;
    };
public:

};


/**
 * Expression class stores Variable instances in itself. It contains one member field
 * which is vector of variables.
 */
class Expression {
public:
    std::vector<Variable> expression;
     explicit  Expression(std::string& input)
    {
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
        int plus_pos, old_pos = 0, i; bool pm = false;
        for (i=0;i<input.length();i++)
        {
            if (input[i]=='+'||(input[i]=='-'&&i!=0&&input[i-1]!='^')){
                plus_pos = i;
                if (pm)
                {
                    std::string a = input.substr(old_pos, plus_pos-old_pos);
                    a.insert(0,"-");
                    Variable x = Variable(a);
                    expression.push_back(x);
                } else{
                    Variable x = Variable(input.substr(old_pos, plus_pos-old_pos));
                    expression.push_back(x);
                }
                old_pos = i+1;
                pm = input[i] != '-' ? false : true;
            }
        }
        plus_pos = i;
        if (pm)
        {
            std::string a = input.substr(old_pos, plus_pos-old_pos);
            a.insert(0,"-");
            Variable x = Variable(a);
            expression.push_back(x);
        } else{
            Variable x = Variable(input.substr(old_pos, plus_pos-old_pos));
            expression.push_back(x);
        }
        regroup();
    }
/**
 *
 * @param q is an expression to be added at the end of this class vector
 * @return this pointer
 */
    Expression operator + ( Expression &q) {
        expression.insert(expression.end(), q.expression.begin(), q.expression.end());
        regroup();
        return *this;
    };
private:
    /**
     * method regroup is a private method that kinda sorts and merge elements of vector
     * meaning if two variables have the same exponent and name they can be merged
     */
    void regroup()
    {
        for (auto it = expression.begin(); it < expression.end(); ++it)
        {
            for(auto it2 = it+1; it2 < expression.end(); ++it2){
                if (*it==*it2)
                {
                    it->multi_num+=it2->multi_num;
                    expression.erase(it2);
                    if (it->multi_num==0)
                        expression.erase(it);
                }
            }
        }
    }
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

/**
 *
 * @param fir first expression to compare
 * @param sec second expression to compare
 * @return merged and arranged in right order expression
 */
std::string addExpression(std::string& fir, std::string& sec)
{
    Expression x =  Expression(fir);
    Expression x2 = Expression(sec);
    x = x+x2;
    std::string result;
    std::string num;

    for(auto & i : x.expression)
    {
        if (i.getMultiNum()>=0) result.append("+");
        if (i.getMultiNum()!=1)
        {
            num = std::to_string(i.getMultiNum());
            num.erase ( num.find_last_not_of('0') + 1, std::string::npos );
            num.erase ( num.find_last_not_of('.') + 1, std::string::npos );
            result.append(num);
        }
        result.append(i.getVarName());
        if (i.getPowNum()!=1)
        {
            result.append("^");
            num = std::to_string(i.getPowNum());
            num.erase ( num.find_last_not_of('0') + 1, std::string::npos );
            num.erase ( num.find_last_not_of('.') + 1, std::string::npos );
            result.append(num);
        }



    }
    if (result[0]=='+')
        return result.substr(1,result.length());
    else
        return result;

}

void test()
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


int main() {
    test();
    return 0;
}
