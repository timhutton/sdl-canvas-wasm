Live demo: https://timhutton.github.io/sdl-canvas-wasm/

This is the branch with the compiled code. See the source code on the master branch: https://github.com/timhutton/sdl-canvas-wasm/tree/master

Build index.js and index.wasm with Emscripten:

```emcc core.cpp -o index.js -s WASM=1```
