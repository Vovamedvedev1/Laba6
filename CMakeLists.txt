cmake_minimum_required(VERSION 3.10)
project("Laba6")

include_directories(include)

set(DEFAULT_FILENAME "1.txt" "2.txt")



add_executable (Laba6
    "Laba6.cpp"
    "include/funcs.h"
    "src/funcs.cpp"
    "include/Article.h"
    "src/Article.cpp"
    "include/Prediction.h"
    "src/Prediction.cpp"
    "include/PrintedEdition.h"
    "src/PrintedEdition.cpp"
    "include/Horoscope.h"
    "src/Horoscope.cpp"
    "include/Newspapper.h"
    "src/Newspapper.cpp"
    "include/ScientificJournal.h"
    "src/ScientificJournal.cpp"
    "include/PublisherHouse.h"
    "src/PublisherHouse.cpp"
 )