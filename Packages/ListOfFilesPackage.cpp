//
// Created by michal on 20.12.18.
//

#include "ListOfFilesPackage.h"


ListOfFilesPackage::ListOfFilesPackage(int taskId, int numberOfFiles)
        : Package(taskId, 10), numberOfFiles(numberOfFiles){};

int ListOfFilesPackage::getNumberOfFiles() { return numberOfFiles; }