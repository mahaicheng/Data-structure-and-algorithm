/*************************************************************************
	> 文件名: BinarySearchTree.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年10月13日 星期二 18时35分58秒
 ************************************************************************/

#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_
namespace mhc
{
    template<typename T>
    class BinarySearchTree
    {
    public:
        BinarySearchTree()
        {
            root = nullptr;
        }
        BinarySearchTree(const BinarySearchTree& rhs)
        {
            root = clone(rhs);
        }
        const BinarySearchTree& operator=(const BinarySearchTree& rhs)
        {
            if(this != &rhs){
                makeEmpty();
                root = clone(rhs);
            }
            return *this;
        }
        ~BinarySearchTree()
        {
            makeEmpty();
        }
        const T& findMin() const
        {
            return findMin(root);
        }
        const T& findMax() const
        {
            return findMax(root);
        }
        bool contains(const T& item) const
        {
            return contains(item, root);
        }
        bool empty() const
        {
            return root == nullptr;
        }
        void printTree() const
        {
            printTree(root);
        }
        void makeEmpty()
        {
            makeEmpty(root);
        }
        void insert(const T& item)
        {
            insert(item, root);
        }
        void remove(const T& item)
        {
            remove(item, root);
        }
    private:
        struct BinaryNode
        {
            T element;
            BinaryNode* left;
            BinaryNode* right;
            BinaryNode(const T& item, BinaryNode* lt, BinaryNode* rt)
            {
                element = item;
                left = lt;
                right = rt;
            }
        };

        BinaryNode* root;

        void insert(const T& item, BinaryNode* & root) const
        {
            if(root == nullptr){
                root = new BinaryNode(item, nullptr, nullptr);
                return;
            }

            if(root->element == item)
                return;     //no duplicate
            if(item < root->element)
                insert(item, root->left);
            else{
                insert(item, root->right);
            }
        }
        void remove(const T& item, BinaryNode* & root) const
        {
            if(root == nullptr)
                return;
            
            if(root->element == item){
                if(root->right == nullptr && root->left == nullptr){
                    delete root;
                    root = nullptr;
                }
                else if(root->left != nullptr && root->right == nullptr){
                    BinaryNode* temp = root;
                    root = root->left;
                    delete temp;
                }
                else if(root->left == nullptr && root->right != nullptr){
                    BinaryNode* temp = root;
                    root = root->right;
                    delete temp;
                }
                else{
                    BinaryNode* ptr = findMin(root->right);
                    root->element = ptr->element;
                    remove(root->element, t->right);
                }
            }
            else if(item < root->element)
                remove(item, root->left);
            else
                remove(item, root->right);
        }
        BinaryNode* findMin(BinaryNode* root) const
        {
            if(root == nullptr)
                return nullptr;

            if(root->left != nullptr){
                return findMin(root->left);
            }
            else{
                return root;
            }
        }
        BinaryNode* findMax(BinaryNode* root) const
        {
            if(root == nullptr)
                return nullptr;

            if(root->right != nullptr){
                return findMax(root->right);
            }
            else{
                return root; 
            }
        }
        bool contains(const T& item, BinaryNode* & root) const
        {
            if(root == nullptr)
                return false;

            if(root->element == item)
                return true;
            else if(item < root->element){
                return contains(item, root->left);
            }
            else{
                return contains(item, root->right);
            }
        }
        void makeEmpty(BinaryNode* & root)
        {
            if(root == nullptr)
                return;
            //must use postOrder sequence
            makeEmpty(root->left);
            makeEmpty(root->right);
            delete root;
            root = nullptr;
        }
        void printTree(BinaryNode* & root) const
        {
            if(root == nullptr)
                return;
            printTree(root->left);
            cout<<root->element<<endl;
            printTree(root->right);
        }
        BinaryNode* clone(BinaryNode* root) const
        {
            if(root == nullptr)
                return nullptr;
            return new BinaryNode(root->element, clone(root->left), clone(root->right));
        }
    };
}
#endif
