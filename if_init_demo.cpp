#include<iostream>
#include<map>       //dictonary in python




int main(){

    //key value
    std::map<int , std::string> data {
        {1, "Rutveej"},
        {2,"Jadhav"},
        {3,"xyz"}
    };

    //structured bindings : spreading a pair of tuple values into different individual values

    
    if(  auto [itr,flag] = data.insert({4,"Manoj"});     !flag  ){
        std::cout<<" Insert failed\n";

    }
    else{
        std::cout<<"Insert Done\n";
    }

    //Printing the entire map
    for(auto& [key,value]:data){
        std::cout<<"Label "<<key<<"\t Value :"<<value<<"\n";
    }
}



/*
        if initilizer - declare if statement inside the if statement only.
*/