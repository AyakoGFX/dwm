// Configuration for dwmblocks
// Modify this file to change the commands that output to your statusbar
// Recompile using the make command after changes

static const Block blocks[] = {
    /*Icon*/  /*Command*/                                                                /*Update Interval*/  /*Update Signal*/
    {"",      "date '+%d/%m/%y'",                                                        5,                  0},  // Date
    {"",      "date '+%I:%M %p'",                                                        5,                  0},  // Time (12-hour format with AM/PM)
    {"Up:",   "uptime | grep -ohe 'up .*' | awk '{gsub(/[,;]/, \"\", $2); print $2}'",   60,                 0},  // Uptime
    {"R:",    "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",                 3,                  0},  // RAM usage
    {"B:",    "acpi | awk '{ print $5 }' | tr -d ','",                                   60,                 0},  // Battery level
    {"D:",    "df -h / | awk 'NR==2 {print $3, $4}'",                                    60,                 0},  // Disk usage (Used and Available space on /)
    {"V:",    "pactl list sinks | awk '/Volume:/ {print $5}' | head -n 1 | tr -d '%'",   1,                  0},  // Volume level
};

// Delimiter between status commands
static char delim[] = " | ";
static unsigned int delimLen = 5;
