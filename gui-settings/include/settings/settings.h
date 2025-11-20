#ifndef SETTINGS_H
#define SETTINGS_H

#define FILENAME_SETTINGS "settings.json"
struct settings_t {
   float work_minutes;
   float rest_minutes;
};


void save_settings(const settings_t settings);
void read_settings(settings_t *settings);

#endif
