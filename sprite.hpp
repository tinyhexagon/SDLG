#pragma once

class sprite
{
protected:
    SDL_FRect sprite_hitbox;
    SDL_FRect sprite_frame;
    SDL_Texture *sprite_texture;

public:
    void sprite_init(SDL_Renderer *renderer, const char *fpath)
    {
        sprite_texture = IMG_LoadTexture(renderer, fpath);
    }

    void sprite_render(SDL_Renderer *renderer)
    {
        SDL_RenderTexture(renderer, sprite_texture, &sprite_frame, &sprite_hitbox);
        SDL_SetTextureScaleMode(sprite_texture, SDL_SCALEMODE_NEAREST);
    }

    void sprite_quit()
    {
        SDL_DestroyTexture(sprite_texture);
    }
};