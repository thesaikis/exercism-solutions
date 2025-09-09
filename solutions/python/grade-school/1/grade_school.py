from bisect import insort


class School:
    def __init__(self):
        self.__roster = []
        self.__added = []

    def add_student(self, name, grade):
        if name not in self.roster():
            insort(self.__roster, (grade, name))
            self.__added.append(True)
        else:
            self.__added.append(False)

    def roster(self):
        return list(name for _, name in self.__roster)

    def grade(self, grade_number):
        return list(name for grade, name in self.__roster if grade == grade_number)

    def added(self):
        return self.__added
