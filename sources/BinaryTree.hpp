
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

            Node()
            {
                Node add = new Node;
                add.left_child = nullptr;
                add.right_child = nullptr;
                return add;
            }

            ~Node()
            {
                delete this;
            }
        };

        Node *root;

    public:
        BinaryTree() : root(nullptr){};

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

        friend std::ostream &operator<<(std::ostream &os, BinaryTree &print) { return os; };

        // getters and setters
        Node *get_root() { return root; }

        Node *get_right(Node *father) { return father->right_child; }
        Node *get_left(Node *father) { return father->left_child; }

        // continue iterator.
        class iterator
        {
        protected:
            Node* pointer_to_current_node;

        public:
            iterator(Node *ptr = nullptr) : pointer_to_current_node(ptr){};

            // should i even have ++? because where does it go? left or right?
            iterator &operator++(int) { return this + 1; } //i++

            iterator &operator++() // ++i
            {
                return *this;
            }

            T &operator=(T &other){};

            bool operator==(const iterator &other) { return pointer_to_current_node == other.pointer_to_current_node; }

            bool operator!=(const iterator &other) { return pointer_to_current_node != other.pointer_to_current_node; } 

            bool operator<(const iterator &it){
                return true;
            }

            T &operator*()
            {
                return pointer_to_current_node->value;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->value);
            }
            
            
            iterator begin() { return iterator{pointer_to_current_node}; }
            iterator end() { return iterator{nullptr}; }
        };


        iterator begin_preorder()
        {
            return begin_it_setup();
        }
        iterator end_preorder()
        {
            return end_it_setup();
        }

        iterator begin_inorder()
        {
            return begin_it_setup();
        }

        iterator end_inorder()
        {
            return end_it_setup();
        }

        iterator begin_postorder()
        {
            return begin_it_setup();
        }

        iterator end_postorder()
        {
            return end_it_setup();
        }

        iterator begin()
        {
            return begin_it_setup();
        }

        iterator end()
        {
            return end_it_setup();
        }

        // SETUPS FOR ITERATORS
        iterator begin_it_setup()
        {
            return iterator{root};
        }
        
        iterator end_it_setup()
        {
            return iterator{nullptr};
        }


        class inorder : public iterator
        {
            iterator &begin_inorder() { return *this; };

            iterator &end_inorder() { return *this; };
        };

        class preorder : public iterator
        {
            iterator &begin_preorder() { return *this; };

            iterator &end_preorder() { return *this; };
        };

        class postorder : public iterator
        {

            iterator &begin_postorder() { return *this; };

            iterator &end_postorder() { return *this; };
        };
    };
};
