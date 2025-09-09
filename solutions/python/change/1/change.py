def find_fewest_coins(coins, target):
    if target < 0:
        raise ValueError("target can't be negative")

    dp = [float("inf")] * (target + 1)
    dp[0] = 0

    for i in range(1, target + 1):
        for c in coins:
            if c <= i:
                dp[i] = min(dp[i], dp[i - c] + 1)

    if dp[target] == float("inf"):
        raise ValueError("can't make target with given coins")

    ans = []

    while target > 0:
        for c in coins:
            if c <= target and dp[target - c] == dp[target] - 1:
                ans.append(c)
                target -= c
                break

    return ans
