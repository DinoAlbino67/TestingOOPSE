#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QString>
#include <functional>
#include "Data.h"

class Node : public QObject {
    Q_OBJECT
private:
    Data value;
    std::function<Data(const Data&)> action;

public:
    Node(QObject* parent, const QString& name, std::function<Data(const Data&)> action_func);
    std::string to_string() const;

public slots:
    void set_value(const Data& data);

signals:
    void value_changed(const Data& data);
};

#endif