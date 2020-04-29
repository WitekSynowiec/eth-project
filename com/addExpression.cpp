//
// Created by Witold Synowiec on 27/04/2020.
//

#include "addExpression.h"
#include "Expression.h"

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
        if (i.getMultiNum()!=1&&i.getMultiNum()!=-1)
        {
            num = std::to_string(i.getMultiNum());
            num.erase ( num.find_last_not_of('0') + 1, std::string::npos );
            num.erase ( num.find_last_not_of('.') + 1, std::string::npos );
            result.append(num);
        }
        if (i.getMultiNum()==-1){
            result.append("-");
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