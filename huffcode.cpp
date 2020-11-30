// huffcode.cpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Source for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017
//
// Finished 11/29/2020
// Greg Talotta
// CS 411 Fall 2020

#include "huffcode.hpp" // for class HuffCode declaration
#include <string>
using std::string;
using std::unordered_map;
#include <set>
using std::multiset;
#include <utility>

void HuffCode::setWeights(const unordered_map<char, int> &theweights)
{
    if (theweights.size() > 0)
    {
        std::multiset<std::shared_ptr<node>, set_compare> trees;
        for (auto x : theweights)
        {
            trees.insert(std::make_shared<node>(true, x.second, x.first));
        }
        while (trees.size() > 1)
        {
            auto left = *trees.begin();
            trees.erase(trees.begin());
            auto right = *trees.begin();
            trees.erase(trees.begin());
            trees.insert(std::make_shared<node>(false, (left->weight + right->weight), left, right));
        }
        auto potential_root = *trees.begin();
        if (potential_root->isLeaf)
        {
            root = std::make_shared<node>(false, potential_root->weight, potential_root);
        }
        else
        {
            root = *trees.begin();
        }
        setCodewords(root, "");
    }
}

void HuffCode::setCodewords(std::shared_ptr<node> thetree, std::string code)
{
    if (thetree->isLeaf)
    {
        codewords.insert(std::make_pair(thetree->data, code));
        return;
    }
    if (thetree->left)
    {
        code.push_back('0');
        setCodewords(thetree->left, code);
    }
    if (thetree->right)
    {
        code.pop_back();
        code.push_back('1');
        setCodewords(thetree->right, code);
    }
    return;
}

string HuffCode::encode(const string &text) const
{
    string out = "";
    for (char const &c : text)
    {
        if (codewords.find(c) != codewords.end())
        {
            out += codewords.at(c);
        }
    }
    return out;
}

string HuffCode::decode(const string &codestr) const
{
    string out = "";
    auto currentNode = root;
    for (char const &c : codestr)
    {
        if (c == '0')
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
        if (currentNode->isLeaf)
        {
            out.push_back(currentNode->data);
            currentNode = root;
        }
    }
    return out;
}
