//
// Created by dominik on 5/20/19.
//

#include "Content.h"
#include <list>
#include <algorithm>

void Content::execute(std::list<Function> functions) {
    for(Statement i: statements){
        i.execute();
    }
}

Content::Content() {
//    statements=std::list<Statement> statements;

}

/*Content::Content(Scope &scope):scope(scope) {

}*/

void Content::addStatement(Statement statement) {
    statements.push_back(statement);
}
