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
#include <unordered_map>
using std::unordered_map;
#include <set>
using std::multiset;
#include <iostream>
void HuffCode::setWeights(const unordered_map<char, int> &theweights)
{
    multiset<std::shared_ptr<node>> trees;
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
        trees.insert(std::make_shared<node>(false, left->weight + right->weight, left, right));
    }
    if (trees.size() == 1)
    {
        root = *trees.begin();
    }
}

string HuffCode::encode(const string &text) const
{
    // WRITE THIS!!!
    return ""; // DUMMY RETURN
}

string HuffCode::decode(const string &codestr) const
{
    // WRITE THIS!!!
    return ""; // DUMMY RETURN
}
