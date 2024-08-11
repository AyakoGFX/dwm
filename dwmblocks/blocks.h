//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
// sudo pacman -S acpi

  {"", "date '+%d/%m/%y'", 5, 0},
  {"", "date '+%I:%M %p'", 5, 0}, // 12-hour format with AM/PM
  {"Up:", "uptime | grep -ohe 'up .*' | awk '{gsub(/[,;]/, \"\", $2); print $2}'", 60, 0}, // Uptime block
  {"R:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	3,		0},
  {"B:", "acpi | awk '{ print $5 }' | tr -d ','", 60, 0},
  {"D:", "df -h / | awk 'NR==2 {print $3, $4}'", 60, 0}, // Used space on /
  {"V:", "pactl list sinks | awk '/Volume:/ {print $5}' | head -n 1 | tr -d '%'", 1, 0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;


// df -h / | awk 'NR==2 {print "Used:", $3, "Avail:", $4}'
//Used: 36G Avail: 424G
//df -h / | awk 'NR==2 {print $3, $4}'
