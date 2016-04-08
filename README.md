# Draw-n-Guess

Neural network based digit recognition. Still in development.

08/04/16 : Added self made database in `data-set/new/`. I wrote 1019 digits by hand (yea, I was determined), the classification rate went up from 94% to 98%. Now it has become really good at guessing my digits, shouldn't be as good with yours (do your own database with learn-mode !).

```
Hold left-button to draw
Click right-button to clear
Hit space to submit to network

Build with SFML
```

### TODO :

- [X] Create a new digit base (currently comparing your mouse drawings with real handwritten digits..)
- [ ] Implement PCA et normalization coef computing
- [X] Learn mode (Adds each drawing to database)


![alt tag](https://zippy.gfycat.com/FairUncomfortableDesertpupfish.gif)

#### References
- http://www.cs.bham.ac.uk/~jxb/NN/l7.pdf
- http://www.di.unito.it/~cancelli/retineu06_07/FNN.pdf
- ESEO Data Mining Project - M. Feuilloy
