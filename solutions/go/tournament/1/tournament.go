package tournament

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"sort"
	"strings"
)

type Team struct {
	name        string
	played      int
	won         int
	tied        int
	lost        int
	totalPoints int
}

type TeamList []Team

func (tl TeamList) Len() int {
	return len(tl)
}

func (tl TeamList) Less(a, b int) bool {
	if tl[a].totalPoints != tl[b].totalPoints {
		return tl[a].totalPoints > tl[b].totalPoints
	}
	return tl[a].name < tl[b].name
}

func (tl TeamList) Swap(i, j int) {
	tl[i], tl[j] = tl[j], tl[i]
}

// Tally reads from reader the match data and write the table to the writer.
func Tally(reader io.Reader, writer io.Writer) error {
	scanner := bufio.NewScanner(reader)
	teamMap := make(map[string]Team)

	for scanner.Scan() {
		line := scanner.Text()

		if len(line) == 0 {
			continue
		} else if line[0] == '#' {
			continue
		}

		data := strings.Split(line, ";")
		if len(data) != 3 {
			return errors.New("invalid data")
		}

		if !updateTeam(data[0], data[2], true, teamMap) || !updateTeam(data[1], data[2], false, teamMap) {
			return errors.New("invalid data")
		}

	}

	var teamList TeamList
	for _, teamData := range teamMap {
		teamList = append(teamList, teamData)
	}

	sort.Sort(teamList)

	writer.Write([]byte(fmt.Sprintf("%-31s| %2s | %2s | %2s | %2s | %2s\n", "Team", "MP", "W", "D", "L", "P")))
	for _, team := range teamList {
		writer.Write([]byte(fmt.Sprintf("%-31s| %2d | %2d | %2d | %2d | %2d\n", team.name, team.played, team.won, team.tied, team.lost, team.totalPoints)))
	}

	return nil
}

// updateTeam accesses the team map and updates the data accordingly.
func updateTeam(teamName string, result string, home bool, teamMap map[string]Team) bool {
	team, ok := teamMap[teamName]
	if !ok {
		team = Team{name: teamName}
	}

	team.played++

	if result == "draw" {
		team.tied++
		team.totalPoints += 1
	} else if result == "win" && home || result == "loss" && !home {
		team.won++
		team.totalPoints += 3
	} else if result == "win" && !home || result == "loss" && home {
		team.lost++
	} else {
		return false
	}

	teamMap[teamName] = team
	return true
}
