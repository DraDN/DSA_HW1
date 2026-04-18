Work in progress!
We'll check back to yall in a hot minute :kissing_heart:

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
 - Processing of the next task, by removing the current one, and displaying the next one
 - Undo of the last processed task, by bringing back the previous task
 - Display of all the waiting tasks, in order
 - Display of the processed taks history, from the most recent one
 - Process of the next k (multiple) tasks, removes the k tasks, and if there are less tasks than k, all of them will be processed and displayed
 - Searching a task by Id, for information on its state (waiting/processed) and if it exists
 - Display of statistics, shows the total of waiting/processed/successful undo operations

### Implementation Details

- Tasks are structured with an unique Id, a specific description, and a priority level, ina range ***from 1*** (low priority) ***to 5**(high priority)
- Menu uses a user-friendly interface, by choosing a integer (1-8) for the preferred action

### Example


## Exercise 2 - Timeline Reconstruction System

### Summary

This exercise implements an event time line reconstruction system, created to manage the chronology of historical events. The system allows for recording, positioning and reorganization of events within the timeline, giving full ocntrol over the chronological order.

### Data Structure Used

***Linked List*** - Chosen because atimeline focuses on order and position, events being constantly inserted between existing ones, reloated, or removed, operations that can be handled by a linked list, leaving the rest of the timeline undisturbed.

### Features

- Record of an ancient event, by adding an event at the start of the timeline
- Record of a recent event, by adding at the end of the timeline
- Insertion of an event between two existing ones
- Removal of an event based on its Id
- Modification of an event, by moving it before or after another one
- Display of all of the events recorded in chronological order
- Display of the impact values of all the events
- Reorganization of events based on impact level, bringing high-impact events at the beginning while keeping a relative order of them

### Implementation Details

### Example



## How to Compile and Run

## Notes




<!--features of project
instructions on how to use them

if there are requirements that are not fuctional, suggest possible solutions

-->



