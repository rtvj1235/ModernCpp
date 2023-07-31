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
  
    std::cout<<ptr->employeeId<<"\t"<<ptr->employeeName<<"\n";

    int num=0;
    std::cin>>num;
    ptr.reset();

}




int main(){

    //creating resources and getting its ownership
    std::shared_ptr<Employee> ptr1 = std::make_shared<Employee>(101,"Rutveej");


    //print the usage count
    std::cout<<"before thread:Main: usage count: "<<ptr1.use_count()<<"\n";


    //created thread(shared the ownership of the resource with the magic)
    std::thread t1(magic,std::ref(ptr1));

    //stalker pointer / weak ptr
    std::weak_ptr<Employee> wkptr(ptr1);


    std::this_thread::sleep_for(std::chrono::seconds(10));              //delay

    //if resourse that wkptr is monitoring(stalking) has not yet expired
    if(!wkptr.expired()){
        std::cout<<"Printing from main"<<ptr1->employeeName<<"\n";
    }
    else{
        std::cout<<"Resource is gone!\n";
    }
    
    t1.join();
}

//optional, variant, visit, std::any fold, thread->mutex, log_guard, unique_guard, conditional_ vars, 
//array of threads, join