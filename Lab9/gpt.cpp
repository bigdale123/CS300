#include <iostream>
#include <vector>

template <typename T>
class DynamicArrayBST {
public:
    DynamicArrayBST() : rootIndex(-1) {}

    void insert(const T& value) {
        if (rootIndex == -1) {
            rootIndex = 0;
            data.push_back(value);
        } else {
            insertRecursive(rootIndex, value);
        }
    }

    bool search(const T& value) const {
        return searchRecursive(rootIndex, value);
    }

    void inOrderTraversal() const {
        inOrderTraversalRecursive(rootIndex);
        std::cout << std::endl;
    }

private:
    std::vector<T> data;
    int rootIndex;

    void insertRecursive(int currentIndex, const T& value) {
        if (value < data[currentIndex]) {
            if (2 * currentIndex + 1 >= data.size()) {
                data.resize(2 * currentIndex + 2); // Ensure enough space
            }
            if (data[2 * currentIndex + 1] == T()) {
                data[2 * currentIndex + 1] = value;
            } else {
                insertRecursive(2 * currentIndex + 1, value);
            }
        } else {
            if (2 * currentIndex + 2 >= data.size()) {
                data.resize(2 * currentIndex + 3); // Ensure enough space
            }
            if (data[2 * currentIndex + 2] == T()) {
                data[2 * currentIndex + 2] = value;
            } else {
                insertRecursive(2 * currentIndex + 2, value);
            }
        }
    }

    bool searchRecursive(int currentIndex, const T& value) const {
        if (currentIndex >= data.size() || data[currentIndex] == T()) {
            return false;
        }
        if (data[currentIndex] == value) {
            return true;
        }
        if (value < data[currentIndex]) {
            return searchRecursive(2 * currentIndex + 1, value);
        } else {
            return searchRecursive(2 * currentIndex + 2, value);
        }
    }

    void inOrderTraversalRecursive(int currentIndex) const {
        if (currentIndex < data.size() && data[currentIndex] != T()) {
            inOrderTraversalRecursive(2 * currentIndex + 1);
            std::cout << data[currentIndex] << " ";
            inOrderTraversalRecursive(2 * currentIndex + 2);
        }
    }
};

int main() {
    DynamicArrayBST<int> bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    bst.insert(10);

    std::cout << "In-order traversal: ";
    bst.inOrderTraversal();

    int searchValue = 4;
    std::cout << "Search for " << searchValue << ": ";
    if (bst.search(searchValue)) {
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    searchValue = 9;
    std::cout << "Search for " << searchValue << ": ";
    if (bst.search(searchValue)) {
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}