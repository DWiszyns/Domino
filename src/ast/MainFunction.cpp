//
// Created by dominik on 5/20/19.
//

#include "MainFunction.h"

void MainFunction::execute(std::list<Function> &functions) {
    this->functions=functions;
    content.execute(functions);

}

MainFunction::MainFunction(){

}

MainFunction::~MainFunction() {

}
