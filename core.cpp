#include <stdio.h>
#include <SDL/SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

struct context
{
    SDL_Surface *screen;
    int iteration;

    context() : iteration(0) {}
};

void mainloop(void *arg)
{
    context *ctx = static_cast<context*>(arg);
    SDL_Surface *screen = ctx->screen;

    if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
          #ifdef TEST_SDL_LOCK_OPTS
            // Alpha behaves like in the browser, so write proper opaque pixels.
            int alpha = 255;
          #else
            // To emulate native behavior with blitting to screen, alpha component is ignored. Test that it is so by outputting
            // data (and testing that it does get discarded)
            int alpha = (i+j) % 255;
          #endif
            int red = (j+ctx->iteration) % 255;
            int green = 0;
            int blue = 0;
            *((Uint32*)screen->pixels + i * 256 + j) = SDL_MapRGBA(screen->format, red, green, blue, alpha);
        }
    }
    if (SDL_MUSTLOCK(screen))
    {
        SDL_UnlockSurface(screen);
    }
    SDL_Flip(screen);
    ctx->iteration++;
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen = SDL_SetVideoMode(256, 256, 32, SDL_SWSURFACE);

    #ifdef TEST_SDL_LOCK_OPTS
    EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
    #endif

    context ctx;
    ctx.screen = screen;

    const int simulate_infinite_loop = 1; // call the function repeatedly
    const int fps = -1; // call the function as fast as can render (typically 60fps)
    emscripten_set_main_loop_arg(mainloop, &ctx, fps, simulate_infinite_loop);

    SDL_Quit();
    return 0;
}
