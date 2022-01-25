# File-Parser
parses file contaning text using input redirection

After running makefile, run like this:
```
./parser.x < test
```
Replace "test" with any other regular text file.

Sample run results:
Top Ten Words
Index     Item    Number  Priority
[   0]the           5         1
[   1]transaction   3         2
[   2]to            3         5
[   3]is            2         3
[   4]expected      2         4
[   5]in            2         12
[   6]advised       2         27
[   7]qualify       1         6
[   8]as            1         7
[   9]a             1         8


	Top Ten Numbers
Index     Item    Number  Priority
[   0]2004          4         1


	Top Ten Characters
Index     Item    Number  Priority
[   0]space         48        2
[   1]\n            8         1
[   2].             5         4
[   3]&             1         6
[   4],             1         5
[   5]-             1         3
