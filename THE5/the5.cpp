#include "the5.h"

bool isCyclicUtil(int file,int base, const std::vector<std::vector<int>>& dependencyMatrix, std::vector<int>& visited, std::vector<int>& recStack) {
    if (visited[file] == 0) {
        visited[file] = 1;
        recStack[file] = 1;

        for (int i = 0; i < dependencyMatrix.size(); ++i) {
            
            if (dependencyMatrix[file][i] == 1) {
                if (visited[i] == 0 && isCyclicUtil(i,base, dependencyMatrix, visited, recStack)) {
                    return true;
                } else if (recStack[i] == 1 && i == base){
                    return true;
                }
            }
        }
    }
   
    return false;
}
void isCyclic(const std::vector<std::vector<int>>& dependencyMatrix, std::vector<std::vector<int>>& cyclicDependencies,bool& isCompilable) {
    int n = dependencyMatrix.size();
    
    for (int i = 0; i < n; ++i){
        std::vector<int> visited(n, 0);
        std::vector<int> recStack(n, 0);
        std::vector<int> cycle;
        if (!visited[i] && isCyclicUtil(i, i,dependencyMatrix, visited, recStack)) {
            isCompilable = false;
            for (int j = 0; j < n; ++j) {
                if (recStack[j] == 1) {
                    cycle.push_back(j);
                }
            }
            cyclicDependencies.push_back(cycle);
            
            
        }
        
        
        
    }
    
}
bool findd(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    for (int num1: vec1){
        for (int num2 : vec2) {
            if (num1 == num2) {
                return true;
            }
        }
    }
    return false;
}

void mergeVectors(std::vector<std::vector<int>>& cyclicDependencies) {
    bool merged = true;
    while (merged) {
        merged = false;
        for (size_t i = 0; i < cyclicDependencies.size(); ++i) {
            for (size_t j = i + 1; j < cyclicDependencies.size(); ++j) {
                if (findd(cyclicDependencies[i], cyclicDependencies[j])) {
                    std::vector<int> mergedVec;
                    mergedVec.reserve(cyclicDependencies[i].size() + cyclicDependencies[j].size());
                    mergedVec.insert(mergedVec.end(), cyclicDependencies[i].begin(), cyclicDependencies[i].end());
                    mergedVec.insert(mergedVec.end(), cyclicDependencies[j].begin(), cyclicDependencies[j].end());
                    std::vector<int> uniquee;
                    for (int num : mergedVec) {
                        bool found = false;
                        for (int uniqueNum : uniquee) {
                            if (num == uniqueNum) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            uniquee.push_back(num);
                        }
                    }

                    cyclicDependencies[i] = uniquee;
                    cyclicDependencies.erase(cyclicDependencies.begin() + j);

                    merged = true;
                    break;
                }
            }
            if (merged) {
                break;
            }
        }
    }
}
void run(const std::vector<std::vector<int>>& dependencyMatrix, 
         bool& isCompilable,
         std::vector<int>& compileOrder, 
         std::vector<std::vector<int>>& cyclicDependencies){
            isCompilable = true;
            int n = dependencyMatrix.size();
            std::vector<int> remaining(n, 0);
            isCyclic(dependencyMatrix, cyclicDependencies,isCompilable);
            if(!isCompilable){
                mergeVectors(cyclicDependencies);
                return;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dependencyMatrix[i][j] == 1) {
                        remaining[j]++;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                int file = -1;
                for (int j = 0; j < n; ++j) {
                    if (remaining[j] == 0) {
                        file = j;
                        break;
                    }
                }
                compileOrder.push_back(file);
                for (int j = 0; j < n; ++j) {
                    if (dependencyMatrix[file][j] == 1) {
                        remaining[j]--;
                    }
                }
        
                remaining[file] = -1; 
            }
            isCompilable = true;
             
         }
        



        

