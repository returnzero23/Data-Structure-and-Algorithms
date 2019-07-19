/**
     * Merge rhs into the priority queue.
     * rhs becomes empty. rhs must be different from this.
     * Exercise 6.35 needed to make this operation more efficient.
     */
    void merge( BinomialQueue & rhs )
    {
        if( this == &rhs )    // Avoid aliasing problems
            return;

        currentSize += rhs.currentSize;

        if( currentSize > capacity( ) )
        {
            int oldNumTrees = theTrees.size( );
            int newNumTrees = max( theTrees.size( ), rhs.theTrees.size( ) ) + 1;
            theTrees.resize( newNumTrees );
            for( int i = oldNumTrees; i < newNumTrees; ++i )
                theTrees[ i ] = nullptr;
        }

        BinomialNode *carry = nullptr;
        for( int i = 0, j = 1; j <= currentSize; ++i, j *= 2 )
        {
            BinomialNode *t1 = theTrees[ i ];
            BinomialNode *t2 = i < rhs.theTrees.size( ) ? rhs.theTrees[ i ] : nullptr;

            int whichCase = t1 == nullptr ? 0 : 1;
            whichCase += t2 == nullptr ? 0 : 2;
            whichCase += carry == nullptr ? 0 : 4;

            bool OnlyThis = false;
            switch( whichCase )
            {
              case 0: /* No trees */
              case 1: /* Only this */
                OnlyThis = true;
                break;
              case 2: /* Only rhs */
                theTrees[ i ] = t2;
                rhs.theTrees[ i ] = nullptr;
                break;
              case 4: /* Only carry */
                theTrees[ i ] = carry;
                carry = nullptr;
                break;
              case 3: /* this and rhs */
                carry = combineTrees( t1, t2 );
                theTrees[ i ] = rhs.theTrees[ i ] = nullptr;
                break;
              case 5: /* this and carry */
                carry = combineTrees( t1, carry );
                theTrees[ i ] = nullptr;
                break;
              case 6: /* rhs and carry */
                carry = combineTrees( t2, carry );
                rhs.theTrees[ i ] = nullptr;
                break;
              case 7: /* All three */
                theTrees[ i ] = carry;
                carry = combineTrees( t1, t2 );
                rhs.theTrees[ i ] = nullptr;
                break;
            }
            if(OnlyThis) break;
        }

        for( auto & root : rhs.theTrees )
            root = nullptr;
        rhs.currentSize = 0;
    }    


    /**
     * Merge rhs into the priority queue.
     * rhs becomes empty. rhs must be different from this.
     * Exercise 6.35 needed to make this operation more efficient.
     */
    void merge1( BinomialQueue & rhs )
    {
        if(currentSize > rhs.currentSize){
        	merge(rhs);
        }else{
        	rhs.merge(this);
        }
    }    