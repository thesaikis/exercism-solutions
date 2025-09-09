from collections import defaultdict


class Team:
    def __init__(self):
        self.wins = 0
        self.losses = 0
        self.draws = 0
        self.matches_played = 0

    def update(self, status):
        self.matches_played += 1

        if status == "draw":
            self.draws += 1
        elif status == "win":
            self.wins += 1
        else:
            self.losses += 1


def tally(rows):
    data = defaultdict(Team)

    for row in rows:
        left_team, right_team, result = row.split(";")
        data[left_team].update(result)
        data[right_team].update(
            "win" if result == "loss" else "loss" if result == "win" else result
        )

    table = ["Team                           | MP |  W |  D |  L |  P"]
    for name, team in sorted(data.items(), key=lambda x: (-(x[1].wins * 3 + x[1].draws), x[0])):
        table.append(
            f"{name:30} | {team.matches_played:>2} | {team.wins:>2} | {team.draws:>2} | {team.losses:>2} | {team.wins * 3 + team.draws:>2}"
        )

    return table
