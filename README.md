# Vending Machine with Arduino and GSM Communication

This project demonstrates the design and implementation of a vending machine system using **Arduino Uno** and **SIM900A GSM module**. The vending machine allows users to order products through SMS, verify payments, and dispense items accordingly. The system incorporates several key components like an LCD display, servo motor, and buck converter for smooth operation.

## Features

- **SMS-based Ordering**: Users can send an SMS to the vending machine to purchase items.
- **Payment Verification**: The system verifies payment amounts via mobile payment (e.g., bKash).
- **Automated Dispensing**: Uses a servo motor to dispense items once the payment is confirmed.
- **LCD Display**: Displays user prompts, product details, and transaction status.
- **Scam Detection**: Detects fraudulent SMS and displays a "Scamming" warning.

## Components Used

- **Arduino Uno**: The central controller for the vending machine system.
- **SIM900A GSM Module**: Used for SMS communication between the vending machine and the user.
- **LCD Display with I2C Module**: Displays product prices, transaction status, and messages.
- **Servo Motor**: Controls the dispensing of the selected item.
- **Buck Converter**: Regulates the voltage to power the Arduino and other components.
- **Buzzer**: Provides audio feedback.
- **3.7V DC Batteries**: Powers the vending machine components.
- **Breadboard and Jumping Wires**: For connecting all components.

## Project Objectives

- To learn how to work with **Arduino Uno** and interface it with peripherals like the **SIM900A GSM module** and **servo motor**.
- To build a functional **vending machine** that operates through GSM communication and mobile payments.
- To gain practical knowledge of **LCD integration** using the I2C module for efficient display management.
  
## System Workflow

1. **SMS Received**: The GSM module receives an SMS from the user to initiate a purchase.
2. **Payment Verification**: The vending machine checks if the payment matches the item price.
3. **Dispensing Product**: If the payment is valid, the servo motor rotates to release the item.
4. **Display Update**: The LCD provides real-time information on transaction status.
5. **Scam Prevention**: If an unauthorized SMS is detected, the system warns the user.

## Hardware Design

- **Arduino Uno**: Controls the entire system, monitors SMS, processes payments, and controls the servo motor.
- **SIM900A GSM Module**: Handles the SMS communication.
- **LCD Display with I2C**: Displays messages and prices.
- **Servo Motor**: Dispenses products.
- **Buck Converter**: Steps down the voltage to power components.
  
## Software Design

The following steps outline the software workflow:

1. Initialize the GSM module and establish communication.
2. Setup the LCD display and servo motor.
3. Monitor for incoming SMS orders.
4. Verify if the payment matches the product price.
5. If verified, activate the servo motor to dispense the item.
6. Update the LCD display with the transaction status.

### YouTube link

Check out the demonstration video here: https://youtu.be/giCCR14wO5o?si=-uG5Mvoqe0_tLtoN

### Pseudocode

```plaintext
Initialize the GSM module to enable communication.
Initialize the LCD display.
Set up the servo motor for dispensing.
Monitor for incoming SMS.
If payment equals product price, dispense product.
Display the transaction status on the LCD.



