

/*
Formal definition of Big O notation
Assuming f(n) and g(n) are non-negative functions.
f(n) = O(g(n)) if and only if f(n) <= c * g(n)
for all values of n where n >= n0 
and c and n0 are constants.

f(n) is the function that given the number of entries, return the total number of operations

The most common used g(n)'s are:
O(1)
O(lg n)
O(n)
O(n lg n)
O(n^2)
O(n^2)
O(n^3)
O(K^n) -> exponential, non polinomial

Problem 1:
Assume that f(n) = 5n + 50 and g(n)= n. Is f(n) = O(g(n))?

Solution :

f(n) = O(g(n)) if and only if f(n) <= c * g(n)

Assuming c = 6 : 
   5n + 50    | 6n
--------------
n = 10; = 100 | 60
n = 20; = 150 | 120
n = 50; = 300 | 300
n = 51; = 305 | 306

So that implies that:  5n + 50 = O(n) for c = 6 and n >= 50
*/



//Analizing the Big O notations of functions


// Exemple 1 
for (i=0; i< n; i = i * 2){
        /* code O(1)*/
}
/* i E { 1, 2, 4, 8, 16 , 32 ... 2^K}
when i >= n -> 2^K >= n -> lg2^K >= lgN -> k >= lgN 
*/

//Exemple 2

for ( i=0 ; i < n; i++){
    for(j= 0; j<n; j++){
        //code O(1)
    }
}
//nested loops

    i   |   #j
----------------
    0   |   n
    1   |   n
    2   |   n
    .........

// if you sum all #j = n
// So N * N = N^2 -> O(N^2)



    
