#pragma once

#include <string>
#include <odb/core.hxx>

#pragma db object
class Person
{
public:
    Person() = {}

    Person(const std::string& name, int age)
            : name_(name), age_(age) {}

    const std::string& name() const { return name_; }
    int age() const { return age_; }

private:
    friend class odb::access;

#pragma db id auto
    int id_;
    std::string name_;
    int age_;
};