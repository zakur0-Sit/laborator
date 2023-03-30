#include "json.h"

ObjectValue::~ObjectValue() {
    for (auto pair : pairs_) {
        delete pair.second;
    }
}

void ObjectValue::add(const std::string& name, JsonValue* value) {
    pairs_.push_back(std::make_pair(name, value));
}

void ObjectValue::print(std::ostream& out, int indent) const {
    out << '{';
    if (pairs_.size() > 0) {
        out << '\n';
        for (auto pair : pairs_) {
            out << std::string(indent + 2, ' ') << '"' << pair.first << "\": ";
            pair.second->print(out, indent + 2);
            if (&pair != &pairs_.back()) {
                out << ',';
            }
            out << '\n';
        }
        out << std::string(indent, ' ');
    }
    out << '}';
}

ArrayValue::~ArrayValue() {
    for (auto value : values_) {
        delete value;
    }
}

void ArrayValue::add(JsonValue* value) {
    values_.push_back(value);
}

void ArrayValue::print(std::ostream& out, int indent) const {
    out << '[';
    if (values_.size() > 0) {
        out << '\n';
        for (auto value : values_) {
            out << std::string(indent + 2, ' ');
            value->print(out, indent + 2);
            if (value != values_.back()) {
                out << ',';
            }
            out << '\n';
        }
        out << std::string(indent, ' ');
    }
    out << ']';
}

void StringValue::print(std::ostream& out, int indent) const {
    out << '"' << value_ << '"';
}

void BoolValue::print(std::ostream& out, int indent) const {
    out << (value_ ? "true" : "false");
}

void NumberValue::print(std::ostream& out, int indent) const {
    out << value_;
}

void NullValue::print(std::ostream& out, int indent) const {
    out << "null";
}
