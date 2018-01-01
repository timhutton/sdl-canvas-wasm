Build index.js and index.wasm with Emscripten:

emcc core.cpp -o index.js -s WASM=1
