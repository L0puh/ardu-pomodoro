#include "core/core.h"
#include "settings//settings.h"

#include <fstream>
#include <iomanip>
#include <iostream>


void save_settings(const settings_t settings){
   std::ofstream file(FILENAME_SETTINGS);
   json data = {{"work_minutes", settings.work_minutes}, 
                {"rest_minutes", settings.rest_minutes}};
   file << std::setw(4) << data << std::endl;
   file.close();


}
void read_settings(settings_t *settings){
   std::ifstream file(FILENAME_SETTINGS);
   json data = json::parse(file);
   std::cout << data.dump(0) << std::endl;
   file.close();
}
