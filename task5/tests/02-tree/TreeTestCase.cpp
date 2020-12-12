//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>

using namespace boost::filesystem;

TEST(GetTree, test1) {
    ASSERT_THROW(GetTree("/lol/kek", true), std::invalid_argument);
}

TEST(GetTree, test2) {
    ofstream file("filename");
    ASSERT_THROW(GetTree("filename", true), std::invalid_argument);
    boost::filesystem::remove_all("filename");
}

TEST(GetTree, test3) {
    FileNode node1;
    node1.name = "folderName";
    node1.is_dir = true;
    create_directory("folderName");

    FileNode node2;
    node2.name = "node2";
    node2.is_dir = true;
    node1.children.push_back(node2);
    create_directory("folderName/node2");


    ASSERT_EQ(GetTree("folderName", true), node1);
    boost::filesystem::remove_all("folderName");
    boost::filesystem::remove_all("folderName/node2");
}

TEST(GetTree, test4) {
    FileNode node1;
    node1.name = "folderName2";
    node1.is_dir = true;
    create_directory("folderName2");
    ofstream file("folderName2/filename");


    ASSERT_EQ(GetTree("folderName2", true), node1);
    boost::filesystem::remove_all("folderName2");
    boost::filesystem::remove_all("folderName2/filename");
}