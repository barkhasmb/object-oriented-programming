#include <iostream>
#include <vector>
using namespace std;

class CPU {};
class Computer {};
class SchoolClass {};

class CPU {
    string cpu_name;
public:
    CPU(string cpu_name = "") {
        this -> cpu_name = cpu_name;
    }
    string getCpuName() {
        return cpu_name;
    }
};

class Computer {
    CPU builtCpu;
    string status;
public:
    Computer(string cpu_name, string status = "Good") {
        builtCpu = CPU(cpu_name);
        this -> status = status;
    }
    string getCpuName() {
        return builtCpu.getCpuName();
    }
    string getStatus() {
        return status;
    }
    void broken(string status = "N/A") {
        this -> status = status;
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
        int size = computers.size();

        for(int i = 0; i < size; i++) {
            if(computers.at(i) == pc) {
                size = i;
                break;
            }
        }

        computers.erase(computers.begin() + size);

        destination.addComputer(pc);
    }
    void printComputers() {
        int size = computers.size();

        for(int i = 0; i < size; i++) {
            cout << classname << endl;
            cout << "CPU: " << computers[i] -> getCpuName() << endl;
            cout << "Status: " << computers[i] -> getStatus() << endl;
        }
    }
};