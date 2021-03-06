//
// Created by pczyz on 20.12.18.
//

#ifndef P2P_SENDER_H
#define P2P_SENDER_H


#include "Stoppable.h"
#include "../Tasks/SenderTasks/SenderTask.h"
#include "../Serializers/Deserializers/Input.h"
#include <vector>

using namespace std;

class RemoteNode;

class Sender: public Stoppable {
public:
    Sender(RemoteNode* remoteNode, Output* output);
    virtual ~Sender();
    void run();

private:
    RemoteNode* remoteNode;
    Output* output;
};


#endif //P2P_SENDER_H
