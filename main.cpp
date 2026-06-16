#include <QCoreApplication>
#include "Node.h"
#include "Data.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    auto generator_lambda = [](const Data& d) {
        return d;
    };

    auto p11_lambda = [](const Data& d) {
        Data result = d;
        for (double& v : result.values) {
            v *= 2.0;
        }
        return result;
    };

    auto p12_lambda = [](const Data& d) {
        Data result = d;
        for (double& v : result.values) {
            v = v * v;
        }
        return result;
    };

    auto p21_lambda = [](const Data& d) {
        Data result = d;
        for (double& v : result.values) {
            v += 10.0;
        }
        return result;
    };

    auto p22_lambda = [](const Data& d) {
        Data result = d;
        for (double& v : result.values) {
            v -= 5.0;
        }
        return result;
    };

    Node* generator = new Node(&a, "Generator", generator_lambda);
    Node* processor_1_1 = new Node(generator, "Processor_1_1", p11_lambda);
    Node* processor_1_2 = new Node(processor_1_1, "Processor_1_2", p12_lambda);
    Node* processor_2_1 = new Node(generator, "Processor_2_1", p21_lambda);
    Node* processor_2_2 = new Node(processor_2_1, "Processor_2_2", p22_lambda);

    QObject::connect(generator, &Node::value_changed, processor_1_1, &Node::set_value);
    QObject::connect(processor_1_1, &Node::value_changed, processor_1_2, &Node::set_value);
    QObject::connect(generator, &Node::value_changed, processor_2_1, &Node::set_value);
    QObject::connect(processor_2_1, &Node::value_changed, processor_2_2, &Node::set_value);

    Data test_data;
    test_data.data_type = "Test_Dataset";
    test_data.values = {1.0, 2.0, 3.0, 4.0};

    generator->set_value(test_data);

    return 0;
}