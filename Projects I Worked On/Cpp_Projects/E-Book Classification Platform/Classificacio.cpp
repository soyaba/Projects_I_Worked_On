#include "Classificacio.hpp"
#include "LlibreE.hpp"
#include <algorithm>

Classificacio::Classificacio(const BinaryTree<string> &arbre) : arbre(arbre) {}

Classificacio::~Classificacio() {}

bool Classificacio::conteArea(const string &area) const {
    return arbre.search(area);
}

void Classificacio::findPath(const BinaryTree<std::string> &node, const std::string &target, std::vector<std::string> &path) const {
    if (node.isEmpty()) {
        return;
    }
    
    path.push_back(node.getRoot());
    
    if (node.getRoot() == target) {
        return;
    }
    
    if (!node.getLeft().isEmpty()) {
        findPath(node.getLeft(), target, path);
        if (path.back() == target) {
            return;
        }
        path.pop_back();
    }
    
    if (!node.getRight().isEmpty()) {
        findPath(node.getRight(), target, path);
        if (path.back() == target) {
            return;
        }
        path.pop_back();
    }
}

std::string Classificacio::findCommonAncestor(const std::vector<std::vector<std::string>> &paths) const {
    if (paths.empty()) {
        return "";
    }
    
    std::vector<std::string> commonPath = paths[0];
    
    for (const auto &path : paths) {
        auto it = std::mismatch(commonPath.begin(), commonPath.end(), path.begin(), path.end());
        commonPath.erase(it.first, commonPath.end());
    }
    
    return commonPath.empty() ? "" : commonPath.back();
}

std::string Classificacio::classifica(const LlibreE &llibre) const {
    std::vector<std::vector<std::string>> paths;
    
    for (const auto &keyword : llibre.getParaulesClau()) {
        std::vector<std::string> path;
        findPath(arbre, keyword, path);
        if (!path.empty() && path.back() == keyword) {
            paths.push_back(path);
        }
    }
    
    return findCommonAncestor(paths);
}

