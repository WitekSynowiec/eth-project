//
// Created by Witold Synowiec on 27/04/2020.
//

#include "Expression.h"
    Expression::Expression(std::string& input)
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
    Expression Expression::operator + ( Expression &q) {
        expression.insert(expression.end(), q.expression.begin(), q.expression.end());
        regroup();
        return *this;
    };


    void Expression::regroup()
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
