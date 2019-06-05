cmake_minimum_required(VERSION 3.13)
project(Domino)

file(GLOB_RECURSE Headers *.h)
file(GLOB_RECURSE Sources *cpp)

find_package(Boost)

link_directories ( ${Boost_LIBRARY_DIRS} )

add_executable(Domino main.cpp Source.cpp Source.h Scanner.cpp Scanner.h ScanDef.h Parser.cpp Parser.h ast/Function.cpp ast/Function.h ast/MainFunction.cpp ast/MainFunction.h ast/Statements/VariableDeclaration.cpp ast/Statements/VariableDeclaration.h ast/Statements/ArrayDeclaration.cpp ast/Statements/ArrayDeclaration.h ast/Expression/Factor/Factor.cpp ast/Expression/Factor/Factor.h ast/Expression/SimpleExpression.cpp ast/Expression/SimpleExpression.h ast/Statements/WriteInStatement.cpp ast/Statements/WriteInStatement.h ast/Statements/WriteOutStatement.cpp ast/Statements/WriteOutStatement.h ast/Expression/Expression.cpp ast/Expression/Expression.h ast/Statements/Assignment.cpp ast/Statements/Assignment.h ast/Statements/ConditionalStatement.cpp ast/Statements/ConditionalStatement.h ast/Statements/ForStatement.cpp ast/Statements/ForStatement.h ast/Statements/ReturnStatement.cpp ast/Statements/ReturnStatement.h ast/Variable.cpp ast/Variable.h ast/Expression/Condition.cpp ast/Expression/Condition.h ast/Expression/ConditionalExpression.cpp ast/Expression/ConditionalExpression.h ast/ParametersDefinition.cpp ast/ParametersDefinition.h ast/Statements/Statement.cpp ast/Statements/Statement.h ast/Statements/IfStatement.cpp ast/Statements/IfStatement.h ast/Statements/WhileStatement.cpp ast/Statements/WhileStatement.h ast/Program.cpp ast/Program.h Scope.cpp Scope.h Token.cpp Token.h ast/Content.cpp ast/Content.h ast/Node/Node.cpp ast/Node/Node.h Rational.cpp Rational.h ast/Expression/Factor/ValueFactor.cpp ast/Expression/Factor/ValueFactor.h ast/Expression/Factor/ExpressionFactor.cpp ast/Expression/Factor/ExpressionFactor.h ast/Expression/Factor/factors.h)
add_library(DominoLib STATIC ${Headers} ${Sources})
