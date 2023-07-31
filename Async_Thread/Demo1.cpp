#include<iostream>
#include<thread>
#include<future>
#include<memory>

/*
    print the square of all numbers in an array
    It will then print the square of number passed as a parameter 
    The parameter to be passed is taken from the user inside main

    Note: 
        SYNCHRONISED : Statement N+1 starts executing only after statement N has finished

        ASYNCHRONISED : Statement N+1 can be started even before statement N has finished. We can
                        get a notification when statement N is finally finished and go back to deal with
                        statement N at that point.


    Explaination for thread:
        3 things to make in kitchen
            - chicken
            - egg
            - rice

        ~ GAS has 3 burners
        [ (PARALLEL EXECUTION) -> (Multiple Core) ]

        ~ GAS has 2 burenrs
        [ (It seems that chicken will take time, so keep it to marinate and cook eggs meanwile) -> CONCURRENT EXECUTION]

        ~ GAS has 1 burner
        [
            - if user starts cooking egg and realises in between spices are not there.
            till spcies are comming user starts cooking chicken, meanwhile spices come and then after 
            chicken
        ]




*/

void CalculateSquare(std::array<int,5> arr, std::future<int>& ft){
    for(int val: arr){
        std::cout<<val*val<<"\n";
    }

    std::cout<<"Printing the number square: ";
    int number = ft.get();          //get value now if it is ready, else block this thread
    std::cout<<number*number<<"\n";


}




int main(){
    int number = 0;
    std::array<int,5> data {1,2,3,4,5};
    //a promise to provide int
    std::promise<int> pr;
    std::future<int> ft= pr.get_future();

    /*
        promise for input
        future for access
    */

   std::future<void> res = std::async(std::launch::async, CalculateSquare, data, std::ref(ft));

    
    //std::thread t1 (CalculateSquare, std::array<int,5>{1,2,3,4,5}, std::ref(ft));
    std::cin>>number;
    pr.set_value(number);
    //t1.join();
}