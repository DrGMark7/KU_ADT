# Time complexity: O(mv)

def min_snacks(m, prices, v):
    dp = [float('inf')] * (v + 1)
    dp[0] = 0
    
    for price in prices:
    #    print("price: ", price)
        for i in range(price, v + 1):     #. if price more than v, it will not be considered
            dp[i] = min(dp[i], dp[i - price] + 1)  #. Assign the minimum value between the current value and the value of the previous price + 1
    #        print(price,i)
    #   print("dp: ", dp)
    #print(dp, v)

    if dp[v] != float('inf'):
        return dp[v]
    else:
        return 0

 
def min_snackV2(m, prices, v):
    temp = []
    for i in range(m):         # number of snacks
        for j in range(v+1):   # price is j
            if j >= prices[i] and j-prices[i] == 0:
                temp.append(1)
            

    print(temp)
    return sum(temp)

# print (min_snackV2(4, [1,5,6,9], 8))
print (min_snackV2(3, [30,5,20], 25))
# print (min_snackV2(2, [5,10], 3))
print (min_snackV2(3, [30,5,25], 28))
print (min_snacks(3, [30,5,25], 28))
# m = int(input())
# prices = [int(input()) for _ in range(m)]
# v = int(input())

# print(prices)
# result = min_snacks(m, prices, v)
# print(result)