#pragma comment(linker, "/stack:200000000") //can slow down program
#pragma GCC optimize("Ofast") //only use when trying to brute force with a lot of simple 'for' loops
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") //can slow down program
#pragma GCC optimize ("O3") //used most often
#pragma GCC target ("sse4") //used most often
