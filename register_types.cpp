//
// Created by jordi on 7/10/2021.
//

#include "register_types.h"

#include "core/object/class_db.h"
#include "discord_manager.h"

void register_game_sdk_gd4_types() {
    ClassDB::register_class<DiscordActivityState>();
    ClassDB::register_class<DiscordActivityManager>();
    ClassDB::register_class<DiscordManager>();
}

void unregister_game_sdk_gd4_types() {
}