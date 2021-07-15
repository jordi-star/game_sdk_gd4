//
// Created by jordi on 7/12/2021.
//

#ifndef GODOT_DISCORD_ACTIVITY_MANAGER_H
#define GODOT_DISCORD_ACTIVITY_MANAGER_H

#include "core/object/object.h"
#include "discord_activity_state.h"
#include "discord-files/discord.h"

class DiscordActivityManager : public Object {
    GDCLASS(DiscordActivityManager, Object);
    discord::Activity _activity{};
    Ref<DiscordActivityState> current_activity;

protected:
    static void _bind_methods();

public:
    bool initialized = false;
    discord::Core *core;
    Ref<DiscordActivityState> get_current_activity();
    void set_activity(Ref<DiscordActivityState> activity);

    void update_activity();

    void clear_activity();

    void register_command(String command);

    void register_steam(int steamId);

    DiscordActivityManager();
};

#endif //GODOT_DISCORD_ACTIVITY_MANAGER_H
