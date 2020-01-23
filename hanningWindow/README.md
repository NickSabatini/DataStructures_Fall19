The hanning window is a concept used in signal processing to smooth out data.

This is a simplified example but works just the same.  The way to think about the hanning window is a sliding pair of minimum and maximum
indeces in an array.  Between the minimum and maximum there are a set of data points (ints) that can be thought of as y values on a graph.
You take these values, and depending on the size of the window, they will be assigned weights.  The values at the edges will have a weight
of 1 and the weights will increase by one as the indeces increase toward the middle.

array:          1 16 18 13 1 14 16 7 5 13
filtered array: 0 0 12 11 10 10 10 10 0 0

window:   | | | | | |
weights:  |1|2|3|2|1|

Example section:
    
    |1|16|18|13|1|         1. We multiply each spot in the index with the correct weight and we get->     |1|32|36|26|1|
          ^               2. Then divide by all weights added together and that is the new value of              ^
    important idx            the important middle index.                                               (1+32+36+26+1)/9 = 
