//
// Created by dominik on 5/20/19.
//

#include "MainFunction.h"

void MainFunction::execute(/*std::list<Function> otherFunctions*/) {//will probably need to fix it later;
    //functions=std::move(otherFunctions);
    content.execute();
}

MainFunction::MainFunction(){

}

MainFunction::~MainFunction() {

}

MainFunction::MainFunction(Content content):content(content) {

}
