// Configuration for dwmblocks
// Modify this file to change the commands that output to your statusbar
// Recompile using the make command after changes

static const Block blocks[] = {
    /*Icon*/  /*Command*/                                                                /*Update Interval*/  /*Update Signal*/
    {"",      "date '+%d/%m/%y'",                                                     3600,                  0},  // Date
    {"",      "date '+%I:%M %p'",                                                        5,                  0},  // Time (12-hour format with AM/PM)
    {"Up:",   "uptime | grep -ohe 'up .*' | awk '{gsub(/[,;]/, \"\", $2); print $2}'",   60,                 0},  // Uptime
    {"  ",    "free -h | awk '/^Mem/ { print $3 \"/\" $4 }' | sed 's/i//g'",                 3,                  0},  // RAM usage
    {" ",    "top -bn1 | awk '/^%Cpu/ { print int($2) \" \" int($3) \" \" int($4) \" \" int($5) }' | awk '{sum=0; for(i=1; i<=NF; i++) sum+=$i; print sum\"%\"}'",                 3,                  0},  // CPU 
    {" ",    "df -h / | awk 'NR==2 {print $3}'",                                    60,                 0},  // Disk usage (Used and Available space on /)
    {"󱊣 ",      "cat /sys/class/power_supply/BAT1/capacity",                               60,                  0},  //batery

{"󰕾 ",    "pactl list sinks | awk '/Volume:/ {print $5}' | head -n 1 | tr -d '%'",   1,                  0},  // Volume level

};

// {"󰕾 ",    "pactl list sinks | awk '/Volume:/ {print $5}' | head -n 1 | tr -d '%'",   1,                  0},  // Volume level
// free -h | awk '/^Mem/ { print $3 " / " $4 }' | sed 's/i//g'
// {"󰁹 ",    "acpi | awk '{ print $5 }' | tr -d ','",                                   60,                 0},  // Battery level
// {" ",    "df -h / | awk 'NR==2 {print $3, $4}'",                                    60,                 0},  // Disk usage (Used and Available space on /)
// {"  ",    "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",                 1,                  0},  // RAM usage
//   
// Delimiter between status commands
static char delim[] = " | ";
static unsigned int delimLen = 5;
// top -bn1 | awk '/^%Cpu/ { print $2 " " $3 " " $4 " " $5 }' | awk '{sum=0; for(i=1; i<=NF; i++) sum+=$i; print sum"%"}'
//
//cat /sys/class/power_supply/BAT1/capacity
//https://github.com/alexb7711/dwmblocks/tree/master/scripts
