#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "Content.h"
#include "Function.h"
#include "Statements/WriteOutStatement.h"
#include <list>
#include <algorithm>
#include "Statements/IfStatement.h"
#include "Statements/WhileStatement.h"


void Content::execute() {
    for(auto &i: statements){
        i->execute();
    }
}

Content::Content() {

}

/*Content::Content(Scope &scope):scope(scope) {

}*/

Content::~Content() {

}


Content::Content(std::list<std::unique_ptr<Statement>> statements, Scope *scope):statements(std::move(statements)),scope(std::move(scope)) {

}


Content::Content(Content &otherContent):statements(std::move(otherContent.statements)),scope(otherContent.scope) {

}

Content::Content(const Content &otherContent):scope(std::move(otherContent.scope)){
    for(const auto &n:otherContent.statements)
        if(dynamic_cast<Assignment*>(n.get()) != nullptr)
            statements.push_back(std::make_unique<Assignment>(*(dynamic_cast<Assignment*>(n.get()))));
        else if(dynamic_cast<WriteOutStatement*>(n.get()) != nullptr)
            statements.push_back(std::make_unique<WriteOutStatement>(*(dynamic_cast<WriteOutStatement*>(n.get()))));
        else if(dynamic_cast<VariableDeclaration*>(n.get()) != nullptr)
            statements.push_back(std::make_unique<VariableDeclaration>(*(dynamic_cast<VariableDeclaration*>(n.get()))));
        else if(dynamic_cast<IfStatement*>(n.get()) != nullptr)
            statements.push_back(std::make_unique<IfStatement>(*(dynamic_cast<IfStatement*>(n.get()))));
        else if(dynamic_cast<WhileStatement*>(n.get()) != nullptr)
            statements.push_back(std::make_unique<WhileStatement>(*(dynamic_cast<WhileStatement*>(n.get()))));
        else
            statements.push_back(std::make_unique<Statement>(*n));
}

Scope Content::getScope() {
    return *scope;
}

void Content::setScope(Scope scope) {
    this->scope=&scope;
}

