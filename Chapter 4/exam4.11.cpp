#include <iostream>
#include <algorithm>

using namespace std;

#include "../data_structure_and_algorithm_analysis/code/dsexceptions.h"

template <typename Comparable>
class BinarySearchTree
{
public:
    struct BinaryNode;
    BinarySearchTree( ) : root{ nullptr }
    {
    }

    /**
     * Copy constructor
     */
    BinarySearchTree( const BinarySearchTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    /**
     * Move constructor
     */
    BinarySearchTree( BinarySearchTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    /**
     * Copy assignment
     */
    BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move assignment
     */
    BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        std::swap( root, rhs.root );       
        return *this;
    }
    
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    BinaryNode* insert( const Comparable & x )
    {
        return insert( x, root, nullptr );
    }
     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    BinaryNode* insert( Comparable && x )
    {
        return insert( std::move( x ), root, nullptr );
    }
    
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }


public:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode *parent;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt, BinaryNode *pt)
          : element{ theElement }, left{ lt }, right{ rt }, parent{ pt} { }
        
        BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt, BinaryNode *pt)
          : element{ std::move( theElement ) }, left{ lt }, right{ rt }, parent{ pt} { }
    };

    BinaryNode *root;

private:
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    BinaryNode* insert( const Comparable & x, BinaryNode * & t, BinaryNode * p )
    {
        if( t == nullptr ){
            t = new BinaryNode{ x, nullptr, nullptr, p};
            return t;
        }
        else if( x < t->element )
        {
            return insert( x, t->left, t);
        }
        else if( t->element < x )
        {
            return insert( x, t->right, t);
        }
        else
            ;  // Duplicate; do nothing
        return nullptr;
    }
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    BinaryNode* insert( Comparable && x, BinaryNode * & t, BinaryNode * p)
    {
        if( t == nullptr ){
            t = new BinaryNode{ std::move( x ), nullptr, nullptr, p};
            return t;
        }
        else if( x < t->element ){
            return insert( std::move( x ), t->left, t );
        }
        else if( t->element < x ){
            return insert( std::move( x ), t->right, t );
        }
        else
            ;  // Duplicate; do nothing
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        while( t != nullptr )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
            printTree( t->left, out );
            out << t->element << endl;
            printTree( t->right, out );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
    }
};

template<class Object>
class Set
{
public:
    class const_iterator{
    public:
    using  BinaryNode = typename BinarySearchTree<Object>::BinaryNode;

    public:
        const_iterator& operator++()
        {
            if(m_current == nullptr) return *this;
            BinaryNode* t = nullptr;
            if(m_current->right != nullptr)
            {
                t = m_current->right;
                while(t->left != nullptr){t = t->left;}
                m_current = t;
            }
            else
            {
                t = m_current->parent;
                while(t != nullptr && t->element < m_current->element){ t = t->parent;}
                m_current = t;
            }
            return *this;//当m_current 为空时没有找到对应的元素
        }

        const_iterator operator++( int )
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        const_iterator& operator--()
        {
            if(m_current == nullptr) return *this;
             BinaryNode* t = nullptr;
            if(m_current->left != nullptr)
            {
                t = m_current->left;
                while(t->right != nullptr){t = t->right;}
                m_current = t;
            }
            else
            {
                t = m_current->parent;
                while(t != nullptr &&  m_current->element < t->element ){ t = t->parent;}
                m_current = t;
            }
            return m_current;//当m_current 为空时没有找到对应的元素
        }

        const_iterator operator--( int )
        {
            const_iterator old = *this;
            --(*this);
            return old;
        }

        bool operator == (const const_iterator& rhs)
        {
            return m_current == rhs.m_current;
        }

        bool operator != (const const_iterator& rhs)
        {
            return m_current != rhs.m_current;
        }

        Object& operator* ()
        { return retrieve(); }


    protected:
        const_iterator(BinaryNode* p): m_current(p)
        {}

        Object& retrieve()
        { return m_current->element; }

        BinaryNode* m_current;

        friend class Set;
    };

    class iterator : public const_iterator
    {
    public:
        using  BinaryNode = typename BinarySearchTree<Object>::BinaryNode;

    public:
        iterator()
        {}

        iterator& operator++()
        {
            if(m_current == nullptr) return *this;
            BinaryNode* t;
            if(m_current->right != nullptr)
            {
                t = m_current->right;
                while(t->left == nullptr){t = t->left;}
                m_current = t;
            }
            else
            {
                t = m_current->parent;
                while(t != nullptr && t->element < m_current->element){ t = t->parent;}
                m_current = t;
            }
            return m_current;//当m_current 为空时没有找到对应的元素
        }

        iterator operator++( int )
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

        iterator& operator--()
        {
            if(m_current == nullptr) return *this;
             BinaryNode* t;
            if(m_current->left != nullptr)
            {
                t = m_current->left;
                while(t->right == nullptr){t = t->right;}
                m_current = t;
            }
            else
            {
                t = m_current->parent;
                while(t != nullptr &&  m_current->element < t->element ){ t = t->parent;}
                m_current = t;
            }
            return m_current;//当m_current 为空时没有找到对应的元素
        }

        iterator operator--( int )
        {
            iterator old = *this;
            --(*this);
            return old;
        }

        bool operator == (const iterator& rhs)
        {
            return m_current == rhs->m_current;
        }

        bool operator != (const iterator& rhs)
        {
            return m_current != rhs->m_current;
        }

        Object& operator* ()
        { return const_iterator::retrieve(); }

        iterator(BinaryNode *p): const_iterator(p)
        {}
        
        friend class Set;
    private:
        BinaryNode* m_current;
    };
public:
    iterator insert(const Object& ele){
        return m_BinarySearchTree.insert(ele);
    }

    const_iterator begin() const
    {
        return m_BinarySearchTree.root;
    }

    iterator begin()
    {
        return m_BinarySearchTree.root;
    }

    const_iterator end() const
    {
        return const_iterator(nullptr);
    }

    iterator end()
    {
        return iterator(nullptr);
    }
    
private:
    BinarySearchTree<Object> m_BinarySearchTree;
};



int main(){
    Set<int> temp;
    temp.insert(10);
    temp.insert(11);

    Set<int>::const_iterator itr = temp.begin();
    Set<int>::const_iterator itr1 = temp.end();
    while(itr != itr1){
        cout << "ele:"<< *itr++ << endl;
    }
    // cout << "set print " << endl;
    // itr++;
    // cout << "set print23 " << endl;
    // cout << *itr << endl;
    // cout << "set print24 " << endl;
    // cout << "set print " << endl;
    // itr++;
    // cout << "set print23 " << endl;
    // cout << *itr << endl;
    // cout << "set print24 " << endl;
    // while(itr++ != temp.end()){
    //     cout << *itr << endl;
    // }
}