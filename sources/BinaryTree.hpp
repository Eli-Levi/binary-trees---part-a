
namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        struct Node
        {
            T value;
            Node *right_child;
            Node *left_child;

            explicit Node(T val = 0, Node *r = nullptr, Node *l = nullptr) : value(val), right_child(r), left_child(l){};
        };

        Node *root;

    public:
        BinaryTree(){};

        BinaryTree(BinaryTree &other) //ctor constuctor
        {
            // create iterator and make new nodes for the new BT.
        }
        BinaryTree<T> &add_root(T make_root)
        {
            return *this;
        }

        BinaryTree<T> &add_left(T root, T left)
        {
            return *this;
        }

        BinaryTree<T> &add_right(T root, T right)
        {
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, BinaryTree<T> &print) { return os; }
        // continue iterator.
        /*class iterator
        {
        protected:
            Node *pointer_to_current_node;

        public:
            explicit iterator(Node *ptr) : pointer_to_current_node(ptr){};

            explicit iterator(const iterator& other): pointer_to_current_node(other.pointer_to_current_node){}; //ctor

            virtual iterator &operator++(int) { return *this; } //i++

            virtual iterator &operator++() // ++i
            {
                return *this;
            }

            //T &operator=(T &other){};

            bool operator==(const iterator &other) const { return pointer_to_current_node == other.pointer_to_current_node; }

            bool operator!=(const iterator &other) const { return pointer_to_current_node != other.pointer_to_current_node; }

            T &operator*() const
            {
                return pointer_to_current_node->value;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->value);
            }
        };*/

        class inorder //: public iterator
        {
            Node *curr;

        public:
            explicit inorder(Node *ptr = nullptr) : curr(ptr){};

            inorder &operator++(int) { return *this; } //i++

            inorder &operator++() // ++i
            {
                return *this;
            }

            bool operator==(const inorder &other) const { return false; }

            bool operator!=(const inorder &other) const { return false; }

            T &operator*() const
            {
                return curr->value;
            }

            T *operator->() const
            {
                return &(curr->value);
            }

            friend std::ostream &operator<<(std::ostream &os, inorder &print) { return os; }

            //iterator &begin_inorder() { return *this; };

            //iterator &end_inorder() { return *this; };
        };

        class preorder //: public iterator
        {
            Node *curr;

        public:
            explicit preorder(Node *ptr = nullptr) : curr(ptr){};

            preorder &operator++(int) { return *this; } //i++

            preorder &operator++() // ++i
            {
                return *this;
            }

            bool operator==(const preorder &other) const { return false; }

            bool operator!=(const preorder &other) const { return false; }

            T &operator*() const
            {
                return curr->value;
            }

            T *operator->() const
            {
                return &(curr->value);
            }

            friend std::ostream &operator<<(std::ostream &os, preorder &print) { return os; }
            //iterator &begin_preorder() { return *this; };

            //iterator &end_preorder() { return *this; };
        };

        class postorder //: public iterator
        {
            Node *curr;

        public:
            explicit postorder(Node *ptr = nullptr) : curr(ptr){};

            postorder &operator++(int) { return *this; } //i++

            postorder &operator++() // ++i
            {
                return *this;
            }

            bool operator==(const postorder &other) const { return false; }

            bool operator!=(const postorder &other) const { return false; }

            T &operator*() const
            {
                return curr->value;
            }

            T *operator->() const
            {
                return &(curr->value);
            }

            friend std::ostream &operator<<(std::ostream &os, postorder &print) { return os; }
            //iterator &begin_postorder() { return *this; };

            //iterator &end_postorder() { return *this; };
        };

        BinaryTree<T>::preorder begin_preorder()
        {
            return preorder(this->root);
        }
        BinaryTree<T>::preorder end_preorder()
        {
            return preorder();
        }

        BinaryTree<T>::inorder begin_inorder()
        {
            return inorder(this->root);
        }

        BinaryTree<T>::inorder end_inorder()
        {
            return inorder();
        }

        BinaryTree<T>::postorder begin_postorder()
        {
            return postorder(this->root);
        }

        BinaryTree<T>::postorder end_postorder()
        {
            return postorder();
        }

        BinaryTree<T>::inorder begin()
        {
            return inorder(this->root);
        }

        BinaryTree<T>::inorder end()
        {
            return inorder();
        }

        // getters and setters
        Node *get_root() { return root; }

        Node *get_right(Node *father) { return father->right_child; }
        Node *get_left(Node *father) { return father->left_child; }
    };
};
