//
// Created by jordi on 7/12/2021.
//

#include "discord_activity_manager.h"
#include "discord-files/discord.h"

Ref<DiscordActivityState> DiscordActivityManager::get_current_activity() {
    return current_activity;
}

void DiscordActivityManager::set_activity(Ref<DiscordActivityState> activity) {
    current_activity = activity;
    current_activity->connect("property_changed", callable_mp(this, &DiscordActivityManager::update_activity));
    update_activity();
}

void DiscordActivityManager::update_activity() {
    if(initialized) {
        if (current_activity != NULL) {
            if (!current_activity->get_details().is_empty()) {
                _activity.SetDetails(current_activity->get_details().utf8().get_data());
            }
            if (!current_activity->get_state().is_empty()) {
                _activity.SetState(current_activity->get_state().utf8().get_data());
            }
            if (current_activity->get_start_timestamp() > 0) {
                _activity.GetTimestamps().SetStart(current_activity->get_start_timestamp());
            }
            if (current_activity->get_end_timestamp() > 0) {
                _activity.GetTimestamps().SetEnd(current_activity->get_end_timestamp());
            }
            if (!current_activity->get_large_image().is_empty()) {
                _activity.GetAssets().SetLargeImage(current_activity->get_large_image().utf8().get_data());
            }
            _activity.GetAssets().SetLargeText(current_activity->get_large_text().utf8().get_data());
            if (!current_activity->get_small_image().is_empty()) {
                _activity.GetAssets().SetSmallImage(current_activity->get_small_image().utf8().get_data());
                _activity.GetAssets().SetSmallText(current_activity->get_small_text().utf8().get_data());
            }
            if (!current_activity->get_party_id().is_empty()) {
                _activity.GetParty().SetId(current_activity->get_party_id().utf8().get_data());
                _activity.GetParty().GetSize().SetCurrentSize(current_activity->get_party_current_size());
                _activity.GetParty().GetSize().SetMaxSize(current_activity->get_party_max_size());
            }
            _activity.SetInstance(current_activity->get_instance());
            if (!current_activity->get_join_secret().is_empty()) {
                _activity.GetSecrets().SetJoin(current_activity->get_join_secret().utf8().get_data());
            }
            if (!current_activity->get_spectate_secret().is_empty()) {
                _activity.GetSecrets().SetSpectate(current_activity->get_spectate_secret().utf8().get_data());
            }
            if (!current_activity->get_match_secret().is_empty()) {
                _activity.GetSecrets().SetMatch(current_activity->get_match_secret().utf8().get_data());
            }
        }
        core->ActivityManager().UpdateActivity(_activity, [](discord::Result result) {
            ERR_FAIL_COND_MSG(result != discord::Result::Ok, vformat("Could not update activity. An error occurred. Error code: %s", itos(static_cast<int>(result))));
        });
    }
    else {
        print_line("Could not update activity. Discord is not initialized.");
    }
}

void DiscordActivityManager::_bind_methods() {
    ClassDB::bind_method(D_METHOD("update_activity"), &DiscordActivityManager::update_activity);
    ClassDB::bind_method(D_METHOD("set_activity", "activity"), &DiscordActivityManager::set_activity);
    ClassDB::bind_method(D_METHOD("get_current_activity"), &DiscordActivityManager::get_current_activity);

//    ADD_PROPERTY(PropertyInfo(Variant::))
}

DiscordActivityManager::DiscordActivityManager() {}