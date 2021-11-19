## Assignment Description
Create a program offering basic to-do list functionality, processing user input and offering an interactive graphical interface.

### Project Delivery

The existing CMake skeleton project and file directory can be used. The program must successfully compile under Ubuntu 20.04 using Qt 5.12 and a standard C++ compiler (gcc, clang). C++17 should be targeted.

### Required Functionality

The program must offer an interface and basic functionality for a user to manage their to-do's (tasks). 

- A task is represented by the following properties:
    - Description
    - Status (*complete* or *incomplete*). Default *incomplete*
    - Priority (*none*, *high*, *medium*, *low*). Default *none*
    - Background color (presets only). Default *white*
- In the main screen, the user can write a description and click a button to add a new task
- In the main screen, the tasks should be displayed in a list, grid or similar
    - All task properties should be inferred from the main screen. That is, the Description, Status, Priority and Background color should be visible for each task from the main screen
- In the main screen, at least the following functionality must be offered to the user
    - Change the task Status by ticking a box (or similar). This also changes Background color to a reserved color (e.g. *white* and *gray*)
    - Click an Edit button to open a **popup or separate screen**, where the Priority and Background color can be changed
    - Permanently erase a task. Note this is **different** from marking Status as *complete*.
- In the main screen, the user can save the current tasks to a file
    - Feel free to choose any suitable format
    - The filename should be chosen by the developer, not the user
    - The function `saveToFileSlow` defined in `include/qt-assignment/FileHelper.hpp` must be used to save the file. The application should be responsive while saving.

### Extra Functionality

This functionality is not required, but provides quality of life changes to the program. They are a plus for the interview but only consider them if time allows.

- The user would like to filter the tasks visible in the main screen by their Priority
- Now that there is functionality to save tasks to a file, the application should read tasks from that file when initializing.

### Implementation Requirements

- Use the Qt QML framework for the GUI
- Provide a clear separation between the frontend and backend of the application
- Modern C++ should be used; Smart pointers (and smart Qt pointers) should be used
- No external libraries should be used, unless their use is justified. Any Qt component can be used

### General Requirements
- Provide sufficient documentation of the classes and methods you define
- Use atomic git commits

## Example GUI

This basic example serves as an inspiration only, feel free to diverge from it as long as the functionality is achieved.

The following image illustrates the main application screen.

![](./example.png)

The following image illustrates the popup to edit task properties (this can also be a separate screen).

![](./example_popup.png)