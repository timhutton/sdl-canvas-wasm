Live demo: https://timhutton.github.io/sdl-canvas-wasm/

See the compiled code on the gh-pages branch: https://github.com/timhutton/sdl-canvas-wasm/tree/gh-pages

Build index.js and index.wasm with Emscripten:

```emcc core.cpp -s WASM=1 -s USE_SDL=2 -O3 -o index.js```

Then open index.html in a web browser.
