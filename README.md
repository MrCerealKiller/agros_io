# AgROS IO

## Description
Part of the AgROS Suite, this package handles common IO interfaces for
agricultural robots, such as light bars and tool relays.

## Dependencies
* ROS (see package.xml)
* FastLED (included as a submodule)

## Usage
### Light Bar
1. Configure your parameters by editing the header file definitions
2. Upload the code using arduino cmake (see tutorials)
3. Start a rosserial python node manually or using the given launch file
4. Your light bar should be connected to your ROS network
