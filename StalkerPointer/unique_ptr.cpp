/*
            STACK ( automatic storage )
                -


            HEAP
                -

*/

#include<iostream>
#include<memory>

struct Employee{
    int employeeId;
    std::string employeeName;

    Employee(int id, std::string name):employeeId(id),employeeName(name){}
};

int main(){
    Employee* e1 = new Employee(101, "Rutveej");
    std::unique_ptr<Employee> ptr(e1);
    //Employee* newPtr = ptr.release();      // release relases the mem and makes dangling

    

}


/*
        UNIQUE
            - any extra overhead
            - unique ownership of a resource! i.e only one owner
                    What is a Resource?
                        - posix file (normal file on the system)
                        - joinable threads!
                        - MUTEX locks!
                        - Database connectivity & session connection (network connectiom)
                        - 

*/