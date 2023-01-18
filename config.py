# config.py

def can_build(env, platform):
    return True

def configure(env):
    if env["platform"] == "windows":
        # Mostly VisualStudio
        if env["CC"] == "cl":
            env.Append(LINKFLAGS=["discord_game_sdk.dll.lib"])
            if env["arch"]=="x86":
                env.Append(LIBPATH=["#modules/game_sdk_gd4/lib/x86/"])
            else: # 64 bit
                env.Append(LIBPATH=["#modules/game_sdk_gd4/lib/x86_64/"])
    elif env["platform"] == "osx":
        env.Append(LIBPATH=["#modules/game_sdk_gd4/lib/x86_64/"])
        env.Append(RPATH=["\$\ORIGIN"])
    elif env["platform"] == "linuxbsd":
        env.Append(LIBPATH=["#modules/game_sdk_gd4/lib/x86_64/"])
        env.Append(LIBS=['discord_game_sdk'])
