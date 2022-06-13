# config.py

def can_build(env, platform):
    return True

def configure(env):
    if env["platform"] == "windows":
        # Mostly VisualStudio
        if env["CC"] == "cl":
            if env["bits"]=="32":
                env.Append(LINKFLAGS=["discord_game_sdk.dll.lib"])
                env.Append(LIBPATH=["#modules/game_sdk_gd4/lib/x86/"])
            else: # 64 bit
                env.Append(LINKFLAGS=["discord_game_sdk.dll.lib"])
                env.Append(LIBPATH=["#modules/game_sdk_gd4/lib/x86_64/"])
    else:
        env.Append(
            LIBPATH=["#modules/game_sdk_gd4/lib/x86_64"])
        env.Append(LIBPATH=["#modules/game_sdk_gd4/lib/x86_64/"])
        env.Append(RPATH=["\$\ORIGIN"])