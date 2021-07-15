//
// Created by jordi on 7/12/2021.
//

#include "discord_activity_state.h"
#include "discord_activity_manager.h"

String DiscordActivityState::get_state() {
    return state;
}
void DiscordActivityState::set_state(String new_value) {
    state = new_value;
    emit_signal("property_changed");
}

String DiscordActivityState::get_details() {
    return details;
}
void DiscordActivityState::set_details(String new_value) {
    details = new_value;
    emit_signal("property_changed");
}

String DiscordActivityState::get_large_image() {
    return large_image;
}
void DiscordActivityState::set_large_image(String new_value) {
    large_image = new_value;
    emit_signal("property_changed");
}

String DiscordActivityState::get_large_text() {
    return large_text;
}
void DiscordActivityState::set_large_text(String new_value) {
    large_text = new_value;
    emit_signal("property_changed");
}

String DiscordActivityState::get_small_image() {
    return small_image;
}
void DiscordActivityState::set_small_image(String new_value) {
    small_image = new_value;
    emit_signal("property_changed");
}

String DiscordActivityState::get_small_text() {
    return small_text;
}
void DiscordActivityState::set_small_text(String new_value) {
    small_text = new_value;
    emit_signal("property_changed");
}

String DiscordActivityState::get_party_id() {
    return party_id;
}
void DiscordActivityState::set_party_id(String new_value) {
    party_id = new_value;
    emit_signal("property_changed");
}

String DiscordActivityState::get_match_secret() {
    return match_secret;
}
void DiscordActivityState::set_match_secret(String new_value) {
    match_secret = new_value;
    emit_signal("property_changed");
}

String DiscordActivityState::get_join_secret() {
    return join_secret;
}
void DiscordActivityState::set_join_secret(String new_value) {
    join_secret = new_value;
    emit_signal("property_changed");
}

String DiscordActivityState::get_spectate_secret() {
    return spectate_secret;
}
void DiscordActivityState::set_spectate_secret(String new_value) {
    spectate_secret = new_value;
    emit_signal("property_changed");
}

bool DiscordActivityState::get_instance() {
    return instance;
}
void DiscordActivityState::set_instance(bool new_value) {
    instance = new_value;
    emit_signal("property_changed");
}

int DiscordActivityState::get_start_timestamp() {
    return start_timestamp;
}

void DiscordActivityState::set_start_timestamp(int new_value) {
    start_timestamp = new_value;
    emit_signal("property_changed");
}

int DiscordActivityState::get_end_timestamp() {
    return end_timestamp;
}
void DiscordActivityState::set_end_timestamp(int new_value) {
    end_timestamp = new_value;
    emit_signal("property_changed");
}

int DiscordActivityState::get_party_current_size() {
    return party_current_size;
}
void DiscordActivityState::set_party_current_size(int new_value) {
    party_current_size = new_value;
    emit_signal("property_changed");
}

int DiscordActivityState::get_party_max_size() {
    return party_max_size;
}
void DiscordActivityState::set_party_max_size(int new_value) {
    party_max_size = new_value;
    emit_signal("property_changed");
}

void DiscordActivityState::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_state"), &DiscordActivityState::get_state);
    ClassDB::bind_method(D_METHOD("set_state", "new_value"), &DiscordActivityState::set_state);
    ClassDB::bind_method(D_METHOD("get_details"), &DiscordActivityState::get_details);
    ClassDB::bind_method(D_METHOD("set_details", "new_value"), &DiscordActivityState::set_details);
    ClassDB::bind_method(D_METHOD("get_large_image"), &DiscordActivityState::get_large_image);
    ClassDB::bind_method(D_METHOD("set_large_image", "new_value"), &DiscordActivityState::set_large_image);
    ClassDB::bind_method(D_METHOD("get_large_text"), &DiscordActivityState::get_large_text);
    ClassDB::bind_method(D_METHOD("set_large_text", "new_value"), &DiscordActivityState::set_large_text);
    ClassDB::bind_method(D_METHOD("get_small_image"), &DiscordActivityState::get_small_image);
    ClassDB::bind_method(D_METHOD("set_small_image", "new_value"), &DiscordActivityState::set_small_image);
    ClassDB::bind_method(D_METHOD("get_small_text"), &DiscordActivityState::get_small_text);
    ClassDB::bind_method(D_METHOD("set_small_text", "new_value"), &DiscordActivityState::set_small_text);
    ClassDB::bind_method(D_METHOD("get_party_id"), &DiscordActivityState::get_party_id);
    ClassDB::bind_method(D_METHOD("set_party_id", "new_value"), &DiscordActivityState::set_party_id);
    ClassDB::bind_method(D_METHOD("get_match_secret"), &DiscordActivityState::get_match_secret);
    ClassDB::bind_method(D_METHOD("set_match_secret", "new_value"), &DiscordActivityState::set_match_secret);
    ClassDB::bind_method(D_METHOD("get_join_secret"), &DiscordActivityState::get_join_secret);
    ClassDB::bind_method(D_METHOD("set_join_secret", "new_value"), &DiscordActivityState::set_join_secret);
    ClassDB::bind_method(D_METHOD("get_spectate_secret"), &DiscordActivityState::get_spectate_secret);
    ClassDB::bind_method(D_METHOD("set_spectate_secret", "new_value"), &DiscordActivityState::set_spectate_secret);
    ClassDB::bind_method(D_METHOD("get_instance"), &DiscordActivityState::get_instance);
    ClassDB::bind_method(D_METHOD("set_instance", "new_value"), &DiscordActivityState::set_instance);
    ClassDB::bind_method(D_METHOD("get_start_timestamp"), &DiscordActivityState::get_start_timestamp);
    ClassDB::bind_method(D_METHOD("set_start_timestamp", "new_value"), &DiscordActivityState::set_start_timestamp);
    ClassDB::bind_method(D_METHOD("get_end_timestamp"), &DiscordActivityState::get_end_timestamp);
    ClassDB::bind_method(D_METHOD("set_end_timestamp", "new_value"), &DiscordActivityState::set_end_timestamp);
    ClassDB::bind_method(D_METHOD("get_party_current_size"), &DiscordActivityState::get_party_current_size);
    ClassDB::bind_method(D_METHOD("set_party_current_size", "new_value"), &DiscordActivityState::set_party_current_size);
    ClassDB::bind_method(D_METHOD("get_party_max_size"), &DiscordActivityState::get_party_max_size);
    ClassDB::bind_method(D_METHOD("set_party_max_size", "new_value"), &DiscordActivityState::set_party_max_size);

    ADD_PROPERTY(PropertyInfo(Variant::STRING, "state"), "set_state", "get_state");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "details"), "set_details", "get_details");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "start_timestamp"), "set_start_timestamp", "get_start_timestamp");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "end_timestamp"), "set_end_timestamp", "get_end_timestamp");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "large_image"), "set_large_image", "get_large_image");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "large_text"), "set_large_text", "get_large_text");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "small_image"), "set_small_image", "get_small_image");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "small_text"), "set_small_text", "get_small_text");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "party_id"), "set_party_id", "get_party_id");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "party_current_size"), "set_party_current_size", "get_party_current_size");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "party_max_size"), "set_party_max_size", "get_party_max_size");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "match_secret"), "set_match_secret", "get_match_secret");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "join_secret"), "set_join_secret", "get_join_secret");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "spectate_secret"), "set_spectate_secret", "get_spectate_secret");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "instance"), "set_instance", "get_instance");

    ADD_SIGNAL(MethodInfo("property_changed"));
}

DiscordActivityState::DiscordActivityState() {}