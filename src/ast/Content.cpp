#include <utility>

//
// Created by dominik on 5/20/19.
//

#include "Content.h"
#include "Function.h"
#include <list>
#include <algorithm>

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
        statements.push_back(std::make_unique<Statement>(*n));

}

