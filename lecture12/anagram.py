n, m = map(int, input().split())

list_word = []
for i in range(n):
    list_word.append(input())

for i in range(m):
    word = input()
    word = sorted(word)
    
    for j in list_word:
        if word == sorted(j):
            print(j, end=' ')
    print()
