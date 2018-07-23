project (MorseKey)

add_executable (MorseKey MorseKey.cpp Morse.cpp MorsePi.cpp)
target_link_libraries(MorseKey wiringPi)
