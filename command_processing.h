/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * By contributing to this project, you agree to license your contributions
 * under the GPLv3 (or any later version) or any future licenses chosen by
 * the project author(s). Contributions include any modifications,
 * enhancements, or additions to the project. These contributions become
 * part of the project and are adopted by the project author(s).
 */

#ifndef COMMAND_PROCESSING_H
#define COMMAND_PROCESSING_H

#include "defines.h"

char (*get_raw_log(void))[LOG_LINE_LENGTH];
int get_next_log_row(void);
unsigned int get_log_generation(void);
int parse_json_command(char *command_string, char *topic);
void *serial_command_processing_thread(void *arg);
void *socket_command_processing_thread(void *arg);

// Serial state management
int serial_is_enabled(void);
int serial_get_fd(void);
void serial_set_state(int enabled, const char *port, int fd);
void serial_get_port(char *buffer, size_t size);

// Serial command operations
int serial_port_send(const char *command);
int forward_helmet_command_to_serial(char *command_string);

#endif // COMMAND_PROCESSING_H
