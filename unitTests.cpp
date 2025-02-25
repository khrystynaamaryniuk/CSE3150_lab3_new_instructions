#include "include/doctest.h"
#include "LinkedList.h"
#include <sstream>

TEST_CASE("LinkedList initialization and insertion") {
    LinkedList list;
    
    SUBCASE("Initial list is empty") {
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "-> NULL");  
    }

    SUBCASE("Insert at the beginning") {
        list.insertAtBeginning(-1);
        list.insertAtBeginning(1);
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "1 -> -1 -> NULL");
    }

    SUBCASE("Insert at the end") {
        list.insertAtEnd(-1);
        list.insertAtEnd(1);
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "-1 -> 1 -> NULL");
    }
}

TEST_CASE("LinkedList deletion") {
    LinkedList list;
    list.insertAtBeginning(-1);
    list.insertAtBeginning(1);
    list.insertAtEnd(0);
    
    SUBCASE("Delete second element") {
        list.deleteNode(1);  // Delete second element (value = 1)
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "-1 -> 0 -> NULL");
    }

    SUBCASE("Delete at index") {
        list.deleteAtIndex(2);  // Delete the third element (value = 0)
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "-1 -> NULL");
    }
}

TEST_CASE("Copying a LinkedList") {
    LinkedList list;
    list.insertAtBeginning(-1);
    list.insertAtBeginning(1);
    
    LinkedList copiedList = list;
    
    std::ostringstream ossOriginal, ossCopy;
    ossOriginal << list;
    ossCopy << copiedList;
    
    CHECK(ossOriginal.str() == ossCopy.str());
}

TEST_CASE("Prefix sum checks") {
    LinkedList list;
    list.insertAtBeginning(-1);
    list.insertAtBeginning(1);
    list.insertAtEnd(-1);

    SUBCASE("Non-negative prefix sum check") {
        CHECK(list.non_negative_prefix() == false);
    }

    SUBCASE("Non-positive prefix sum check") {
        CHECK(list.non_positive_prefix() == true);
    }
}

TEST_CASE("Pointer Jumping") {
    LinkedList list;
    list.insertAtBeginning(-1);
    list.insertAtBeginning(1);
    list.insertAtEnd(0);
    
    SUBCASE("Before pointer jumping") {
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "1 -> -1 -> 0 -> NULL");
    }
    
    list.pointerJumping();
    
    SUBCASE("After pointer jumping") {
        std::ostringstream oss;
        oss << list;
        CHECK(oss.str() == "1 -> (cycle detected)");
    }
}
