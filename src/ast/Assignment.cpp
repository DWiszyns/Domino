//
// Created by dominik on 5/20/19.
//

#include "Assignment.h"

void Assignment::execute() {
    lvalue=rvalue.execute()

    Statement::execute();
}

Assignment::Assignment(Variable &lvalue, Expression rvalue):lvalue(lvalue),rvalue(rvalue) {

}
