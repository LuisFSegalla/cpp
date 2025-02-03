# C++ Magic the Gathering Collection tracker

This is a project that I use to study some concepts of C++.

The objective is to use [Scryfall's API](https://scryfall.com/docs/api) to get some information about my collection of Magic The Gathering cards.

There are no big depencies on the project and a devcontainer can be used to run it in a compatible environment. 

# How to build

After opening the application on the container you can build it by following:

> mkdir build
>
> cd build
>
> cmake ..
>
>> Run 
>>
>> cmake -DCMAKE_BUILD_TYPE=Debug ..
>>
>> if you want to have access to the debugger for the application.
>
>
> make


This should build the project for you with an exrcutable main. 

The project is not yet ready so the main is not fully functional.