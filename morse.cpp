#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <stdio.h>

sf::SoundBuffer Buffer;
sf::Sound Sound;
void play_tone(float, float);
void morse_loop(std::string);
float unit;
int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Missing argument!\nUsage: morse <unit length> <\"input\"> \n";
    return 1;
  }

  if (!Buffer.loadFromFile("beep.wav")) {
    return -1;
  }
  Sound.setBuffer(Buffer);
  unit = (atof(argv[1]));
  morse_loop(std::string(argv[2]));
  Sound.stop();
  return 0;
}

void play_tone(float sound, float delay) {
  sf::Clock clock;
  clock.restart();
  Sound.play();
  while (clock.getElapsedTime().asSeconds() < sound) {
  }
  clock.restart();
  Sound.pause();
  while (clock.getElapsedTime().asSeconds() < delay) {
  }
}
void morse_loop(std::string string) {
  for (int i = 0; i < string.length(); i++) {
    switch (string.at(i)) {
    case '-':
      play_tone(unit * 3, unit * 1);
      break;
    case '.':
      play_tone(unit * 1, unit * 1);
      break;
    case ' ':
      play_tone(unit * 0, unit * 1);
      break;
    case '/':
      play_tone(unit *0, unit *7);
      break;
    }
  }
}
