"""Functions used in preparing Guido's gorgeous lasagna.

Learn about Guido, the creator of the Python language:
https://en.wikipedia.org/wiki/Guido_van_Rossum

This is a module docstring, used to describe the functionality
of a module and its functions and/or classes.
"""


EXPECTED_BAKE_TIME = 40
PREPARATION_TIME = 2


def bake_time_remaining(time_in_oven):
    """Calculate the bake time remaining.

    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """

    return EXPECTED_BAKE_TIME - time_in_oven


def preparation_time_in_minutes(layers):
    """Calculate the preparation time needed.

    :param layers: int - number of layers in the lasagna
    :return: int - number of preparation time (in minutes)

    Function that takes the number of layers of the lasagna as and argument and
    returns the amount of time needed to prepare all the layers.
    """

    return layers * PREPARATION_TIME


def elapsed_time_in_minutes(layers, elapsed_bake_time):
    """Calculate the total minutes spent cooking.

    :param layers: int - number of layers in the lasagna
    :param elapsed_bake_time: int - time in minutes spent in the oven
    :return: int - the total time (in minutes) spent cooking and preparing the lasagna

    Function that takes the number of layers and the current elapsed baking time as arguments
    and returns the total time spent cooking and preparing.
    """

    return preparation_time_in_minutes(layers) + elapsed_bake_time
