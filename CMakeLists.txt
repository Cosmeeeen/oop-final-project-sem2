cmake_minimum_required(VERSION 3.19)
project(proiectFinal)

set(CMAKE_CXX_STANDARD 14)

add_executable(proiectFinal main.cpp Tests/Tests.cpp Tests/Tests.h Entities/Property.cpp Entities/Property.h Tests/EntitiesTester.cpp Tests/EntitiesTester.h Entities/House.cpp Entities/House.h Entities/Apartment.cpp Entities/Apartment.h Validation/ValidationException.h Validation/PropertyValidator.cpp Validation/PropertyValidator.h Validation/HouseValidator.cpp Validation/HouseValidator.h Validation/ApartmentValidator.cpp Validation/ApartmentValidator.h Validation/RepoException.h Validation/ReadFromFileException.h Tests/ValidatorsTest.cpp Tests/ValidatorsTest.h Repository/Repo.cpp Repository/Repo.h Tests/RepoTester.cpp Tests/RepoTester.h)