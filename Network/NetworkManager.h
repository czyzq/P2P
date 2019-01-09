//
// Created by michal on 18.12.18.
//

#ifndef P2P_NETWORKMANAGER_H
#define P2P_NETWORKMANAGER_H


#include <list>
#include <set>
#include "RemoteNode.h"

using  namespace std;

class NetworkManager {
private:
    vector<RemoteNode*> remoteNodes;
    NodeAddr me;
    int initConnect(NodeAddr addr, NodeAddr me);
    int connect(NodeAddr addr, NodeAddr me);
public:
    NetworkManager(NodeAddr me);
    virtual ~NetworkManager();
    vector<NodeAddr> getNodeAddress();

public:
    void registerRemoteNode(RemoteNode* remoteNode);
    void unregisterRemoteNode(RemoteNode* remoteNode);
    int connectToNetwork(NodeAddr addr, NodeAddr me);
    vector<File> getFiles();
    void fileDownloadManage(File file);
};


#endif //P2P_NETWORKMANAGER_H
