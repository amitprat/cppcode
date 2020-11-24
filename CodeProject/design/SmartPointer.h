#pragma once
#include "../header.h"

template <class T>
class SmartPointer {
    T* obj = nullptr;
    int* refcount = nullptr;

public:
    SmartPointer() {
        refcount = new int();
        *refcount = 0;
    }
    SmartPointer(T* obj) {
        cout << "Creating smart pointer" << obj->to_string() << endl;
        this->obj = obj;
        this->refcount = new int();
        *refcount = 1;
    }
    SmartPointer(const SmartPointer& that) {
        cout << "Copy construct that" << that.obj->to_string() << " to this" << (obj ? obj->to_string() : "null") << endl;
        this->obj = that.obj;
        this->refcount = that.refcount;
        (*refcount)++;
    }
    void operator =(const SmartPointer& that) {
        cout << "Assigning that" << that.obj->to_string() << " to this" << (obj ? obj->to_string() : "null") << endl;
        if (*this == that) return;
        if (refcount > 0) {
            cout << "Deleting object" << obj->to_string() << endl;
            delete obj;
        }
        refcount = that.refcount;
        (*refcount)++;
        obj = that.obj;
    }
    bool operator ==(const SmartPointer& that) {
        return this->obj == that.obj;
    }
    ~SmartPointer() {
        cout << "Try deleting " << obj->to_string() << endl;
        (*refcount)--;
        if (*refcount == 0) {
            cout << "Deleting object" << obj->to_string() << endl;
            delete obj;
        }
    }
    T* getValue() {
        return obj;
    }
};

class Student {
public:
    string name;
    int age = 20;
    Student(string name) :name(name) {}

    string to_string() {
        return "{" + name + ", " + std::to_string(age) + "}";
    }
};
class SmartPointerTest {
public:
    static void test() {
        SmartPointer<Student> other(new Student("Student1"));
        SmartPointer<Student> unassigned;
        {
            SmartPointer<Student> obj(new Student("Student2"));
            other = obj;
            unassigned = other;
        }
        SmartPointer<Student> obj1(new Student("Student3"));
        SmartPointer<Student>* obj2 = new SmartPointer<Student>(new Student("Student4"));
        delete obj2;
    }
};