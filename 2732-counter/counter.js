/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let current=n;
    return function() {
        current++;
        return current-1;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */