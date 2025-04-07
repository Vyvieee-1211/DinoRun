#include"sound.h"
Sound::Sound()
{
    std::cout << "Loading Music" << '\n'; 
	jumpingSound = Mix_LoadWAV(JUMP_SOUND);
	endGameSound = Mix_LoadWAV(END_GAME_SOUND);  
	gMusic = Mix_LoadMUS(BACKGROUND_MUSIC);
}
Sound::~Sound()
{

}
void Sound::playMusic(bool* hurt)
{
    if (*hurt) return;
    if (gMusic == nullptr) return;

    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(gMusic, -1);
    }
    else if (Mix_PausedMusic() == 1) {
        Mix_ResumeMusic();
    }
}
void Sound::playJumpSound() {
    if (jumpingSound != nullptr) {
        Mix_PlayChannel(-1, jumpingSound, 0);
    }
}
void Sound::playEndGameSound()
{
    if (endGameSound != nullptr) {
        Mix_PlayChannel(-1, endGameSound, 0);
    }
}