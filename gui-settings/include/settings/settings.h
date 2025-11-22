#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>
#define FILENAME_SETTINGS "settings.json"
#define FILENAME_STATISTIC "statistic.json"

struct settings_t {
   float work_minutes;
   float rest_minutes;
};


void save_settings(const settings_t settings);
void read_settings(settings_t *settings);

int read_statistics(std::vector<float>& days, std::vector<float>& hours);

#endif
