//
// Created by michal on 28.12.18.
//

#ifndef P2P_CONTROLLER_H
#define P2P_CONTROLLER_H


#include "OperationCode.h"
#include "Network/Listener.h"
#include "Network/NetworkManager.h"

using namespace std;

class ControllerException : public exception {
private:
    std::string message;
public:
    explicit ControllerException(const std::string& message): message(message){};
    virtual const char* what() const throw() {
        return message.c_str();
    }
};


class Controller {
public:
    Controller(NodeAddr me);
    virtual ~Controller();
    void startNewNetwork();
    void connectToNetwork(NodeAddr addr);
    vector<NodeAddr> getNodesAddresses();
    vector<File> getFiles();
    void downloadFile(File file);
private:
    NodeAddr me;
    NetworkManager* networkManager = nullptr;
    Listener* listener = nullptr;
    void startListener();
};


#endif //P2P_CONTROLLER_H
