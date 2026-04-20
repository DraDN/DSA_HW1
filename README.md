<!---Work in progress!
We'll check back to yall in a hot minute :kissing_heart: --->

# Data Strucutres and Algorithms - HW1

This repository contains solutions for the Data Structures and Algorithms Homework 1.
The homework focuses on the implementation and application of stacks, queues and linked lists.

### Team Members - GROUP 1211EB

- Dragan Dragos-Nicolae
- Reculciuc Livia-Maria

## General information about the exercises

- Each exercise uses a different data structure type (stack, queue or linked list)
- All impelmentations have classes and separate header files with structs for better organized and readable code
- The exercises use the header files provided to us at the laboratory.

## Exercise 1 - Interactive Task Flow Manager

### Summary

This exercise implements a task manager with a fully interactive menu. The manager allows the user to add, process, display and search by id, making a foundationa for real-world task scheduling and management.

### Data Structure Used

***Queue***- Chosen because the first task aded is the first processed, following a First-In-First-Out pattern. Tasks arrive at the tail and are heandled from the head, ensuring a predictable way of solving tasks.

### Features

 - Adds tasks with different priority levels (1-5)
 - Processing of the next task, by displaying the current one, and taking the next one
 - Undo of the last processed task
 - Display of all the waiting tasks, in order
 - Display of the processed taks history, from the most recent one
 - Process of the next k (multiple) tasks, removes the k tasks, and if there are less than k tasks, all of them will be processed and displayed
 - Searching a task by Id, and displaying its state (waiting/processed) or if it exists
 - Display statistics, shows the total of waiting tasks/processed tasks/successful undo operations

### Implementation Details

- Tasks are structured with an unique Id, a specific description, and a priority level, ina range ***from 1*** (low priority) ***to 5***(high priority)
- Menu uses a user-friendly interface, by choosing a integer (1-8) for the preferred action

### Example


## Exercise 2 - Timeline Reconstruction System

### Summary

This exercise implements an event time line reconstruction system, created to manage the chronology of historical events. The system allows for recording, positioning and reorganization of events within the timeline, giving full control over the chronological order.

### Data Structure Used

***Linked List*** - Chosen because a timeline focuses on relative structure, events being constantly inserted between existing ones, reloated, or removed, operations that can be handled by a linked list, leaving the rest of the timeline undisturbed.

### Features

- Record of an ancient event, by adding an event at the start of the timeline
- Record of a recent event, by adding at the end of the timeline
- Insertion of an event between two existing ones
- Removal of an event based on its Id
- Relocation of an event, by moving it before or after another one
- Display of all of the events recorded in order
- Display of the total impact values of all the events
- Reorganization of events based on impact level, bringing events with an impact higher than a threshold at the beginning, while keeping their relative order

### Implementation Details

- Evets are structured with an unique ID, a name, the year of the event, impact score given by an integer indicating the significance and prev/next pointers
- Each node in the timeline maintains two directional links, one to its predecessor and one to its successor, enabling efficient traversal and pointer rewiring during modifications

### Example



## How to Compile and Run

- A C++ compiler is necessary

### Instructions

Navigate to the build folder and run the program:
`cd build\EX`
`EX.exe`

Or run it directly using the full path:
`DSA_HW1\build\EX\EX.exe`

Repeat for both exercises directories and input the presented operations.

## Notes

- Each exrcise uses one specific data structure and a custom data structure implementation
- All cases were tested for both exercises for complete functionality
- The code uses clases and separate header files for an organized structure
- The exercises demonstrate the understanding and  use of data structures





