//
// Created by dominik on 5/20/19.
//

#include "Program.h"

void Program::execute() {
    mainFunction.execute();
}

Program::~Program() {

}

Program::Program(MainFunction mainFunction):mainFunction(mainFunction) {

}
