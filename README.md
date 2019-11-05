![fillit](https://raw.githubusercontent.com/romaniyazov/fillit/master/readme_assets/readme_title.png)

![tetriminoes](https://raw.githubusercontent.com/romaniyazov/fillit/master/readme_assets/tetriminoes.png)

The goal of this project is to assemble the smallest possible square from tetriminos provided in the file given as argument. Figures inside the smallest square should be ordered left-to-right, top-to-bottom, according to their order in the file.

### Usage
```
./fillit tetriminos.txt
```

#### Input file example
```
....
####
....
....

....
.#..
.###
....

....
....
##..
.##.

```
Each tetrimino must bew followed by a newline.

### Output example
```
AAAA
CC..
BCC.
BBB.
```

### The algorithm
The size of the map is determined by `sqrt(NUM_OF_FIGURES * 4)`. If no solution on the map is possible, it is increased by 1.

The solution is being found using backtracking. After placing the figure to the top left possible position, the program tries to place the next one. If the next one fails, it goes back and moves the figure. All of this is being done recursively.

### Useful resources
https://en.wikipedia.org/wiki/Backtracking

https://medium.com/@phtruong42/42-project-fillit-ffd0ce54223e

https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909
