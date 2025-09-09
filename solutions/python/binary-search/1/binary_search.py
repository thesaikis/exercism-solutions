def find(search_list, value):
    left, right = 0, len(search_list) - 1

    while left <= right:
        mid = (left + right) // 2

        if search_list[mid] == value:
            return mid
        
        if search_list[mid] > value:
            right = mid - 1
        else:
            left = mid + 1

    raise ValueError("value not in array")
