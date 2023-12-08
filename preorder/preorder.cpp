struct BSTNode {
    string key;
    BSTNode *left, *right;
}

BSTNode *findNode(BSTNode *t, const string & key) {
    if (t == NULL) return NULL;
    if (key == t->key) return t;
    if (key < t->key) {
        return findNode(t->left, key);
    } else {
        return findNode(t->right, key);
    }
}

void preOrder(BSTNode *t) {
    if(t == NULL) return NULL;
    std::cout << t->key;
    preOrder(t->left);
    preOrder(t->right);
}

int main() {
    BSTNode root = {
        key = "1";
        left = BSTNode
    }
}