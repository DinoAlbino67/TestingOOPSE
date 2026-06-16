#include "Node.h"
#include <iostream>

Node::Node(QObject* parent, const QString& name, std::function<Data(const Data&)> action_func)
    : QObject(parent), action(action_func) {
    setObjectName(name);
}

std::string Node::to_string() const {
    std::string result = objectName().toStdString() + " [" + value.data_type + "]: ";
    for (double v : value.values) {
        result += std::to_string(v) + " ";
    }
    return result;
}

void Node::set_value(const Data& data) {
    value = data;
    std::cout << to_string() << std::endl;
    value = action(value);
    std::cout << to_string() << std::endl;
    emit value_changed(value);
}