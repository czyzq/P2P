//
// Created by michal on 18.12.18.
//

#include "RemoteNode.h"

#include <thread>
#include <future>
#include <unistd.h>
#include "Tasks/Task.h"


RemoteNode::RemoteNode(int sockfd): sockfd(sockfd){
    receiverTasks = new vector<Task>;
    senderTasks=new vector<Task>;
    receiver = new Receiver(receiverTasks);
    sender = new Sender(senderTasks);
    start();
}

RemoteNode::RemoteNode(RemoteNode && obj) : receiver(obj.receiver)
{
    std::cout << "Move RemoteNode Constructor is called" << std::endl;
}

RemoteNode& RemoteNode::operator=(RemoteNode && obj)
{
    std::cout << "Move RemoteNode Assignment is called" << std::endl;
    receiver = std::move(obj.receiver);
    return *this;
}

RemoteNode::~RemoteNode(){};


void RemoteNode::start(){
    std::thread th1([&](){receiver->run();});
    th1.detach();
    std::thread th2([&](){sender->run();});
    th2.detach();
}


void RemoteNode::addReceiverTask(Task& task){
    receiverTasks->emplace_back(task);
}

void RemoteNode::addSenderTask(Task& task){
    senderTasks->emplace_back(task);
}


bool RemoteNode::operator==(const RemoteNode &other){
    return this->getSockfd() == other.getSockfd();
}