cmake_minimum_required(VERSION 3.13)
project(Domino)

file(GLOB_RECURSE Headers *.h)
file(GLOB_RECURSE Sources *cpp)

find_package(Boost)

link_directories ( ${Boost_LIBRARY_DIRS} )

add_executable(Domino main.cpp Source.cpp Source.h Scanner.cpp Scanner.h ScanDef.h Parser.cpp Parser.h ast/Function.cpp ast/Function.h ast/MainFunction.cpp ast/MainFunction.h ast/VariableDeclaration.cpp ast/VariableDeclaration.h ast/ArrayDeclaration.cpp ast/ArrayDeclaration.h ast/Factor.cpp ast/Factor.h ast/SimpleExpression.cpp ast/SimpleExpression.h ast/WriteInStatement.cpp ast/WriteInStatement.h ast/WriteOutStatement.cpp ast/WriteOutStatement.h ast/Expression.cpp ast/Expression.h ast/Assignment.cpp ast/Assignment.h ast/ConditionalStatement.cpp ast/ConditionalStatement.h ast/ForStatement.cpp ast/ForStatement.h ast/ReturnStatement.cpp ast/ReturnStatement.h ast/Variable.cpp ast/Variable.h ast/Condition.cpp ast/Condition.h ast/ConditionalExpression.cpp ast/ConditionalExpression.h ast/ParametersDefinition.cpp ast/ParametersDefinition.h ast/Statement.cpp ast/Statement.h ast/IfStatement.cpp ast/IfStatement.h ast/WhileStatement.cpp ast/WhileStatement.h ast/Program.cpp ast/Program.h Scope.cpp Scope.h Token.cpp Token.h ast/Content.cpp ast/Content.h ast/Node/Node.cpp ast/Node/Node.h ast/Node/StringNode.cpp ast/Node/StringNode.h ast/Node/CharNode.cpp ast/Node/CharNode.h ast/Node/FloatNode.cpp ast/Node/FloatNode.h ast/Node/RationalNode.cpp ast/Node/RationalNode.h ast/Node/BooleanNode.cpp ast/Node/BooleanNode.h ast/Node/ArrayNode.cpp ast/Node/ArrayNode.h Rational.cpp Rational.h ast/Node/IntNode.cpp ast/Node/IntNode.h ast/Array.cpp ast/Array.h)
add_library(DominoLib STATIC ${Headers} ${Sources} ast/Function.cpp ast/Function.h)
