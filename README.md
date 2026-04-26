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

INPUT
```
Choose option: 1
101     // Id
Slides  // Descripion
5       // Priority
```
OUPUT
```
Task added successfully:
ID: 101, Description:  Slides, Priority: 5
```

INPUT
```
Choose option: 2
```
OUTPUT
```
Processed task:
ID: 101, Description: Fix_memory_leak, Priority: 5
```

INPUT
```
Choose option: 6
3  // k
```
OUTPUT
```
Requested to process 3 task(s).
Processed tasks:
ID: 104, Description: Banners, Priority: 4
Processed tasks:
ID: 103, Description: Badges, Priority: 2
Processed tasks:
ID: 102, Description: Sponsors, Priority: 5
```

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

INPUT
```
recordAncientEvent  // Method
0                   // Unique integer
First_contact       // Description
2200                // Year
100                 // Impact
```
OUTPUT
```
[ 0 | First_contact | 2200 | 100 ]  // Front
```

INPUT
```
recordRecentEvent
1
Quantum_energy
2300
90
```
OUTPUT
```
[ 1 | Quantum_energy | 2300 | 90 ]  // Back
```

INPUT
```
relocateEvent
3
0
false
```
OUTPUT
```
[ 0 | First_contact | 2200 | 100 ]
[ 3 | Temporal_crisis | 2400 | 95 ]  // After node 0
[ 1 | Quantum_energy | 2300 | 90 ]
```
INPUT
```
relocateEvent
3
0
true
```
OUTPUT
```
[ 3 | Temporal_crisis | 2400 | 95 ]  // Before node 0
[ 0 | First_contact | 2200 | 100 ]
[ 1 | Quantum_energy | 2300 | 90 ]
```

## How to Compile and Run

- A C++ compiler is necessary
- CMake of version 3.14 or higher

### Instructions

While inside the main project folder (where this readme is located), run either:

`cmake --build build --target run_ex1`

In order to run and compile the Interactive Task Flow Manager from exercise 1

Or:

`cmake --build build --target run_ex2`

In order to compile and run a test script of the Timeline Manager library from exercise 2

## Notes

- Each exrcise uses one specific data structure and a custom data structure implementation
- All cases were unit tested for both exercises for complete functionality
- The code uses clases and separate header files for an organized structure
- The exercises demonstrate the understanding and  use of data structures





