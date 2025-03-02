#pragma once 
namespace combi
{
    struct  xcombination
    {
        short   n,
            m,
            * sset;
        xcombination(
            short n = 1,
            short m = 1
        );
        void reset();
        short getfirst();
        short getnext();
        short ntx(short i);
        unsigned __int64 nc;
        unsigned __int64 count() const;
    };

    struct  permutation
    {
        const static bool L = true;
        const static bool R = false;

        short  n,
            * sset;
        bool* dart;
        permutation(short n = 1);
        void reset();

        __int64 getfirst();
        __int64 getnext();

        short ntx(short i);
        unsigned __int64 np;

        unsigned __int64 count() const;
    };

    struct  accomodation
    {
        short  n,
            m,
            * sset;
        xcombination* cgen;
        permutation* pgen;
        accomodation(short n = 1, short m = 1);
        void reset();
        short getfirst();
        short getnext();
        short ntx(short i);
        unsigned __int64 na;
        unsigned __int64 count() const;
    };
}