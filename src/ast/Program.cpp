//
// Created by dominik on 5/20/19.
//

#include "Program.h"

int Program::execute() {
    mainFunction.execute(functions);
    return a+b;

}

Program::~Program() {
}

Program::Program(int a, int b):a(a),b(b) {

}
