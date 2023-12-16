#include <iostream>
#include <string>

class TextInput {
protected:
    std::string value = "";

public:
    virtual void add(char c) {
        value += c;
    }

    std::string getValue() const {
        return value;
    }
};

class NumericInput : public TextInput {
public:
    void add(char c) override {
        if (c >= '0' && c <= '9') {
            TextInput::add(c);
        }
    }
};

#ifndef RunTests
int main() {
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
    delete input; // Don't forget to free memory allocated by 'new'
}
#endif