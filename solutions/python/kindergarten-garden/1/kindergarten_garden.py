class Garden:
    students = [
        "Alice",
        "Bob",
        "Charlie",
        "David",
        "Eve",
        "Fred",
        "Ginny",
        "Harriet",
        "Ileana",
        "Joseph",
        "Kincaid",
        "Larry",
    ]

    _LET_TO_PLANT = {
        "V": "Violets",
        "R": "Radishes",
        "G": "Grass",
        "C": "Clover",
    }

    def __init__(self, diagram, students=None):
        self.students = sorted(students) if students is not None else Garden.students
        self.rows = diagram.split("\n")

    def plants(self, name):
        idx = self.students.index(name)
        return [
            Garden._LET_TO_PLANT.get(row[i])
            for row in self.rows
            for i in range(idx * 2, idx * 2 + 2)
        ]
