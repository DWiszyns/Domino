//
// Created by dominik on 5/20/19.
//

#include "MainFunction.h"

void MainFunction::execute() {
    //functions=std::move(otherFunctions);
    content.execute();
}

MainFunction::MainFunction(){

}

MainFunction::~MainFunction() {

}

MainFunction::MainFunction(Content content):content(content) {

}

Content MainFunction::getContent() {
    return content;
}
