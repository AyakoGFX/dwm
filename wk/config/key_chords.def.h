#ifndef WK_CONFIG_KEY_CHORDS_H_
#define WK_CONFIG_KEY_CHORDS_H_

#include <stddef.h>

#include "src/common/key_chord.h"

/* state,
 * KEY(
 *     mods,
 *     special,
 *     key, key_len
 * ),
 * description,
 * command
 * before
 * after
 * flags, chords
 */
KeyChord builtinKeyChords[] = {
    {
        .state = KEY_CHORD_STATE_NOT_NULL, 
        .key = {
            .mods = {
                .ctrl = false, .alt = false, .hyper = false, .shift = false
            },
            .special = SPECIAL_KEY_NONE,
            .repr = "x", .len = 1
        },
        .description = "Kill", 
        .command = "killall dwmblocks && killall volapplet && killall cbatticon", 
        .before = NULL, 
        .after = NULL, 
        .flags = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false
        }, .keyChords = NULL
    },
    {
        .state = KEY_CHORD_STATE_NOT_NULL, 
        .key = {
            .mods = {
                .ctrl = false, .alt = false, .hyper = false, .shift = false
            },
            .special = SPECIAL_KEY_NONE,
            .repr = "l", .len = 1
        },
        .description = "LockScrean", 
        .command = "slock", 
        .before = NULL, 
        .after = NULL, 
        .flags = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false
        }, .keyChords = NULL
    },
    {
        .state = KEY_CHORD_STATE_NOT_NULL, 
        .key = {
            .mods = {
                .ctrl = false, .alt = false, .hyper = false, .shift = false
            },
            .special = SPECIAL_KEY_NONE,
            .repr = "e", .len = 1
        },
        .description = "+Emacs", 
        .command = NULL, 
        .before = NULL, 
        .after = NULL, 
        .flags = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false
        }, 
        .keyChords = (KeyChord[]){
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "e", .len = 1
                },
                .description = "open Emacs-C", 
                .command = "emacsclient -c -a 'emacs'", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "E", .len = 1
                },
                .description = "open Emacs", 
                .command = "emacs", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "s", .len = 1
                },
                .description = "start server", 
                .command = "emacs --daemon", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "S", .len = 1
                },
                .description = "stop server", 
                .command = "emacsclient -e '(kill-emacs)'", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "k", .len = 1
                },
                .description = "Emacs Everyware", 
                .command = "emacsclient --eval \"(emacs-everywhere)\"", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            { .state = KEY_CHORD_STATE_IS_NULL }
        }
    },
    {
        .state = KEY_CHORD_STATE_NOT_NULL, 
        .key = {
            .mods = {
                .ctrl = false, .alt = false, .hyper = false, .shift = false
            },
            .special = SPECIAL_KEY_NONE,
            .repr = "t", .len = 1
        },
        .description = "+Term-app", 
        .command = NULL, 
        .before = NULL, 
        .after = NULL, 
        .flags = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false
        }, 
        .keyChords = (KeyChord[]){
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "n", .len = 1
                },
                .description = "nvim", 
                .command = "alacritty -e nvim", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "b", .len = 1
                },
                .description = "btop", 
                .command = "alacritty -e btop", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            { .state = KEY_CHORD_STATE_IS_NULL }
        }
    },
    {
        .state = KEY_CHORD_STATE_NOT_NULL, 
        .key = {
            .mods = {
                .ctrl = false, .alt = false, .hyper = false, .shift = false
            },
            .special = SPECIAL_KEY_NONE,
            .repr = "o", .len = 1
        },
        .description = "+Open", 
        .command = NULL, 
        .before = NULL, 
        .after = NULL, 
        .flags = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false
        }, 
        .keyChords = (KeyChord[]){
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "b", .len = 1
                },
                .description = "Browser", 
                .command = "google-chrome-stable", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "f", .len = 1
                },
                .description = "Filemanager", 
                .command = "thunar", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "g", .len = 1
                },
                .description = "Gimp", 
                .command = "gimp", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "o", .len = 1
                },
                .description = "OBS", 
                .command = "obs", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "c", .len = 1
                },
                .description = "Cursor", 
                .command = "cursor", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "d", .len = 1
                },
                .description = "Github-Desktop", 
                .command = "github-desktop", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "k", .len = 1
                },
                .description = "kdenlive", 
                .command = "org.kde.kdenlive", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "t", .len = 1
                },
                .description = "xfce-taskmanager", 
                .command = "xfce4-taskmanager", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "T", .len = 1
                },
                .description = "Timeshift", 
                .command = "timeshift-launcher", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            { .state = KEY_CHORD_STATE_IS_NULL }
        }
    },
    {
        .state = KEY_CHORD_STATE_NOT_NULL, 
        .key = {
            .mods = {
                .ctrl = false, .alt = false, .hyper = false, .shift = false
            },
            .special = SPECIAL_KEY_NONE,
            .repr = "S", .len = 1
        },
        .description = "+Services", 
        .command = NULL, 
        .before = NULL, 
        .after = NULL, 
        .flags = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false
        }, 
        .keyChords = (KeyChord[]){
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "o", .len = 1
                },
                .description = "+olamma", 
                .command = NULL, 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, 
                .keyChords = (KeyChord[]){
                    {
                        .state = KEY_CHORD_STATE_NOT_NULL, 
                        .key = {
                            .mods = {
                                .ctrl = false, .alt = false, .hyper = false, .shift = false
                            },
                            .special = SPECIAL_KEY_NONE,
                            .repr = "s", .len = 1
                        },
                        .description = "stop", 
                        .command = "systemctl stop ollama.service", 
                        .before = NULL, 
                        .after = NULL, 
                        .flags = {
                            false, false, false, false, false, false, false,
                            false, false, false, false, false, false, false
                        }, .keyChords = NULL
                    },
                    {
                        .state = KEY_CHORD_STATE_NOT_NULL, 
                        .key = {
                            .mods = {
                                .ctrl = false, .alt = false, .hyper = false, .shift = false
                            },
                            .special = SPECIAL_KEY_NONE,
                            .repr = "S", .len = 1
                        },
                        .description = "start", 
                        .command = "systemctl start ollama.service", 
                        .before = NULL, 
                        .after = NULL, 
                        .flags = {
                            false, false, false, false, false, false, false,
                            false, false, false, false, false, false, false
                        }, .keyChords = NULL
                    },
                    { .state = KEY_CHORD_STATE_IS_NULL }
                }
            },
            { .state = KEY_CHORD_STATE_IS_NULL }
        }
    },
    {
        .state = KEY_CHORD_STATE_NOT_NULL, 
        .key = {
            .mods = {
                .ctrl = false, .alt = false, .hyper = false, .shift = false
            },
            .special = SPECIAL_KEY_NONE,
            .repr = "r", .len = 1
        },
        .description = "+Rofi", 
        .command = NULL, 
        .before = NULL, 
        .after = NULL, 
        .flags = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false
        }, 
        .keyChords = (KeyChord[]){
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "e", .len = 1
                },
                .description = "Emoji", 
                .command = "rofi -modi emoji -show emoji", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "c", .len = 1
                },
                .description = "clipmenu", 
                .command = "clipmenu", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "w", .len = 1
                },
                .description = "rofi-wifi", 
                .command = "rofi-wifi", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "b", .len = 1
                },
                .description = "rofi-bluetooth", 
                .command = "rofi-bluetooth", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "p", .len = 1
                },
                .description = "rofi-passmenu", 
                .command = "rofi-passmenu", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "s", .len = 1
                },
                .description = "rofi-spellcheck", 
                .command = "rofi-spell-c", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "P", .len = 1
                },
                .description = "POWER-MENU", 
                .command = "rofi -show power-menu -modi power-menu:rofi-power-menu", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            { .state = KEY_CHORD_STATE_IS_NULL }
        }
    },
    {
        .state = KEY_CHORD_STATE_NOT_NULL, 
        .key = {
            .mods = {
                .ctrl = false, .alt = false, .hyper = false, .shift = false
            },
            .special = SPECIAL_KEY_NONE,
            .repr = "s", .len = 1
        },
        .description = "+Screenshot", 
        .command = NULL, 
        .before = NULL, 
        .after = NULL, 
        .flags = {
            false, false, false, false, false, false, false,
            false, false, false, false, false, false, false
        }, 
        .keyChords = (KeyChord[]){
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "s", .len = 1
                },
                .description = "flameshot gui", 
                .command = "flameshot gui", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "f", .len = 1
                },
                .description = "full-S", 
                .command = "flameshot full --path ~/Pictures/SS/", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "d", .len = 1
                },
                .description = "delay 5s", 
                .command = "flameshot full --delay 5000", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            {
                .state = KEY_CHORD_STATE_NOT_NULL, 
                .key = {
                    .mods = {
                        .ctrl = false, .alt = false, .hyper = false, .shift = false
                    },
                    .special = SPECIAL_KEY_NONE,
                    .repr = "c", .len = 1
                },
                .description = "full-S-clipboard", 
                .command = "flameshot full --clipboard", 
                .before = NULL, 
                .after = NULL, 
                .flags = {
                    false, false, false, false, false, false, false,
                    false, false, false, false, false, false, false
                }, .keyChords = NULL
            },
            { .state = KEY_CHORD_STATE_IS_NULL }
        }
    },
    { .state = KEY_CHORD_STATE_IS_NULL }
};

#endif /* WK_CONFIG_KEY_CHORDS_H_ */
