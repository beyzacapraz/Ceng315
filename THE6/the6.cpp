#include "the6.h"

// do not add extra libraries here

int find_structure(std::vector< std::vector<std::pair<int,int> > > &bond_energies, std::vector< std::vector<std::pair<int,int> > > &lowest_energy_structure) {
    std::vector<int> Q(bond_energies.size(), 0);
    std::vector<int> min_weight(bond_energies.size(), INT_MAX); // infinity yapma
    std::vector<int> parent(bond_energies.size(), -1); 
    int total_energy = 0;
    min_weight[0] = 0; // ilkinden başlıyoruz
    for(int i = 0; i < bond_energies.size(); i++){ //  vertex döngüsü
        int index = -1;
        int weight = INT_MAX;
        for(int v = 0; v < bond_energies.size(); v++){ // en küçük weighte sahip vertexi bulma
            if(!Q[v] && min_weight[v] < weight){
                index = v;
                weight = min_weight[v];
            }

        }
        if(index >= 0){
            Q[index] = 1;
            for(int j = 0; j < bond_energies[index].size(); j++){// o indexteki vertexin komuşlarının minini bulma
                int v = bond_energies[index][j].first; // komşu vertex
                int w = bond_energies[index][j].second;
                if(!Q[v] && w < min_weight[v]){
                    parent[v] = index;
                    min_weight[v] = w;
                }
            }
            if(parent[index] != -1){ // child -> parent a doğru edgelerin weighti
                total_energy += min_weight[index]; 
                lowest_energy_structure[index].emplace_back(parent[index], min_weight[index]); // bidirectional
                lowest_energy_structure[parent[index]].emplace_back(index, min_weight[index]);
            }


        }
        
    }
    return total_energy;
}
void DFS(int v, std::vector<std::vector<std::pair<int, int>>>& molecule_structure, std::vector<int>& current_chain, std::vector<int>& visited, std::vector<int>& max_chain) {
    visited[v] = 1;
    current_chain.push_back(v);
    for (int i = 0; i < molecule_structure[v].size(); i++) {
        std::pair<int, int> edge = molecule_structure[v][i];
        int neighbor = edge.first;
        if (!visited[neighbor]) {
            DFS(neighbor, molecule_structure, current_chain, visited, max_chain);
        }
    }

    if (current_chain.size() >= max_chain.size()) {
        max_chain = current_chain;
    }

    current_chain.pop_back();
}

int find_longest_chain(std::vector<std::vector<std::pair<int, int>>>& molecule_structure, std::vector<int>& chain) {
    std::vector<int> max_chain;
    for(int i = 0; i < molecule_structure.size(); i++){ //her vertex için path bulma
        std::vector<int> visited(molecule_structure.size(), 0);
        std::vector<int> current_chain;
        DFS(i,molecule_structure, current_chain,visited, max_chain);
    }
    chain = max_chain;
    return max_chain.size();
}