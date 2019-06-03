//
// Created by dominik on 5/20/19.
//

#ifndef DOMINO_PARAMETERSDEFINITION_H
#define DOMINO_PARAMETERSDEFINITION_H


#include "Variable.h"
#include <utility>

class ParametersDefinition {
    std::vector<Variable> parameters;
public:
    ParametersDefinition();
    explicit ParametersDefinition(std::vector<Variable> parameters);
    ParametersDefinition(const ParametersDefinition& parametersDefinition);
    ~ParametersDefinition();
    std::vector<Variable> getParameters();
    Variable getParameter(unsigned int i);
    TypeKind getParameterType(unsigned int i);
};


#endif //DOMINO_PARAMETERSDEFINITION_H
