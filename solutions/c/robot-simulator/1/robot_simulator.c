#include "robot_simulator.h"

robot_position_t increments[] = {{0, 1}, {1,0}, {0,-1}, {-1,0}};

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    return (robot_status_t) {direction, (robot_position_t) {x, y}};
}

void robot_move(robot_status_t *robot, const char *commands) {
    while (*commands) {
        switch (*commands) {
            case 'R':
                robot->direction = (robot->direction + 1) % DIRECTION_MAX;
                break;
            case 'L':
                robot->direction = (robot->direction - 1) % DIRECTION_MAX;
                break;
            case 'A':
                robot->position.x += increments[robot->direction].x;
                robot->position.y += increments[robot->direction].y;
                break;
        }
        commands++;
    }
}