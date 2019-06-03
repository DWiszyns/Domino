
//
// Created by dominik on 5/20/19.
//

#include "ParametersDefinition.h"

ParametersDefinition::ParametersDefinition() = default;

ParametersDefinition::~ParametersDefinition() = default;

ParametersDefinition::ParametersDefinition(std::vector<Variable> parameters):parameters(std::move(parameters)) {

}

std::vector<Variable> ParametersDefinition::getParameters() {
    return parameters;
}

Variable ParametersDefinition::getParameter(unsigned int i) {
    return parameters[i];
}

TypeKind ParametersDefinition::getParameterType(unsigned int i) {
    return parameters[i].getNode().getTypeKind();
}

ParametersDefinition::ParametersDefinition(const ParametersDefinition &parametersDefinition)= default;
