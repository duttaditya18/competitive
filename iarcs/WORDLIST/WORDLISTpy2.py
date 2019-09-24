f= open("guru99.txt","w+")

mymap = dict()

def createWordList(line):
    wordList1 = line.split()
    for word in wordList1:
        cleanWord = ""
        for char in word:
            if char in '\'.,;:':
                char = ""
            cleanWord += char
        cleanWord = cleanWord.lower()
        mymap[cleanWord] = mymap.get(cleanWord, 0) + 1

a = int(raw_input())
print(a)

for i in range(a):
    x = raw_input()
    createWordList(x)

print len(mymap)
for i in sorted (mymap.keys()):  
     print i
