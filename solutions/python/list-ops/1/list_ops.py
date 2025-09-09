from functools import reduce


def append(list1, list2):
    return list1 + list2


def concat(lists):
    return [] if lists == [] else reduce(lambda acc, elem: acc + elem, lists)


def filter(function, list):
    return [elem for elem in list if function(elem)]


def length(list):
    return len(list)


def map(function, list):
    return [function(elem) for elem in list]


def foldl(function, list, initial):
    return reduce(function, [initial] + list)


def foldr(function, list, initial):
    return reduce(function, [initial] + list[::-1])


def reverse(list):
    return list[::-1]
