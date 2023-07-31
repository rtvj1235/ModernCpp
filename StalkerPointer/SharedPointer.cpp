/*

    Shared pointer- 
        2 or More threads both are reading from the same file!
        File was originally opened in a 3rd thread(say main.cpp)
        we need to allow both threads access to this file(resource).


    One problem with shared_ptr is
        - usage counter :- When t1,t2,t3 are working on file1.txt after the t1's work done it
                            cannot close the file without the permission of t2 and t3.
                            So compiler takes counter=0 so a mem is needed to handle this mem, hence drawback.

*/

#include<iostream>
#include<memory>
#include<thread>


struct Employee{
    int employeeId;
    std::string employeeName;

    Employee(int id, std::string name):employeeId(id),employeeName(name){}

};

void magic(std::shared_ptr<Employee>& ptr){
    std::cout<<ptr->employeeId<<"\t"<<ptr->employeeName<<"\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));              //delay
    std::cout<<ptr->employeeId<<"\t"<<ptr->employeeName<<"\n";

}




int main(){

    std::shared_ptr<Employee> ptr1 = std::make_shared<Employee>(101,"Rutveej");
    std::cout<<"before thread:Main: usage count: "<<ptr1.use_count()<<"\n";

    std::thread t1(magic,std::ref(ptr1));

    t1.join();
}