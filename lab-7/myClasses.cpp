#include <iostream>
#include <vector>
using namespace std;

class CPU {
    string cpu_name;
public:
    CPU() {}
    CPU(string cname) {
        cpu_name = cname;
    }
};

class Computer {
    CPU builtCpu;
    string status = "Good";
public:
    Computer(string cpu_name) {
        builtCpu = CPU(cpu_name);
    }
    void broken() {
        status = "N/A";
    }
};

class SchoolClass {
    string classname;
    vector<Computer *> computers;
public:
    SchoolClass(string cname) {
        classname = cname;
    }
    void addComputer(Computer *pc) {
        computers.push_back(pc);
    }
    void transfer(SchoolClass &destination, Computer *pc) {

    }
};