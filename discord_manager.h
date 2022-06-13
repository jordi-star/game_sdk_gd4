//
// Created by jordi on 7/10/2021.
//

#ifndef GODOT_DISCORDMANAGER_H
#define GODOT_DISCORDMANAGER_H

#include "scene/main/node.h"
#include "discord-files/discord.h"
#include "discord_activity_manager.h"


class DiscordManager : public Node {
    GDCLASS(DiscordManager, Node);
    String client_id = "0";
    bool require_discord = false;
    bool init_on_ready = false;

protected:
    static void _bind_methods();
    void _notification(int p_what);
    DiscordActivityManager *activity_manager;

public:
    bool initialized = false;
    discord::Core *core{};
    enum DiscordLogLevel {
        ERROR,
        WARNING,
        INFO,
        DEBUG
    };
    String get_client_id();
    void set_client_id(String id);

    int get_log_level();
    void set_log_level(DiscordLogLevel level);

    bool get_require_discord();
    void set_require_discord(bool new_value);

    DiscordActivityManager* get_activity_manager();

    bool get_init_on_ready();
    void set_init_on_ready(bool new_value);

    bool get_initialized();
    void set_initialized(bool new_value);
    void run_callbacks();
    Error initialize(int64_t client_id, bool require_discord, DiscordLogLevel log_level = DiscordLogLevel::INFO);

    DiscordManager();

private:
    DiscordLogLevel log_level = DiscordLogLevel::INFO;
};

VARIANT_ENUM_CAST(DiscordManager::DiscordLogLevel);

#endif //GODOT_DISCORDMANAGER_H
