#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>

#include "chip8.h"
#include "config.h"
#include "widget/widget.h"

class app
{
public:
    static constexpr uint32_t init_flags = SDL_INIT_AUDIO | SDL_INIT_EVENTS| SDL_INIT_TIMER | SDL_INIT_VIDEO;

    app(config& conf, std::string const& rom_path, const uint8_t* program, size_t program_size);
    ~app();
    int exec();

    static std::vector<uint8_t> load_rom(std::filesystem::path rom_path);

private:
    void handle_event();
    void render();
    void play_sound();

    chip8 m_emulator;
    std::string const& m_rom_path;
    config m_conf;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Event m_event;
    bool m_quit;
    bool m_audio_enabled;
    uint32_t m_wavfile_length;
    uint8_t* m_wav_buffer;
    SDL_AudioSpec m_wav_spec;
    SDL_AudioDeviceID m_audio_device;
    TTF_Font* m_font;

    std::vector<widget*> m_widgets;
};
