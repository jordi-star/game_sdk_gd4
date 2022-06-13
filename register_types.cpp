//
// Created by jordi on 7/10/2021.
//

#include "register_types.h"

#include "core/object/class_db.h"
#include "discord_manager.h"

void initialize_game_sdk_gd4_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		GDREGISTER_CLASS(DiscordManager);
		GDREGISTER_CLASS(DiscordActivityState);
		GDREGISTER_CLASS(DiscordActivityManager);
	}
}

void uninitialize_game_sdk_gd4_module(ModuleInitializationLevel p_level) {
}