//
// Created by jordi on 7/12/2021.
//

#ifndef GODOT_DISCORDACTIVITYSTATE_H
#define GODOT_DISCORDACTIVITYSTATE_H

#include "core/object/ref_counted.h"

class DiscordActivityState : public RefCounted {
    GDCLASS(DiscordActivityState, RefCounted);

    String state;
    String details;
    int start_timestamp=0;
    int end_timestamp=0;
    String large_image;
    String large_text;
    String small_image;
    String small_text;
    String party_id;
    int party_current_size=0;
    int party_max_size=0;
    String match_secret;
    String join_secret;
    String spectate_secret;
    bool instance;

protected:
    static void _bind_methods();

public:
    String get_state();
    void set_state(String new_value);

    String get_details();
    void set_details(String new_value);

    String get_large_image();
    void set_large_image(String new_value);

    String get_large_text();
    void set_large_text(String new_value);

    String get_small_image();
    void set_small_image(String new_value);

    String get_small_text();
    void set_small_text(String new_value);

    String get_party_id();
    void set_party_id(String new_value);

    String get_match_secret();
    void set_match_secret(String new_value);

    String get_join_secret();
    void set_join_secret(String new_value);

    String get_spectate_secret();
    void set_spectate_secret(String new_value);

    bool get_instance();
    void set_instance(bool new_value);

    int get_start_timestamp();
    void set_start_timestamp(int new_value);

    int get_end_timestamp();
    void set_end_timestamp(int new_value);

    int get_party_current_size();
    void set_party_current_size(int new_value);

    int get_party_max_size();
    void set_party_max_size(int new_value);
    DiscordActivityState();

};


#endif //GODOT_DISCORDACTIVITYSTATE_H
