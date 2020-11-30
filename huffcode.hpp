// huffcode.hpp
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Header for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017
//
// Finished 11/29/2020
// Greg Talotta
// CS 411 Fall 2020

#ifndef FILE_HUFFCODE_H_INCLUDED
#define FILE_HUFFCODE_H_INCLUDED

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

struct node
{
    node() {}
    node(bool l, int w, char d)
    {
        isLeaf = l;
        weight = w;
        data = d;
    }
    node(bool l, int w, std::shared_ptr<node> le)
    {
        isLeaf = l;
        weight = w;
        left = le;
    }
    node(bool l, int w, std::shared_ptr<node> le, std::shared_ptr<node> r)
    {
        isLeaf = l;
        weight = w;
        left = le;
        right = r;
    }
    bool isLeaf;
    int weight;
    char data;
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
    bool operator<(const node &other) const
    {
        return weight < other.weight;
    }
    bool operator>(const node &other) const
    {
        return weight > other.weight;
    }
};

struct set_compare
{
    bool operator()(const std::shared_ptr<node> &n1, const std::shared_ptr<node> &n2) const
    {
        return n1->weight < n2->weight;
    }
};
// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode
{

    // ***** HuffCode: ctors, dctor, op= *****
public:
    // Compiler-generated default ctor, copy ctor, copy =, dctor used

    // ***** HuffCode: general public functions *****
public:
    void setWeights(const std::unordered_map<char, int> &theweights);

    std::string encode(const std::string &text) const;

    std::string decode(const std::string &codestr) const;

    // ***** HuffCode: data members *****
private:
    std::shared_ptr<node> root;
    void setCodewords(std::shared_ptr<node> thetree, std::string code);
    std::unordered_map<char, std::string> codewords;
}; // End class HuffCode

#endif //#ifndef FILE_HUFFCODE_H_INCLUDED
