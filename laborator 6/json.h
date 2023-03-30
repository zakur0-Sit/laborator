#include <iostream>
#include <string>
#include <vector>
#include <map>

class JsonValue {
public:
    virtual ~JsonValue() {}

    virtual void print(std::ostream& out, int indent = 0) const = 0;
};

class NullValue : public JsonValue {
public:
    void print(std::ostream& out, int indent = 0) const override;
};

class NumberValue : public JsonValue {
public:
    NumberValue(int value) : value_(value) {}

    void print(std::ostream& out, int indent = 0) const override;

private:
    int value_;
};

class BoolValue : public JsonValue {
public:
    BoolValue(bool value) : value_(value) {}

    void print(std::ostream& out, int indent = 0) const override;

private:
    bool value_;
};

class StringValue : public JsonValue {
public:
    StringValue(const std::string& value) : value_(value) {}

    void print(std::ostream& out, int indent = 0) const override;

private:
    std::string value_;
};

class ArrayValue : public JsonValue {
public:
    ArrayValue() {}

    ~ArrayValue();

    void add(JsonValue* value);

    void print(std::ostream& out, int indent = 0) const override;

private:
    std::vector<JsonValue*> values_;
};

class ObjectValue : public JsonValue {
public:
    ObjectValue() {}

    ~ObjectValue();

    void add(const std::string& name, JsonValue* value);

    void print(std::ostream& out, int indent = 0) const override;

    operator unsigned() const {
        return pairs_.size();
    }

private:
    std::vector<std::pair<std::string, JsonValue*>> pairs_;
};
