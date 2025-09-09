ALLERGIES_LIST = ['eggs', 'peanuts', 'shellfish', 'strawberries', 'tomatoes', 'chocolate', 'pollen', 'cats']

class Allergies:
    def __init__(self, score):
        self.__allergies = [a for shift, a in enumerate(ALLERGIES_LIST) if score & (1 << shift)]

    def allergic_to(self, item):
        return item in self.__allergies

    @property
    def lst(self):
        return self.__allergies
