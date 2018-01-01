#include <SDL2/SDL.h>
#include <emscripten.h>
#include <cstdlib>

struct context
{
    SDL_Renderer *renderer;
    int iteration;

    context() : iteration(0) {}
};

void mainloop(void *arg)
{
    context *ctx = static_cast<context*>(arg);
    SDL_Renderer *renderer = ctx->renderer;
    
    // example: draw a moving rectangle
    
    // red background
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // moving blue rectangle
    SDL_Rect r;
    r.x = ctx->iteration % 255;
    r.y = 50;
    r.w = 50;
    r.h = 50;
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect( renderer, &r );

    SDL_RenderPresent(renderer);

    ctx->iteration++;
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(255, 255, 0, &window, &renderer);

    context ctx;
    ctx.renderer = renderer;

    const int simulate_infinite_loop = 1; // call the function repeatedly
    const int fps = -1; // call the function as fast as can render (typically 60fps)
    emscripten_set_main_loop_arg(mainloop, &ctx, fps, simulate_infinite_loop);

    return EXIT_SUCCESS;
}
