struct Node
{
    Node* left;
    Node* right;
};

int CountNode(Node* node){

    if(node == nullptr) return 0;

    return 1 + CountNode(node->left) + CountNode(node->right);
}

int CountLeaves(Node* node){
    if(node == nullptr) return 0;

    if(node->left == nullptr && node->right == nullptr) return 1;

    return CountLeaves(node->left) + CountLeaves(node->right);
}

int CountFull(Node* node){
    if(node == nullptr) return 0;

    bool ifFull = node->left != nullptr && node->right != nullptr;

    return CountFull(node->left) + CountFull(node->right) + (ifFull ? 1 : 0);
}


int main()
{
    return 0;
}