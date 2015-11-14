/**
 * Antoine Chauvin © Slang
 */

#ifndef SLANG_INTERPRETER_HPP
#define SLANG_INTERPRETER_HPP

#include <map>
#include "Expression.hpp"
#include "Expressions/List.hpp"
#include "Expressions/Function.hpp"
#include "Expressions/Set.hpp"

class InterpreterContext {
public:
    typedef std::map<std::string, std::unique_ptr<const Expression>> map_t;

    InterpreterContext();
    InterpreterContext(const InterpreterContext* parent);

    const Expression& get(const std::string& key) const;
    void set(const std::string& key, std::unique_ptr<const Expression> value);

private:
    const InterpreterContext* parent;
    map_t map;
};

class Interpreter : public InterpreterContext {
public:
    typedef Function<Interpreter> Fun;
    typedef NativeFunction<Interpreter> NaFun;

    Interpreter();
    Interpreter(const InterpreterContext* parent);
    virtual ~Interpreter();

    std::unique_ptr<const Expression> interpret(const Expression& exp);

private:
    std::unique_ptr<const Expression> accessSet(const std::string& key, const List::values_t& values);
    std::unique_ptr<const Expression> callFunction(const List::values_t& values);

    std::unique_ptr<const Expression> let(const List::values_t& parameters);
};

std::string toString(const Expression& exp);

std::unique_ptr<const Expression> print(Interpreter& context, const List::values_t& parameters);
std::unique_ptr<const Expression> println(Interpreter& context, const List::values_t& parameters);
std::unique_ptr<const Expression> readln(Interpreter& context, const List::values_t& parameters);
std::unique_ptr<const Expression> plus(Interpreter& context, const List::values_t& parameters);

#endif //SLANG_INTERPRETER_HPP
