//
// Created by jordi on 7/10/2021.
//

#include "discord_manager.h"

String DiscordManager::get_client_id() {
    return client_id;
}

DiscordActivityManager* DiscordManager::get_activity_manager() {
    return activity_manager;
}

void DiscordManager::set_client_id(String id) {
    client_id = id;
}

int DiscordManager::get_log_level() {
    return log_level;
}

void DiscordManager::set_log_level(DiscordLogLevel level) {
    log_level = level;
}

bool DiscordManager::get_require_discord() {
    return require_discord;
}

void DiscordManager::set_require_discord(bool new_value) {
    require_discord = new_value;
}

bool DiscordManager::get_initialized() {
    return initialized;
}

void DiscordManager::set_initialized(bool new_value) {
}

bool DiscordManager::get_init_on_ready() {
    return init_on_ready;
}

void DiscordManager::set_init_on_ready(bool new_value) {
    init_on_ready = new_value;
}

void DiscordManager::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_init_on_ready", "new_value"), &DiscordManager::set_init_on_ready);
    ClassDB::bind_method(D_METHOD("get_init_on_ready"), &DiscordManager::get_init_on_ready);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "init_on_ready"), "set_init_on_ready", "get_init_on_ready");

    ClassDB::bind_method(D_METHOD("set_initialized", "new_value"), &DiscordManager::set_initialized);
    ClassDB::bind_method(D_METHOD("get_initialized"), &DiscordManager::get_initialized);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "initialized"), "set_initialized", "get_initialized");

    ClassDB::bind_method(D_METHOD("set_client_id", "id"), &DiscordManager::set_client_id);
    ClassDB::bind_method(D_METHOD("get_client_id"), &DiscordManager::get_client_id);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "client_id"), "set_client_id", "get_client_id");

    ClassDB::bind_method(D_METHOD("set_require_discord", "new_value"), &DiscordManager::set_require_discord);
    ClassDB::bind_method(D_METHOD("get_require_discord"), &DiscordManager::get_require_discord);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "require_discord"), "set_require_discord", "get_require_discord");

    ClassDB::bind_method(D_METHOD("get_activity_manager"), &DiscordManager::get_activity_manager);

    ClassDB::bind_method(D_METHOD("set_log_level", "level"), &DiscordManager::set_log_level);
    ClassDB::bind_method(D_METHOD("get_log_level"), &DiscordManager::get_log_level);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "log_level", PROPERTY_HINT_ENUM, "Error,Warning,Info,Debug"), "set_log_level", "get_log_level");
    ClassDB::bind_method(D_METHOD("initialize", "client_id", "require_discord"), &DiscordManager::initialize);
    ClassDB::bind_method(D_METHOD("run_callbacks"), &DiscordManager::run_callbacks);

    BIND_ENUM_CONSTANT(ERROR);
    BIND_ENUM_CONSTANT(WARNING);
    BIND_ENUM_CONSTANT(INFO);
    BIND_ENUM_CONSTANT(DEBUG);
    ADD_SIGNAL(MethodInfo("game_sdk_initialized"));
}

Error DiscordManager::initialize(int64_t client_id, bool require_discord, DiscordLogLevel log_level) {
    if(!initialized) {
        EDiscordCreateFlags create_flag;

        if (require_discord) {
            create_flag = DiscordCreateFlags_Default;
        } else {
            create_flag = DiscordCreateFlags_NoRequireDiscord;
        }

        Error status = Error::OK;
        discord::Result result = discord::Core::Create(client_id, create_flag, &core);
        if (result != discord::Result::Ok) {
            status = Error::ERR_CANT_CREATE;
            print_error(vformat("An error occurred while attempting to initialize the Discord Game SDK. Error code: %s",
                                static_cast<int>(result)));
        } else {
            initialized = true;
            set_process_internal(true);
            emit_signal("game_sdk_initialized");

            activity_manager = memnew(DiscordActivityManager);
            activity_manager->core = core;
            activity_manager->initialized = true;

//            discord::LogLevel d_log_level = discord::LogLevel::Debug;
//            switch (log_level) {
//                case DiscordManager::INFO: {
//                    d_log_level = discord::LogLevel::Info;
//                }
//                case DiscordManager::WARNING: {
//                    d_log_level = discord::LogLevel::Warn;
//                }
//                case DiscordManager::ERROR: {
//                    d_log_level = discord::LogLevel::Error;
//                }
//                case DiscordManager::DEBUG: {
//                    d_log_level = discord::LogLevel::Debug;
//                }
//            }
//
//            core->SetLogHook(
//                    d_log_level, [](discord::LogLevel level, const char *message) {
//                        print_line("LOG");
//                        print_line(vformat("%s", message));
//                    });

        }
        return status;
    }
    else {
        return Error::ERR_ALREADY_EXISTS;
    }
}

void DiscordManager::run_callbacks() {
    if(initialized) {
        core->RunCallbacks();
    }
}

void DiscordManager::_notification(int p_what) {
    switch (p_what) {
        case NOTIFICATION_READY: {
            if(init_on_ready) {
                #ifdef TOOLS_ENABLED
                if (Engine::get_singleton()->is_editor_hint()) {
                    return;
                }
                #endif
                if(initialize(client_id.to_int(), require_discord, log_level) == Error::OK) {
                    if(OS::get_singleton()->has_feature("debug")) {
                        print_line("Discord Game SDK initialized successfully!");
                    }
                }
            }
        } break;
        case NOTIFICATION_INTERNAL_PROCESS: {
            #ifdef TOOLS_ENABLED
                        if (Engine::get_singleton()->is_editor_hint()) {
                                return;
                            }
            #endif
            run_callbacks();
        } break;
        case NOTIFICATION_PREDELETE: {
            #ifdef TOOLS_ENABLED
                        if (Engine::get_singleton()->is_editor_hint()) {
                                return;
                            }
            #endif
            print_line(vformat("%s", initialized));
            if(initialized) {
                memdelete(&activity_manager);
                memdelete(&core);
            }
        } break;
    }
}

DiscordManager::DiscordManager() {}