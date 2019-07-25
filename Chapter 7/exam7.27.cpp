#include <vector>

using namespace std;

template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;
    
    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );

        // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}

inline int leftChild( int i )
{
    return 2 * i + 1;
}

template <typename Comparable>
void percDown( vector<Comparable> & a, int i, int n ,int left)
{
    int child;
    Comparable tmp;

    for( tmp = std::move( a[ i + left ] ); leftChild( i ) < n; i = child )
    {
        child = leftChild( i );
        if( child != n - 1 && a[ child + left ] < a[ child + 1 + left ] )
            ++child;
        if( tmp < a[ child + left ] )
            a[ i + left] = std::move( a[ child + left ] );
        else
            break;
    }
    a[ i + left] = std::move( tmp );
}


template <typename Comparable>
void heapsort( vector<Comparable> & a , int left, int right)
{
    const size = right - left + 1;
    for( int i = size / 2 - 1; i >= 0; --i )  /* buildHeap */
        percDown( a, i, size, left );
    for( int j = size - 1; j > 0; --j )
    {
        std::swap( a[ left ], a[ right ] );               /* deleteMax */
        percDown( a, 0, j ,left);
    }
}

template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right , int depth)
{
    if(depth > 0)
    {
        const Comparable & pivot = median3( a, left, right );

            // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot

        quicksort( a, left, i - 1, depth - 1);     // Sort small elements
        quicksort( a, i + 1, right, depth - 1);    // Sort large elements
    }
    else  // Do an insertion sort on the subarray
        heapsort( a, left, right );
}