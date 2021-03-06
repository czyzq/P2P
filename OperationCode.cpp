//
// Created by michal on 23.12.18.
//

#include "OperationCode.h"

bool NodeAddr::operator==(NodeAddr const &a) {
    return a.port == this->port && a.addr.s_addr==this->addr.s_addr;
}

bool NodeAddr::operator!=(NodeAddr const &a) {
    return !(a.port == this->port && a.addr.s_addr==this->addr.s_addr);
}

bool File::operator==(File const &a) {
    return a.hash==this->hash;
}

bool File::operator!=(File const &a) {
    return a.hash!=this->hash;
}

bool operator < (const File& l, const File& r) {
    return (l.hash<r.hash);
}

bool OperationCode::isRequest(int operationCode) {
    const list<int> requestOperationCodes = list<int>({
        FILES_LIST_REQUEST,
        NODES_LIST_REQUEST,
        FILE_FRAGMENT_REQUEST
    });
    return find(requestOperationCodes.begin(), requestOperationCodes.end(), operationCode) != requestOperationCodes.end();
}
