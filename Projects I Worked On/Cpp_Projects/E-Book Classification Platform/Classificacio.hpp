#ifndef CLASSIFICACIO_HPP
#define CLASSIFICACIO_HPP

#include "BinaryTree.hpp"
#include "LlibreE.hpp"
#include <string>
#include <vector>

class Classificacio {
public:
    Classificacio(const BinaryTree<std::string> &arbre);
    ~Classificacio();

    bool conteArea(const std::string &area) const;
    std::string classifica(const LlibreE &llibre) const;

private:
    BinaryTree<std::string> arbre;

    void findPath(const BinaryTree<std::string> &node, const std::string &target, std::vector<std::string> &path) const;
    std::string findCommonAncestor(const std::vector<std::vector<std::string>> &paths) const;
};

#endif

