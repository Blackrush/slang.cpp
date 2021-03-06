/**
 * Antoine Chauvin © Slang
 */

#ifndef SLANG_INTEGER_HPP
#define SLANG_INTEGER_HPP

#include "../Expression.hpp"

class Integer : public Expression {
public:
    typedef long long integer_t;

    const integer_t integer;

    Integer(integer_t integer) : integer(integer) {}

    virtual std::string getName() const { return "INTEGER"; }
    virtual Expressions getType() const { return Expressions::INTEGER; }

    virtual std::unique_ptr<const Expression> copy() const {
        return std::unique_ptr<const Expression>(new Integer(integer));
    }

    virtual bool coerceBoolean() const { return integer != 0; }
};

#endif //SLANG_INTEGER_HPP
