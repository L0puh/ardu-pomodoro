#include "core/core.h"
#include "settings/settings.h"

#include <fstream>

int read_statistics(std::vector<float>& days, std::vector<float>& hours) {
   days.clear();
   hours.clear();

   std::ifstream file(FILENAME_STATISTIC);
   if (!file) {
      //TODO: logging error 
      return 0;
   }

   json j;
   file >> j;

   if (!j.contains("data") || !j["data"].is_array()) {
      return 0;
   }

   for (const auto& item : j["data"]) {
      if (item.contains("day") && item.contains("hours")) {
         days.push_back(item["day"].get<float>());
         hours.push_back(item["hours"].get<float>());
      }
   }

   return days.size();
}
