VIEW THIS RAW IF USING GITHUB ------------------------------------------------------------------^

The hanning window is a concept used in signal processing to smooth out data.

This is a simplified example but works just the same.  The way to think about the hanning window is a sliding pair of minimum and maximum
indeces in an array.  Between the minimum and maximum there are a set of data points (ints) that can be thought of as y values on a graph.
You take these values, and depending on the size of the window, they will be assigned weights.  The values at the edges will have a weight
of 1 and the weights will increase by one as the indeces increase toward the middle.

array:          1 16 18 13 1 14 16 7 5 13
filtered array: 0 0 12 11 10 10 10 10 0 0

window:   | | | | | |           | | | |
weights:  |1|2|3|2|1|           |1|2|1|

Example section:

Original Array: 
4 7 0 9 5 2 0 7 7 3 
Filtered Array: 
0 4 4 5 5 2 2 5 6 0 
    
    1. We multiply each spot in the index with the correct weight and we get  
    2. Then divide by all weights added together and that is the new value of the middle index in the window
    
    7(1) + 7(2) + 3(1) = 24
    24/(1 + 2 + 1) = 6
    
    The reason that the middle of the window has a higher weight is to give the values closest the most influence on what the final middle     value will be.
    
