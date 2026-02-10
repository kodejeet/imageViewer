
# PPM Image Viewer (SDL2)

A minimal image viewer that reads **PPM (P6)** images from `stdin` and displays them using **SDL2**.  
Built to stay close to the metal: raw file parsing, manual buffers, no image libraries.

---

## Supported Format
- PPM **P6** (binary)
- `maxval = 255` only

---

## Recommended Image Size / Ratio

PPM itself has **no fixed or recommended aspect ratio** — it’s just raw pixels.  
That said, for sanity and performance:

- **Recommended resolution**: `800×600` or `640×480`
- **Aspect ratio**: `4:3` or `16:9`
- Avoid extremely large images (PPM is uncompressed and memory-heavy)

Best rule:  
👉 *Use a resolution that comfortably fits on screen and matches your SDL window.*

---

## Setup & Build

Compile using SDL2:

```bash
gcc -o main main.c `sdl2-config --cflags --libs`
```


Then run :

```bash
cat image.ppm | ./main
```
