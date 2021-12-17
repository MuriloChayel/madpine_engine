#include"GameLoop.h"

#include<iostream>

int a;

void Game::Start(){
    std::cout<<"Initialized"<<std::endl;
}
void Game::Update(){
    a++;
    //std::cout<<a<<std::endl;    
}